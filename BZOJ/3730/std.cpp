#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<climits>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define N 500100
#define M 1000200
#define lowbit(x) x&(-x)
using namespace std;
inline int read()
{
	int x=0,f=1;char ch;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,v[N],ans;
int head[N],pos;
struct edge{int to,next;}e[M];
inline void add(int a,int b)
{pos++;e[pos].to=b,e[pos].next=head[a],head[a]=pos;}

int dist[N],ff[N][20],dep[N];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	ff[u][0]=fa;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dist[v]=dist[u]+1;
		dfs(v,u);
	}
}
void make()
{
	for(int k=1,j=2;j<=n;j<<=1,k++)
		for(int i=1;i<=n;i++)
			ff[i][k]=ff[ff[i][k-1]][k-1];
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int tmp=dep[x]-dep[y];
	for(int k=0,j=1;j<=tmp;j<<=1,k++)
		if(tmp&j)x=ff[x][k];
	while(x!=y)
	{
		int j=0;
		while(ff[x][j]!=ff[y][j])j++;
		if(j)j--;
		x=ff[x][j],y=ff[y][j];
	}return x;
}
inline int dis(int x,int y)
{
	int lc=lca(x,y);
	return dist[x]+dist[y]-2*dist[lc];
}

int root[N][2],sz;
int s[N<<4],ls[N<<4],rs[N<<4];
inline void insert(int &u,int l,int r,int x,int val)
{
	if(!u)u=++sz;s[u]+=val;
	if(l==r)return;int mid=(l+r)>>1;
	if(x<=mid)insert(ls[u],l,mid,x,val);
	else insert(rs[u],mid+1,r,x,val);
}
inline int query(int u,int l,int r,int x,int y)
{
	if(!u)return 0;
	if(x<=l&&y>=r)return s[u];
	int mid=(l+r)>>1;
	if(y<=mid)return query(ls[u],l,mid,x,y);
	else if(x>mid)return query(rs[u],mid+1,r,x,y);
	else return query(ls[u],l,mid,x,mid)+query(rs[u],mid+1,r,mid+1,y);
}
int sum,f[N],size[N],rt;bool vis[N];
void find_root(int u,int fa)
{
	size[u]=1,f[u]=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int vv=e[i].to;
		if(vv==fa||vis[vv])continue;
		find_root(vv,u);
		size[u]+=size[vv];
		f[u]=max(f[u],size[vv]);
	}f[u]=max(f[u],sum-size[u]);
	if(f[u]<f[rt])rt=u;
}

int p[N],d[N];
void get_dep(int tr,int u,int fa)
{
	insert(root[tr][0],0,n,d[u],v[u]);
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa||vis[v])continue;
		d[v]=d[u]+1;get_dep(tr,v,u);
	}
}
void find_dep(int tr,int u,int fa)
{
	insert(root[tr][1],0,n,d[u],v[u]);
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa||vis[v])continue;
		d[v]=d[u]+1;find_dep(tr,v,u);
	}
}
void work(int u)
{
	vis[u]=1;d[u]=0;get_dep(u,u,0);
	for(int i=head[u];i;i=e[i].next)
	{
		int vv=e[i].to;
		if(vis[vv])continue;
		sum=size[vv],rt=0;
		find_root(vv,0);p[rt]=u;
		d[vv]=1;find_dep(rt,vv,u);
		work(rt);
	}
}

void updata(int u,int val)
{
	int va=query(root[u][0],0,n,0,0);
	int ct=val-va;
	insert(root[u][0],0,n,0,ct);
	for(int i=u;p[i];i=p[i])
	{
		int dt=dis(u,p[i]);
		insert(root[p[i]][0],0,n,dt,ct);
		insert(root[i][1],0,n,dt,ct);
	}
}
int ask(int u,int k)
{
	int j=k;
	int ret=query(root[u][0],0,n,0,k);
	for(int i=u;p[i];i=p[i])
	{
		int dt=dis(p[i],u);
		ret+=query(root[p[i]][0],0,n,0,k-dt);
		ret-=query(root[i][1],0,n,0,k-dt);
	}return ret;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("my.txt","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		v[i]=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b);add(b,a);
	}sum=f[0]=n;rt=0;
	dfs(1,0);make();
	find_root(1,0);
	work(rt);
	for(int i=1;i<=m;i++)
	{
		int f=read(),x=read(),y=read();
		if(f==0)printf("%d\n",ans=ask(x,y));
		else  updata(x,y);
	}
}
