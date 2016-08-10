#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=210,maxp=410,maxv=40410,inf=1e9;
using namespace std;
inline int read(){int tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,m;
struct Graph{
	int tot,head[maxp],next[maxv],to[maxv],c[maxv],w[maxv],dis[maxp],cur[maxp],vis[maxp],sign;
	void ins(int a,int b,int f,int p){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;w[tot]=p;}
	int s,t,pointsize,cost;
	void getp(int&x){if(!x)x=++pointsize;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	int q[maxp],ql,qr,inq[maxp];
	Graph(){tot=1;}
	bool spfa(){
		rep(i,1,pointsize)dis[i]=inf,cur[i]=head[i];++sign;dis[t]=0;
		ql=qr=0;inq[t]=1;q[qr++]=t;
		while(ql!=qr){
			int k=q[ql++];inq[k]=0;if(ql==maxp)ql=0;
			for(int p=head[k];p;p=next[p])if(c[p^1]&&dis[to[p]]>dis[k]+w[p^1]){
				dis[to[p]]=dis[k]+w[p^1];
				if(!inq[to[p]])inq[to[p]]=1,q[qr++]=to[p];
				if(qr==maxp)qr=0;
			}
		}
		return dis[s]<inf;
	}
	int dfs(int k,int maxflow){
		if(k==t)return cost+=maxflow*dis[s],maxflow;
		int flow=0,tflow;vis[k]=sign;
		for(int&p=cur[k];p&&maxflow;p=next[p])
			if(c[p]&&dis[k]==dis[to[p]]+w[p]&&vis[to[p]]<sign&&(tflow=dfs(to[p],min(c[p],maxflow))))
			c[p]-=tflow,c[p^1]+=tflow,maxflow-=tflow,flow+=tflow;
		return flow;
	}
	int zkwflow(int start,int end,int&c){
		s=start;t=end;int flow=0,tflow;
		while(spfa())while(tflow=dfs(s,inf))flow+=tflow,++sign;
		return c=cost,flow;
	}
}G;
int node[maxn][2];
int main(){
	n=read();m=read();
	rep(i,1,m){int a=read(),b=read(),c=read();G.addedge(node[a][1],node[b][0],1,c);}
	rep(i,1,n)G.addedge(node[i][0],node[i][1],1,0);
	int cost,flow=G.zkwflow(node[1][1],node[n][0],cost);
	printf("%d %d",flow,cost);
	return 0;
}
