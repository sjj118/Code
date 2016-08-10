#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#define eps 1e-8
#define inf 1000000000
#define pa pair<int,int>
#define ll long long 
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
ll A,B;
int ls[4000005],rs[4000005],sum[4000005];
int bin[20];
int n,m,cnt,ind,size;
int last[100005],deep[100005],root[200005],in[100005],out[100005];
int fa[100005][17];
vector<int> a[100005];
struct query{
	int x,y;
}q[100005];
bool operator<(query a,query b)
{
	if(a.x==b.x)return a.y<b.y;
	else return a.x<b.x;
}
struct edge{
	int to,next;
}e[200005];
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
int insert(int x,int l,int r,int pos,int val)
{
	int t=++size;
	ls[t]=ls[x];rs[t]=rs[x];
	if(l==r){sum[t]=sum[x]+val;return t;}
	int mid=(l+r)>>1;
	if(pos<=mid)ls[t]=insert(ls[t],l,mid,pos,val);
	else rs[t]=insert(rs[t],mid+1,r,pos,val);
	sum[t]=sum[ls[t]]+sum[rs[t]];
	return t;
}
int query(int p1,int p2,int p3,int p4,int l,int r,int st,int ed)
{
	int mid=(l+r)>>1;
	if(l==st&&r==ed)
	{
		return sum[p1]+sum[p2]-sum[p3]-sum[p4];
	}
	if(ed<=mid)return query(ls[p1],ls[p2],ls[p3],ls[p4],l,mid,st,ed);
	else if(st>mid)return query(rs[p1],rs[p2],rs[p3],rs[p4],mid+1,r,st,ed);
	else 
		return query(ls[p1],ls[p2],ls[p3],ls[p4],l,mid,st,mid)+query(rs[p1],rs[p2],rs[p3],rs[p4],mid+1,r,mid+1,ed);
}
void dfs(int x)
{
	in[x]=++ind;
	for(int i=1;bin[i]<=deep[x];i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa[x][0])
		{
			fa[e[i].to][0]=x;
			deep[e[i].to]=deep[x]+1;
			dfs(e[i].to);
		}
	out[x]=++ind;
}
void dfs2(int x)
{
	root[x]=root[fa[x][0]];
	for(int i=0;i<a[x].size();i++)
	{
		root[x]=insert(root[x],1,ind,in[a[x][i]],1);
		root[x]=insert(root[x],1,ind,out[a[x][i]],-1);
	}
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa[x][0])
			dfs2(e[i].to);
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;i<=16;i++)
		if(t&bin[i])
			x=fa[x][i];
	for(int i=16;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	if(x==y)return x;
	return fa[x][0];
}
void solve()
{
	for(int i=1;i<=m;i++)
	{
		int x=q[i].x,y=q[i].y,f=lca(x,y);
		A+=query(root[x],root[y],root[f],root[fa[f][0]],1,ind,in[f],in[x]);
		A+=query(root[x],root[y],root[f],root[fa[f][0]],1,ind,in[f],in[y]);
		A-=query(root[x],root[y],root[f],root[fa[f][0]],1,ind,in[f],in[f]);
		A--;
	}
}
int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
	bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
	n=read();m=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		insert(u,v);
	}
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		a[x].push_back(y);
		q[i].x=x,q[i].y=y;
	}
	sort(q+1,q+m+1);
	dfs(1);
	dfs2(1);
	solve();
	int j;
	for(int i=1;i<=m;i=j)
		for(j=i;q[j].x==q[i].x&&q[j].y==q[i].y;j++)
			A-=(ll)(j-i)*(j-i-1)/2;
	B=(ll)m*(m-1)/2;
	ll t=gcd(A,B);
	A/=t;B/=t;
	printf("%lld/%lld",A,B);
	return 0;
}
