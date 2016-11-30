#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=500+10,P=N*2,V=2*(N*N+N+N*N),inf=1e9;
int n,m,r,t,k,man[N],pro[N],start,end;
struct Graph{
	int tot,head[P],to[V],next[V],c[V],w[V],dis[P],clock,vis[P];
	int s,t,ps,cost;
	Graph(){tot=1;}
	void getp(int&x){if(!x)x=++ps;}
	void ins(int a,int b,int f,int p){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;w[tot]=p;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	int q[P],ql,qr,inq[P];
	bool spfa(){
		rep(i,1,ps)dis[i]=inf;++clock;dis[t]=0;
		ql=qr=0;q[qr++]=t;
		while(ql!=qr){
			int k=q[ql++];if(ql==P)ql=0;inq[k]=0;
			for(int p=head[k];p;p=next[p])if(c[p^1]&&dis[to[p]]>dis[k]+w[p^1]){
				dis[to[p]]=dis[k]+w[p^1];
				if(inq[to[p]])continue;
				inq[to[p]]=1;
				if(dis[to[p]]<dis[q[ql]]){
					if(ql==0)ql=P;
					q[--ql]=to[p];
				}else{
					q[qr++]=to[p];
					if(qr==P)qr=0;
				}
			}
		}
		return dis[s]<inf;
	}
	int dfs(int k,int mf){
		if(k==t)return cost+=dis[s]*mf,mf;
		int flow=0,tf;
		vis[k]=clock;
		for(int p=head[k];p&&mf;p=next[p])
			if(vis[to[p]]!=clock&&c[p]&&dis[to[p]]+w[p]==dis[k]&&(tf=dfs(to[p],min(c[p],mf))))
			flow+=tf,mf-=tf,c[p]-=tf,c[p^1]+=tf;
		return flow;
	}
	int zkwflow(int start,int end,int&c){
		s=start;t=end;
		int flow=0,tf;
		while(spfa())while(tf=dfs(s,inf))++clock,flow+=tf;
		return c=cost,flow;
	}
}G;
int main(){
	scanf("%d%d%d%d%d",&n,&m,&r,&t,&k);
	rep(i,1,k){
		int a,b;scanf("%d%d",&a,&b);
		G.addedge(man[a],pro[b],1,0);
	}
	rep(i,1,m)G.addedge(pro[i],end,1,0);
	rep(i,1,n)rep(j,1,min(m,t/r))G.addedge(start,man[i],1,j);
	int ans2,ans1=G.zkwflow(start,end,ans2);
	printf("%d %d\n",ans1,ans2*r);
	return 0;
}
