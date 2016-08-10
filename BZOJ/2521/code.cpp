#include<iostream>
#include<cstdio>
#define maxn 510
#define maxm 1700
#define inf 1e9

using namespace std;

int n,m,lab;
struct Edge{
	int u,v,d;
	void init(int U,int V,int D){u=U;v=V;d=D;}
}edge[maxm];

struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],c[maxm],dis[maxn],cur[maxn];
	int pointsize,s,t;
	void ins(int a,int b,int C){to[++tot]=b;c[tot]=C;next[tot]=head[a];head[a]=tot;}
	void addedge(int&a,int&b,int C){ins(a,b,C);ins(b,a,C);}
	int q[maxn],ql,qr;
	bool BFS(){
		for(int i=1;i<=pointsize;++i)cur[i]=head[i],dis[i]=0;
		ql=1;qr=0;q[++qr]=t;
		while(ql<=qr)
			for(int k=q[ql++],p=head[k];p;p=next[p])
			if(c[p^1]&&to[p]!=t&&!dis[to[p]])dis[q[++qr]=to[p]]=dis[k]+1;
		return dis[s];
	}
	int DFS(int k,int maxflow){
		if(k==t)return maxflow;
		int flow=0,tflow;
		for(int&p=cur[k];p&&maxflow;p=next[p])
			if(c[p]&&dis[to[p]]+1==dis[k]&&(tflow=DFS(to[p],min(maxflow,c[p]))))
			c[p]-=tflow,c[p^1]+=tflow,maxflow-=tflow,flow+=tflow;
		return flow;
	}
	int Dinic(int start,int end){
		s=start;t=end;
		int flow=0;
		while(BFS())flow+=DFS(s,inf);
		return flow;
	}
	Graph(){
		tot=1;
	}
}G;

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d%d",&n,&m,&lab);
	for(int i=1;i<=m;++i){
		int u,v,d;scanf("%d%d%d",&u,&v,&d);
		edge[i].init(u,v,d);
	}
	for(int i=1;i<=m;++i)if(i!=lab){
		if(edge[lab].d-edge[i].d+1>0)G.addedge(edge[i].u,edge[i].v,edge[lab].d-edge[i].d+1);
	}
	G.pointsize=n;
	printf("%d",G.Dinic(edge[lab].u,edge[lab].v));
	return 0;
}
