#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=200000+10;
int fa[MAXN],depth[MAXN],to[MAXN][19];//18
int team[MAXN],head,tail;
int tot,g[MAXN],nnext[MAXN],num[MAXN];
int mn[MAXN];
int n,m;
int root[MAXN],rtc;
struct A{int x,y,z;}init[MAXN];
struct B{int l,r,sum;}seg[MAXN*20];
void add(int x,int y)
{
	tot++;
	nnext[tot]=g[x];
	g[x]=tot;
	num[tot]=y;
}
void get_lca(int rt)
{
	team[++tail]=rt;
	depth[rt]=1;
	while(head!=tail)
	{
		int x=team[++head];
		to[x][0]=fa[x];
		for(int i=1;i<=18;i++)
			to[x][i]=to[to[x][i-1]][i-1];
		for(int i=g[x];i;i=nnext[i])
		{
			depth[num[i]]=depth[x]+1;
			fa[num[i]]=x;
			team[++tail]=num[i];
		}
	}
}
int lca(int x,int y)
{
	if(depth[x]<depth[y]) swap(x,y);
	for(int i=18;i>=0;i--)
		if(depth[to[x][i]]>=depth[y])
			x=to[x][i];
	if(x==y) return x;
	
	for(int i=18;i>=0;i--)
		if(to[x][i]!=to[y][i])
			x=to[x][i],y=to[y][i];
	return to[x][0];
}
void build(int frt,int &rt,int l,int r,int x)
{
	rt=++rtc;
	seg[rt].sum++;
	if(l==r) return ;
	int mid=(l+r)/2;
	if(x<=mid) seg[rt].r=seg[frt].r,build(seg[frt].l,seg[rt].l,l,mid,x);
	else seg[rt].l=seg[frt].l,build(seg[frt].r,seg[rt].r,mid+1,r,x);
	seg[rt].sum=seg[seg[rt].l].sum+seg[seg[rt].r].sum;
}
int q(int rt,int l,int r,int x)
{
	if(rt==0) return 0;
	if(r<=x) return seg[rt].sum;
	int mid=(l+r)/2;
	if(x<=mid) return q(seg[rt].l,l,mid,x);
	else return q(seg[rt].l,l,mid,x)+q(seg[rt].r,mid+1,r,x);
}
int read()
{
	char c=getchar();int x=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'&&!feof(stdin)) x=x*10+c-'0',c=getchar();
	return x;
}
#include<ctime>
int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
	int rt,x,y,z,opt,cnt=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		x=read();
		if(x==0) rt=i;
		else add(x,i);
	}
	get_lca(rt);
	m=read();
	for(int i=1;i<=n;i++) mn[i]=m+1;
	for(int i=1;i<=m;i++)
	{
		opt=read();
		if(opt==1)
			init[++cnt]=(A){read(),read(),i-read()-1};
		else
		{
			x=read();
			mn[x]=min(mn[x],i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		x=team[i];
		y=fa[x];
		build(root[y],root[x],1,n,mn[x]);
	}
	for(int i=1;i<=cnt;i++)
	{
		x=init[i].x;
		y=init[i].y;
		z=init[i].z;
		int f=lca(x,y);
		printf("%d %d\n",
			depth[x]+depth[y]-depth[f]*2+1,
			q(root[x],1,n,z)+
			q(root[y],1,n,z)-
			q(root[fa[f]],1,n,z)*2-
			(mn[f]<=z?1:0)
			);	
	}
	cerr<<clock();
}
