#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1e9
#define maxn 63
#define maxp 4000
#define maxv 100000

using namespace std;

int n,m;
int start,end,car[maxn],fix[maxn][maxn];
struct Graph{
	int tot,head[maxp],to[maxv],next[maxv],dis[maxp],c[maxv],w[maxv],slk[maxp],vis[maxp];
	int s,t,pointsize,cost;
	void getp(int&x){if(!x)x=++pointsize;}
	void ins(int a,int b,int f,int p){to[++tot]=b;c[tot]=f;w[tot]=p;next[tot]=head[a];head[a]=tot;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	Graph(){tot=1;}
	bool modlabel(){
		int delta=inf;
		for(int i=1;i<=pointsize;++i)if(!vis[i])delta=min(delta,slk[i]),slk[i]=inf;
		if(delta==inf)return 0;
		for(int i=1;i<=pointsize;++i)if(vis[i])dis[i]+=delta;
		return 1;
	}
	int dfs(int k,int maxflow){
		if(k==t)return cost+=maxflow*dis[s],maxflow;
		int flow=0,tflow;vis[k]=1;
		for(int p=head[k];p&&maxflow;p=next[p])if(c[p]&&!vis[to[p]])
			if(dis[k]!=dis[to[p]]+w[p])slk[to[p]]=min(slk[to[p]],dis[to[p]]+w[p]-dis[k]);
			else if(tflow=dfs(to[p],min(maxflow,c[p])))c[p]-=tflow,c[p^1]+=tflow,maxflow-=tflow,flow+=tflow;
		return flow;
	}
	int zkwflow(int start,int end,int&co){
		s=start;t=end;
		int flow=0;cost=0;
		do{do{memset(vis,0,sizeof(vis));}while(dfs(s,inf));
		}while(modlabel());
		co=cost;
		return flow;
	}
}G;

int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)G.addedge(start,fix[i][j],1,0);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
		int t;scanf("%d",&t);
		for(int p=1;p<=n;++p)G.addedge(fix[j][p],car[i],1,p*t);
	}
	for(int i=1;i<=n;++i)G.addedge(car[i],end,1,0);
	int ans=0;G.zkwflow(start,end,ans);
	printf("%.2lf",ans*1.0/n);
	return 0;
}
