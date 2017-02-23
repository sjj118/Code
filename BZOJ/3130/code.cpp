#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::min;
typedef double real;
const int N=10000+10,M=200000+10;
const real eps=1e-6,inf=1e100;
int n,m,p;
real mx;
struct Graph{
	int tot,head[N],to[M],next[M],dis[N],cur[N];
	int s,t;
	real c[M];
	void ins(int a,int b,real f){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;}
	void addedge(int a,int b,real f){ins(a,b,f);ins(b,a,0);}
	void clear(){tot=1;cls(head);}
	int q[N],ql,qr;
	bool bfs(){
		rep(i,1,n)dis[i]=0,cur[i]=head[i];
		ql=qr=0;q[qr++]=t;
		while(ql!=qr)for(int k=q[ql++],p=head[k];p;p=next[p])
			if(c[p^1]>eps&&!dis[to[p]]&&to[p]!=t)dis[q[qr++]=to[p]]=dis[k]+1;
		return dis[s]>eps;
	}
	real dfs(int k,real mf){
		if(k==t)return mf;
		real flow=0,tf;
		for(int&p=cur[k];p&&mf;p=next[p])
			if(c[p]>eps&&dis[to[p]]+1==dis[k]&&(tf=dfs(to[p],min(mf,c[p])))>eps)
				c[p]-=tf,c[p^1]+=tf,mf-=tf,flow+=tf;
		return flow;
	}
	real Dinic(int start,int end){
		s=start;t=end;
		real flow=0;
		while(bfs())flow+=dfs(s,inf);
		return flow;
	}
}G;
struct Edge{
	int a,b,c;
}e[M];
int main(){
	scanf("%d%d%d",&n,&m,&p);
	G.clear();
	rep(i,1,m)scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),G.addedge(e[i].a,e[i].b,e[i].c);
	mx=G.Dinic(1,n);
	printf("%d\n",int(mx+0.5));
	real l=0,r=50000;
	while(r-l>eps){
		real mid=(l+r)/2;
		G.clear();
		rep(i,1,m)G.addedge(e[i].a,e[i].b,min(1.0*e[i].c,mid));
		if(G.Dinic(1,n)>=mx-eps)r=mid;else l=mid;
	}
	printf("%.5lf",l*p);
	return 0;
}
