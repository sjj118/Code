#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define inf 1e9
#define maxn 1010
#define maxp 2016
#define maxv 1000000

using namespace std;

struct Graph{
	int tot,head[maxp],to[maxv],next[maxv],c[maxv],w[maxv],dis[maxp],vis[maxp],sign;
	int s,t,pointsize,cost;
	void getp(int&x){if(!x)x=++pointsize;}
	void ins(int a,int b,int f,int p){to[++tot]=b;c[tot]=f;w[tot]=p;next[tot]=head[a];head[a]=tot;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	Graph(){tot=1;}
	int q[maxp],inq[maxp],ql,qr;
	bool spfa(){
		for(int i=1;i<=pointsize;++i)dis[i]=inf;dis[t]=0;++sign;
		ql=0;qr=0;q[qr++]=t;inq[t]=1;
		while(ql!=qr){
			int k=q[ql++];if(ql==maxp)ql=0;inq[k]=0;
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
		if(k==t)return cost+=maxflow*dis[s],maxflow;
		int flow=0,tflow;vis[k]=sign;
		for(int p=head[k];p&&maxflow;p=next[p])
			if(c[p]&&vis[to[p]]!=sign&&dis[k]==dis[to[p]]+w[p]&&(tflow=dfs(to[p],min(maxflow,c[p]))))
			c[p]-=tflow,c[p^1]+=tflow,maxflow-=tflow,flow+=tflow;
		return flow;
	}
	int zkwflow(int start,int end,int&c){
		s=start;t=end;cost=0;
		int flow=0,tflow;sign=1;
		while(spfa())while(tflow=dfs(s,inf))flow+=tflow,++sign;
		return c=cost,flow;
	}
}G;
int a,b,node[maxn][2],start,end;
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}

int main(){
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;++i)G.addedge(start,node[i][0],1,0),G.addedge(node[i][1],end,1,0);
	for(int i=a;i<=b;++i){
		for(int j=a;j<i;++j){
			int x=floor(sqrt(i*i-j*j));
			if(x*x==i*i-j*j&&gcd(j,x)==1)G.addedge(node[i][0],node[j][1],1,-i-j),G.addedge(node[j][0],node[i][1],1,-i-j);
		}
	}
	int ans=0;
	printf("%d ",G.zkwflow(start,end,ans)/2);
	printf("%d",-ans/2);
	return 0;
}
