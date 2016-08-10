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
#define N 1000005
#define inf 1000000000
#define ll long long 
using namespace std;
ll ans;
int n,m,cnt,tot;
int last[100005];
int C[100005],L[100005],root[100005];
ll sum[100005],size[100005];
struct edge{
	int to,next;
}e[100005];
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}
struct Ltree{
	int v[100005];
	int l[100005],r[100005];
	int merge(int x,int y){
		if(x==0||y==0)return x+y;
		if(v[x]<v[y])swap(x,y);
		r[x]=merge(r[x],y);
		swap(l[x],r[x]);
		return x;
	}
	void pop(int &x){
		x=merge(l[x],r[x]);
	}
	int top(int x){
		return v[x];
	}
}heap;
void dfs(int x)
{
	root[x]=++tot;heap.v[tot]=C[x];
	size[x]=1;
	sum[x]=C[x];
	for(int i=last[x];i;i=e[i].next)
	{
		dfs(e[i].to);
		sum[x]+=sum[e[i].to];
		size[x]+=size[e[i].to];
		root[x]=heap.merge(root[x],root[e[i].to]);
	}
	while(sum[x]>m)
	{
		sum[x]-=heap.top(root[x]);heap.pop(root[x]);
		size[x]--;
	}
	ans=max(ans,size[x]*L[x]);
}
int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		insert(x,i);
		scanf("%d%d",&C[i],&L[i]);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
