#include<iostream>
#include<cstdio>
#define inf 1e9
#define maxn 1010
#define maxm 10010
#define maxp 1010
#define maxv 30000
#define LL long long

using namespace std;

int n,m,p[maxn],s[maxm],t[maxm],c[maxm];
struct Graph{
	int tot,head[maxp],to[maxv],next[maxv],c[maxv],w[maxv],dis[maxp],vis[maxp],sign;
	int s,t,pointsize;
	LL cost;
	void getp(int&x){if(!x)x=++pointsize;}
	void ins(int a,int b,int f,int p){to[++tot]=b;c[tot]=f;w[tot]=p;next[tot]=head[a];head[a]=tot;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	Graph(){tot=1;}
	int q[maxp],inq[maxp],ql,qr;
	bool spfa(){
		for(int i=1;i<=pointsize;++i)dis[i]=inf;dis[t]=0;++sign;
		ql=qr=0;q[qr++]=t;inq[t]=1;
		while(ql!=qr){
			int k=q[ql++];inq[k]=0;if(ql==maxp)ql=0;
			for(int p=head[k];p;p=next[p])if(c[p^1]&&dis[k]+w[p^1]<dis[to[p]]){
				dis[to[p]]=dis[k]+w[p^1];
				if(!inq[to[p]]){
					inq[to[p]]=1;
					q[qr++]=to[p];
					if(qr==maxp)qr=0;
				}
			}
		}
		return dis[s]<inf;
	}
	int dfs(int k,int maxflow){
		if(k==t)return cost+=(LL)maxflow*dis[s],maxflow;
		int flow=0,tflow;vis[k]=sign;
		for(int p=head[k];p&&maxflow;p=next[p])
			if(c[p]&&vis[to[p]]!=sign&&dis[k]==dis[to[p]]+w[p]&&(tflow=dfs(to[p],min(maxflow,c[p]))))
			c[p]-=tflow,c[p^1]+=tflow,maxflow-=tflow,flow+=tflow;
		return flow;
	}
	int zkwflow(int start,int end,LL&c){
		s=start;t=end;
		int flow=0,tflow;sign=0;
		while(spfa())while(tflow=dfs(s,inf))flow+=tflow,++sign;
		return c=cost,flow;
	}
}G;
int start,end,fang[maxn];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=m;++i)scanf("%d%d%d",&s[i],&t[i],&c[i]);
	for(int i=1;i<=m;++i)G.addedge(fang[t[i]+1],fang[s[i]],inf,c[i]);
	for(int i=1;i<=n+1;++i)if(p[i]-p[i-1]>0)G.addedge(fang[i],end,p[i]-p[i-1],0);else G.addedge(start,fang[i],p[i-1]-p[i],0);
	for(int i=1;i<=n;++i)G.addedge(fang[i],fang[i+1],inf,0);
	LL ans;
	G.zkwflow(start,end,ans);
	printf("%lld",ans);
	return 0;
}
