#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=110,inf=1e9,maxp=210,maxv=41000;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,m,k,c[maxn],f[maxn];
struct Graph{
	int tot,head[maxp],to[maxv],next[maxv],c[maxv],w[maxv],dis[maxp],clock,vis[maxp];
	int pointsize,s,t,cost;
	void getp(int&x){if(!x)x=++pointsize;}
	void ins(int a,int b,int f,int p){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;w[tot]=p;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	int q[maxp],ql,qr,inq[maxp];
	Graph(){tot=1;}
	bool spfa(){
		rep(i,1,pointsize)dis[i]=inf;++clock;dis[t]=0;
		ql=qr=0;q[qr++]=t;inq[t]=1;
		while(ql!=qr){
			int k=q[ql++];if(ql==maxp)ql=0;inq[k]=0;
			for(int p=head[k];p;p=next[p])if(c[p^1]&&dis[to[p]]>dis[k]+w[p^1]){
				dis[to[p]]=dis[k]+w[p^1];
				if(!inq[to[p]]){
					q[qr++]=to[p];
					inq[to[p]]=1;
					if(qr==maxp)qr=0;
				}
			}
		}
		return dis[s]<inf;
	}
	int dfs(int k,int maxflow){
		if(k==t)return cost+=maxflow*dis[s],maxflow;
		vis[k]=clock;
		int flow=0,tflow;
		for(int p=head[k];p;p=next[p])
			if(c[p]&&vis[to[p]]!=clock&&maxflow&&dis[k]==dis[to[p]]+w[p]&&(tflow=dfs(to[p],min(maxflow,c[p]))))
			c[p]-=tflow,c[p^1]+=tflow,maxflow-=tflow,flow+=tflow;
		return flow;
	}
	int zkwflow(int start,int end,int&c){
		s=start;t=end;
		int flow=0,tflow;
		while(spfa())while((tflow=dfs(s,inf)))flow+=tflow,++clock;
		return c=cost,flow;
	}
}G;
int stu[maxn],les[maxn],start,end;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m)scanf("%d",&c[i]);
	rep(i,1,m)scanf("%d",&f[i]);
	rep(i,1,n)G.addedge(start,stu[i],k,0),G.addedge(stu[i],end,k-1,0);
	rep(i,1,n)rep(j,1,m)if(gc()-'0')G.addedge(stu[i],les[j],1,-f[j]);
	rep(i,1,m)rep(j,1,n)G.addedge(les[i],end,1,(j*2-1)*c[i]);
	int ans;G.zkwflow(start,end,ans);
	printf("%d",ans);
	return 0;
}
