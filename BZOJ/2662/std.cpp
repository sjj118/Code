#include<iostream>
#include<cstdio>
#include<cstring>
#include<ext/pb_ds/priority_queue.hpp>
#define pa pair<int,pair<int,int> >
#define mp(a,b,c) make_pair(a,make_pair(b,c))
#define fr first
#define sc second.first
#define tr second.second 
#define inf 1000000000
using namespace std;
using namespace __gnu_pbds;
typedef __gnu_pbds::priority_queue<pa,greater<pa>,pairing_heap_tag > heap;
heap::point_iterator id[55][55];
int n,m,k,cnt,ans=inf;
int last[55],dis[55][55];
struct edge{int to,next,v;}e[2005];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;e[cnt].v=w;
}
void dijkstra()
{
	heap q;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dis[i][j]=inf;
	dis[1][0]=0;id[1][0]=q.push(mp(0,1,0));
	while(!q.empty())
	{
		int a=q.top().sc,b=q.top().tr;q.pop();
		for(int i=last[a];i;i=e[i].next)
		{
			if(dis[a][b]+e[i].v<dis[e[i].to][b])
			{
				dis[e[i].to][b]=dis[a][b]+e[i].v;
				if(id[e[i].to][b]==0)id[e[i].to][b]=q.push(mp(dis[e[i].to][b],e[i].to,b));
				else q.modify(id[e[i].to][b],mp(dis[e[i].to][b],e[i].to,b));
			}
			if(b<k&&dis[a][b]+e[i].v/2<dis[e[i].to][b+1])
			{
				dis[e[i].to][b+1]=dis[a][b]+e[i].v/2;
				if(id[e[i].to][b+1]==0)id[e[i].to][b+1]=q.push(mp(dis[e[i].to][b+1],e[i].to,b+1));
				else q.modify(id[e[i].to][b+1],mp(dis[e[i].to][b+1],e[i].to,b+1));
			}
		}
	}
}
int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		insert(u,v,w);
	}
	dijkstra();
	for(int i=0;i<=k;i++)
		ans=min(ans,dis[n][i]);
	printf("%d",ans);
	return 0;
}
