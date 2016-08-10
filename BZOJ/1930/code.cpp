#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1e9
#define maxn 2016
#define maxp 5000
#define maxv 4000110

using namespace std;

struct Graph{
	int tot,head[maxp],to[maxv],next[maxv],c[maxv],w[maxv],dis[maxp],vis[maxp],slk[maxp];
	int s,t,pointsize,cost;
	void getp(int&x){if(!x)x=++pointsize;}
	void ins(int a,int b,int f,int p){to[++tot]=b;c[tot]=f;w[tot]=p;next[tot]=head[a];head[a]=tot;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	Graph(){tot=1;}
	int q[maxp],ql,qr,inq[maxp];
	bool spfa(){
		for(int i=1;i<=pointsize;++i)dis[i]=inf;dis[t]=0;
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
	int zkwflow(int start,int end,int&c){
		s=start;t=end;
		int flow=0;cost=0;
//		while(spfa()){
//			do{memset(vis,0,sizeof(vis));}while(dfs(s,inf));
//		}
		spfa();
		do{do{memset(vis,0,sizeof(vis));}while(dfs(s,inf));
		}while(modlabel());
		return c=cost,flow;
	}
}G;
int n,bean[maxn][2],start,end,pac;
struct Point{
	int x,y;
}p[maxn];
bool comp(Point a,Point b){return a.x<b.x||a.x==b.x&&a.y<b.y;}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y);
	G.addedge(start,pac,2,0);
	for(int i=1;i<=n;++i)G.addedge(pac,bean[i][0],1,0),G.addedge(bean[i][0],bean[i][1],1,-1),G.addedge(bean[i][0],bean[i][1],1,0),G.addedge(bean[i][1],end,1,0);
	sort(p+1,p+1+n,comp);
	for(int i=1;i<=n;++i){
		int low=inf;
		for(int j=i+1;j<=n;++j){
			if(p[i].y<=p[j].y&&p[j].y<low)G.addedge(bean[i][1],bean[j][0],2,0),low=p[j].y;
		}
	}
	int ans=0;
	G.zkwflow(start,end,ans);
	printf("%d",-ans);
	return 0;
}
