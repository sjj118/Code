#include<bits/stdc++.h>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=5010,maxp=30010,maxv=2000011,inf=1e9,mo=0;
const LL linf=1e18;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
struct Graph{
	int tot,head[maxp],to[maxv],next[maxv],c[maxv],vis[maxp],sign,m[maxp];
	int s,t,pointsize;
	LL cost,dis[maxp],w[maxv];
	void getp(int&x){if(!x)x=++pointsize;}
	void ins(int a,int b,int f,int l,LL p){to[++tot]=b;c[tot]=f-l;w[tot]=p;next[tot]=head[a];head[a]=tot;}
	void addedge(int&a,int&b,int f,int l,LL p){getp(a);getp(b);ins(a,b,f,l,p);ins(b,a,0,0,-p);m[a]+=l;m[b]-=l;}
	Graph(){tot=1;}
	int q[maxp],inq[maxp],ql,qr;
	bool spfa(){
		for(int i=1;i<=pointsize;++i)dis[i]=linf;dis[t]=0;++sign;
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
		return dis[s]<linf;
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
	void avaflow(){
		int s0=0,t0=0,sum=0;getp(s0);getp(t0);
		for(int i=1;i<=pointsize-2;++i)if(m[i]>0) addedge(i,t0,m[i]),sum+=m[i];else addedge(s0,i,-m[i]);
	}
}G;
int n,s,e;
int x[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
int node[maxn][2],line[maxn][2];
int main(){
	n=read();s=read();e=read();
	rep(i,1,n)x[i]=read();
	rep(i,1,n)a[i]=read();
	rep(i,1,n)b[i]=read();
	rep(i,1,n)c[i]=read();
	rep(i,1,n)d[i]=read();
	rep(i,1,n)G.addedge(node[i][0],node[i][1],1,1,0),G.addedge(line[i][0],node[i][0],1,0,b[i]),G.addedge(node[i][1],line[i][0],1,0,c[i]),G.addedge(line[i][1],node[i][0],1,0,a[i]),G.addedge(node[i][1],line[i][1],1,0,d[i]);
	rep(i,2,n)G.addedge(line[i][0],line[i-1][0],inf,0,x[i]-x[i-1]);
	rep(i,1,n-1)G.addedge(line[i][1],line[i+1][1],inf,0,x[i+1]-x[i]);
	LL cost;G.avaflow();
	G.zkwflow(node[s][0],node[e][1],cost);
	printf("%lld\n",cost);
	return 0;
}
