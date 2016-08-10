#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 810
#define maxp 2000
#define maxv 50000
#define inf 1e9

using namespace std;

int n,m;
int star[maxn][2],start,end;
struct Graph{
	int tot,head[maxp],to[maxv],next[maxv],c[maxv],w[maxv],dis[maxp],slk[maxp],vis[maxp];
	int s,t,pointsize,cost;
	void getp(int&x){if(!x)x=++pointsize;}
	void ins(int a,int b,int f,int p){to[++tot]=b;c[tot]=f;w[tot]=p;next[tot]=head[a];head[a]=tot;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	Graph(){tot=1;}
	int q[maxp],inq[maxp],ql,qr;
	bool spfa(){
		for(int i=1;i<=pointsize;++i)dis[i]=inf,vis[i]=0;dis[t]=0;
		ql=1;qr=1;q[qr++]=t;inq[t]=1;
		while(ql!=qr){
			int k=q[ql++];inq[k]=0;
			if(ql==maxp)ql=0;
			for(int p=head[k];p;p=next[p])if(c[p^1]&&dis[k]+w[p^1]<dis[to[p]]){
				dis[to[p]]=dis[k]+w[p^1];
				if(!inq[to[p]])inq[to[p]]=1,q[qr++]=to[p];
				if(qr==maxp)qr=0;
			}
		}
		return dis[s]<inf;
	}
	bool modlabel(){
		int delta=inf;
		for(int i=1;i<=pointsize;++i)if(!vis[i])delta=min(delta,slk[i]),slk[i]=inf;
		if(delta==inf)return 0;
		for(int i=1;i<=pointsize;++i)if(vis[i])dis[i]+=delta,vis[i]=0;
		return 1;
	}
	int dfs(int k,int maxflow){
		if(k==t)return cost+=maxflow*dis[s],maxflow;
		int flow=0,tflow;vis[k]=1;
		for(int p=head[k];p&&maxflow;p=next[p])if(c[p]&&!vis[to[p]])
			if(dis[k]!=dis[to[p]]+w[p])slk[to[p]]=min(slk[to[p]],dis[to[p]]+w[p]-dis[k]);
			else if(tflow=dfs(to[p],min(maxflow,c[p])))c[p]-=tflow,c[p^1]+=tflow,flow+=tflow,maxflow-=tflow;
		return flow;
	}
	int zkwflow(int start,int end,int&c){
		s=start,t=end;
		int flow=0,tflow;
//		while(spfa())while(tflow=dfs(s,inf))flow+=tflow,memset(vis,0,sizeof(vis));
		do{while(tflow=dfs(s,inf))flow+=tflow,memset(vis,0,sizeof(vis));}while(modlabel());
//		do{do{memset(vis,0,sizeof(vis));}while(dfs(s,inf));
//		}while(modlabel());
		return c=cost,flow;
	}
}G;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int x;scanf("%d",&x);
		G.addedge(start,star[i][0],1,0);
		G.addedge(star[i][0],end,1,x);
		G.addedge(star[i][1],end,1,0);
	}
	for(int i=1;i<=m;++i){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);if(u>v)swap(u,v);
		G.addedge(star[v][0],star[u][1],1,w);
	}
	int ans=0;
	G.zkwflow(start,end,ans);
	printf("%d",ans);
	return 0;
}
