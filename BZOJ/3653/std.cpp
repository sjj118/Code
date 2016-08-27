/**************************************************************
    Problem: 3653
    User: Tunix
    Language: C++
    Result: Accepted
    Time:8964 ms
    Memory:158752 kb
****************************************************************/
 
//Huce #1 D
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
#define F(i,j,n) for(int i=j;i<=n;++i)
#define D(i,j,n) for(int i=j;i>=n;--i)
#define pb push_back
using namespace std;
inline int getint(){
    int v=0,sign=1; char ch=getchar();
    while(ch<'0'||ch>'9'){ if (ch=='-') sign=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){ v=v*10+ch-'0'; ch=getchar();}
    return v*sign;
}
const int N=3e5+10,INF=~0u>>2;
typedef long long LL;
/******************tamplate*********************/
int head[N],to[N<<1],next[N<<1],cnt;
void add(int x,int y){
    to[++cnt]=y; next[cnt]=head[x]; head[x]=cnt;
    to[++cnt]=x; next[cnt]=head[y]; head[y]=cnt;
}
int n,m,a[N],dep[N],sz[N],st[N],ed[N],root[N],tot,ct;
struct Tree{
    int l,r; LL sum;
}t[N*30];
#define mid (l+r>>1)
void update(int &o,int l,int r,int pos,int w){
    t[++ct]=t[o], o=ct, t[o].sum+=w;
    if (l==r) return;
    if (pos<=mid) update(t[o].l,l,mid,pos,w);
    else update(t[o].r,mid+1,r,pos,w);
}
LL query(int i,int j,int l,int r,int ql,int qr){
    if (ql<=l && qr>=r){
        return t[j].sum-t[i].sum;
    }else{
        LL ans=0;
        if (ql<=mid) ans+=query(t[i].l,t[j].l,l,mid,ql,qr);
        if (qr> mid) ans+=query(t[i].r,t[j].r,mid+1,r,ql,qr);
        return ans;
    }
}
#undef mid
void dfs(int x){
    a[st[x]=++tot]=x;
    sz[x]=1;
    for(int i=head[x];i;i=next[i])
        if (st[to[i]]==0){
            dep[to[i]]=dep[x]+1;
            dfs(to[i]);
            sz[x]+=sz[to[i]];
        }
    ed[x]=tot;
}
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    freopen("std.out","w",stdout);
#endif
    n=getint(); m=getint();
    int x,y;
    F(i,2,n){
        x=getint(); y=getint();
        add(x,y);
    }
    dfs(1);
    F(i,1,n) update(root[i]=root[i-1],0,n,dep[a[i]],sz[a[i]]-1);
    F(i,1,m){
        x=getint(); y=getint();
        LL ans=(LL)(sz[x]-1)*min(dep[x],y);
        ans+=query(root[st[x]-1],root[ed[x]],0,n,
                   dep[x]+1,min(dep[x]+y,n));
        printf("%lld\n",ans);
    }
    return 0;
}
