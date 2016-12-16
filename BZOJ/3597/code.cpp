#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=5000+10,M=3000+10,V=M<<1;
const double eps=1e-4;
int n,m;
struct Edge{
	int u,v,a,b,c,d;
}e[M];
struct Graph{
	int tot,head[N],to[V],next[V];
	double w[V],dis[N];
	void ins(int a,int b,double c){to[++tot]=b;next[tot]=head[a];head[a]=tot;w[tot]=c;}
	void clear(){tot=0;cls(head);}
	int q[N],ql,qr,inq[N],step[N];
	bool spfa(){
		ql=qr=0;cls(step);
		rep(i,1,n)inq[i]=1,q[qr++]=i;
		random_shuffle(q,q+n);
		while(ql!=qr){
			int k=q[ql++];inq[k]=0;if(ql==N)ql=0;
			for(int p=head[k];p;p=next[p])if(dis[k]+w[p]>dis[to[p]]){
				dis[to[p]]=dis[k]+w[p];
				step[to[p]]=step[k]+1;
				if(step[k]>=n)return 1;
				if(inq[to[p]])continue;
				inq[to[p]]=1;
				if(dis[to[p]]>=dis[q[ql]]){
					if(ql==0)ql=N;
					q[--ql]=to[p];
				}else{
					q[qr++]=to[p];
					if(qr==N)qr=0;
				}
			}
		}
		return 0;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);n+=2;
	rep(i,1,m)scanf("%d%d%d%d%d%d",&e[i].u,&e[i].v,&e[i].a,&e[i].b,&e[i].c,&e[i].d);
	double l=0,r=3e10;
	while(r-l>eps){
		double mid=(l+r)/2;
		G.clear();
		rep(i,1,m){
			G.ins(e[i].u,e[i].v,-e[i].d-e[i].b-mid);
			if(e[i].c)G.ins(e[i].v,e[i].u,e[i].d-e[i].a-mid);
		}
		if(G.spfa())l=mid;else r=mid;
	}
	printf("%.2lf",l);
	return 0;
}
