#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=300,maxp=600,maxv=13e4,inf=1e9;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
int m,n,s[maxn],t[maxn][maxn],w[maxn][maxn];
LL cost;
struct Graph{
	int tot,head[maxp],next[maxv],to[maxv],c[maxv],w[maxv],dis[maxp],vis[maxp],clock;
	int pointsize,s,t;
	void getp(int&x){if(!x)x=++pointsize;}
	void ins(int a,int b,int f,int p){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;w[tot]=p;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	int q[maxp],inq[maxp],ql,qr;
	Graph(){tot=1;}
	bool spfa(){
		rep(i,1,pointsize)dis[i]=inf;dis[t]=0;++clock;
		ql=qr=0;q[qr++]=t;inq[t]=1;
		while(ql!=qr){
			int k=q[ql++];if(ql==maxp)ql=0;inq[k]=0;
			for(int p=head[k];p;p=next[p])if(c[p^1]&&dis[to[p]]>dis[k]+w[p^1]){
				dis[to[p]]=dis[k]+w[p^1];
				if(!inq[to[p]]){
					inq[to[p]]=1;
					if(dis[to[p]]<=dis[q[ql]]){
						if(ql==0)ql=maxp;
						q[--ql]=to[p];
					}else{
						q[qr++]=to[p];
						if(qr==maxp)qr=0;
					}
				}
			}
		}
		return dis[s]<inf;
	}
	int dfs(int k,int maxflow){
		if(k==t)return cost+=maxflow*dis[s],maxflow;
		int flow=0,tflow;
		vis[k]=clock;
		for(int p=head[k];p&&maxflow;p=next[p])
			if(c[p]&&vis[to[p]]!=clock&&dis[to[p]]+w[p]==dis[k]&&(tflow=dfs(to[p],min(maxflow,c[p]))))
			c[p]-=tflow,c[p^1]+=tflow,flow+=tflow,maxflow-=tflow;
		return flow;
	}
	int zkwflow(int start,int end){
		s=start;t=end;
		int flow=0,tflow;
		while(spfa())while((tflow=dfs(s,inf)))++clock,flow+=tflow;
		return flow;
	}
}G;
int start,end,worker[maxn],product[maxn];
int main(){
	scanf("%d%d",&m,&n);
	rep(i,1,n)G.addedge(product[i],end,read(),0);
	rep(i,1,m)rep(j,1,n)if(read())G.addedge(worker[i],product[j],inf,0);
	rep(i,1,m){
		scanf("%d",&s[i]);
		rep(j,1,s[i])scanf("%d",&t[i][j]);t[i][s[i]+1]=inf;
		rep(j,1,s[i]+1)scanf("%d",&w[i][j]);
		rep(j,1,s[i]+1)G.addedge(start,worker[i],t[i][j]-t[i][j-1],w[i][j]);
	}
	G.zkwflow(start,end);
	printf("%lld",cost);
	return 0;
}
