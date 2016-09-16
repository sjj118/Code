#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
inline int getc(){
    static const int L=1<<15;
    static char buf[L],*S=buf,*T=buf;
    if(S==T){
        T=(S=buf)+fread(buf,1,L,stdin);
        if(S==T)
            return EOF;
    }
    return*S++;
}
inline int getint(){
    int c;
    while(!isdigit(c=getc()));
    int x=c-'0';
    while(isdigit(c=getc()))
        x=(x<<1)+(x<<3)+c-'0';
    return x;
}
 
#define N 100010
#define M 200010
int head[N],next[M<<1],end[M<<1];
inline void addedge(int a,int b){
    static int q=1;
    end[q]=b;
    next[q]=head[a];
    head[a]=q++;
}
inline void make(int a,int b){
    addedge(a,b);
    addedge(b,a);
}
 
int dfn[N],low[N],tclock,stack[N],top,cnt;
bool iscut[N];
vector<int>v[N];
inline void tarjan(int x){
    dfn[x]=low[x]=++tclock;
    stack[++top]=x;
    int y,son=0;
    for(int j=head[x];j;j=next[j]){
        if(!dfn[end[j]]){
            ++son;
            tarjan(end[j]);
            low[x]=min(low[x],low[end[j]]);
            if(low[end[j]]>=dfn[x]){
                ++cnt;
                iscut[x]=1;
                while(1){
                    y=stack[top--];
                    v[cnt].push_back(y);
                    if(y==end[j])
                        break;
                }
                v[cnt].push_back(x);
            }
        }
        else
            low[x]=min(low[x],dfn[end[j]]);
    }
    if(x==1&&son<=1)
        iscut[x]=0;
}
 
struct Tree{
    static const int V=N<<1;
    int head[V],next[V<<1],end[V<<1];
    inline void addedge(int a,int b){
        static int q=1;
        end[q]=b;
        next[q]=head[a];
        head[a]=q++;
    }
    inline void make(int a,int b){
        addedge(a,b);
        addedge(b,a);
    }
}g;
 
int ans[N];
 
int pa[N<<1][21],dep[N<<1];
inline void dfs(int x,int fa){
    for(int j=g.head[x];j;j=g.next[j]){
        if(g.end[j]!=fa){
            dep[g.end[j]]=dep[x]+1;
            pa[g.end[j]][0]=x;
            dfs(g.end[j],x);
        }
    }
}
inline int lca(int x,int y){
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=20;i>=0;--i)
        if(dep[pa[x][i]]>=dep[y])
            x=pa[x][i];
    if(x==y)
        return x;
    for(int i=20;i>=0;--i)
        if(pa[x][i]!=pa[y][i])
            x=pa[x][i],y=pa[y][i];
    return pa[x][0];
}
 
int sig[N<<1];
inline void upd_path(int x,int y){
    int _lca=lca(x,y);
    if(_lca==x){
        sig[y]++;
        sig[pa[x][0]]--;
    }
    else if(_lca==y){
        sig[x]++;
        sig[pa[y][0]]--;
    }
    else{
        sig[x]++,sig[y]++;
        sig[_lca]--;
        sig[pa[_lca][0]]--;
    }
}
 
inline void up_sign(int x,int fa){
    for(int j=g.head[x];j;j=g.next[j])
        if(g.end[j]!=fa){
            up_sign(g.end[j],x);
            sig[x]+=sig[g.end[j]];
        }
    if(iscut[x])
        ans[x]+=sig[x];
}
 
int main(){
    freopen("code.in","r",stdin);freopen("std.out","w",stdout);
 
    int n=getint(),m=getint(),q=getint(),i,j;
    int a,b;
    for(i=1;i<=m;++i){
        a=getint();
        b=getint();
        make(a,b);
    }
     
    tarjan(1);
     
    for(i=1;i<=cnt;++i)
        for(j=0;j<v[i].size();++j)
            g.make(n+i,v[i][j]);
     
    dep[1]=1;
    dfs(1,-1);
    for(j=1;j<=20;++j)
        for(i=1;i<=n;++i)
            pa[i][j]=pa[pa[i][j-1]][j-1];
 
    while(q--){
        a=getint();
        b=getint();
        if(!iscut[a])
            ++ans[a];
        if(!iscut[b])
            ++ans[b];
        upd_path(a,b);
    }
     
    up_sign(1,-1);
     
    for(i=1;i<=n;++i)
        printf("%d\n",ans[i]);
     
    return 0;
}
