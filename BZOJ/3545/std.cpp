#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
#define N 520050
#define e exp(1.0)
#define pi acos(-1.0)
using namespace std;
int sc()
{
    int i=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')i=i*10+c-'0',c=getchar();
    return i*f;
}
struct W{int x,y,z;}a[N];
struct Q{int v,x,k,p;}b[N];
int v[N],ans[N],root[N],FA[N];
int fa[N*10],ch[N*10][2],w[N*10],s[N*10];
int n,m,q,cnt;
bool cmp1(W a,W b){return a.z<b.z;}
bool cmp2(Q a,Q b){return a.x<b.x;}
int find(int x)
{
    return FA[x]==x?x:FA[x]=find(FA[x]);
}
int son(int x){return ch[fa[x]][1]==x;}
void push_up(int x){s[x]=s[ch[x][0]]+s[ch[x][1]]+1;}
void rotate(int x,int &f)
{
    int y=fa[x],z=fa[y],b=son(x),c=son(y);
    ch[z][c]=x; fa[x]=z;
    ch[y][b]=ch[x][!b]; if(ch[x][!b])fa[ch[x][!b]]=y;
    ch[x][!b]=y; fa[y]=x;
    push_up(y),push_up(x);
    if(y==f) f=x;
}
void splay(int x,int &f)
{
    while(x!=f)
    {
        int y=fa[x],z=fa[y];
        if(y==f) rotate(x,f);
        else
        {
            if(ch[z][0]==y^ch[y][0]==x) rotate(x,f);
            else                        rotate(y,f);
            rotate(x,f);
        }
    }
}
void add(int &x,int k,int f,int c)
{
    if(!x)
    {
        x=++cnt;
        s[x]=1;
        w[x]=k;
        fa[x]=f;
        splay(x,root[c]);
        return;
    }
    s[x]++;
    if(v[k]<v[w[x]])add(ch[x][0],k,x,c);
    else            add(ch[x][1],k,x,c);
}

void insert(int x,int f)
{
    if(!x)return;
    insert(ch[x][0],f);
    insert(ch[x][1],f);
    add(root[f],w[x],0,f);
    /*  TLEµÄÐ´·¨£¡£¡£¡ 
    add(root[f],w[x],0,f);
    insert(ch[x][0],f);
    insert(ch[x][1],f);
    */
}
void merge(int x,int y)
{
    if(s[root[x]]<s[root[y]])swap(x,y);
    FA[y]=x;
    insert(root[y],x);
}
int search(int x,int k)
{
    if(s[x]<k)return -1;
    if(k==s[ch[x][1]]+1)return v[w[x]];
    else if(k<=s[ch[x][1]])
        return search(ch[x][1],k);
    else 
        return search(ch[x][0],k-s[ch[x][1]]-1);
}
#include<ctime>
int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
    n=sc(),m=sc(),q=sc();cnt=n;
    for(int i=1;i<=n;i++)v[i]=sc(),FA[i]=root[i]=w[i]=i,s[i]=1;
    for(int i=1;i<=m;i++)
        a[i].x=sc(),a[i].y=sc(),a[i].z=sc();
    for(int i=1;i<=q;i++)
        b[i].v=sc(),b[i].x=sc(),b[i].k=sc(),b[i].p=i;
    sort(a+1,a+m+1,cmp1);
    sort(b+1,b+q+1,cmp2);
    int L=1;
    cerr<<clock()<<endl;
    for(int i=1;i<=q;i++)
    {
        int mn=b[i].x;
        while(a[L].z<=mn&&L<=m)
        {
            int fx=find(a[L].x),fy=find(a[L].y);
            if(fx!=fy) merge(fx,fy);
            L++;
        }

        int fx=find(b[i].v);
        ans[b[i].p]=search(root[fx],b[i].k);
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    cerr<<clock()<<endl;
    return 0;
}
