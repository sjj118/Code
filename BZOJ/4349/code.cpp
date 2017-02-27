#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef double real;
inline void dn(real&x,real y){if(y<x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
const int N=50+5,M=N*N;
const real inf=1e100;
struct Edge{
	int a,b;
	real c;
}e[M];
int n,m;
real a[N];
int b[N];
int pre[N],nid[N],nps,vis[N];
real in[N];
real DMST(int n){
	real ret=0;
	while(1){
		rep(i,1,n)in[i]=inf;cls(pre);nps=0;cls(nid);cls(vis);
		rep(i,1,m)if(e[i].a!=e[i].b)e[++nps]=e[i];m=nps;nps=0;
		rep(i,1,m)if(e[i].c<in[e[i].b])in[e[i].b]=e[i].c,pre[e[i].b]=e[i].a;
		rep(i,1,n){
			ret+=in[i];
			int k;
			for(k=i;k&&!vis[k];k=pre[k])vis[k]=i;
			if(k&&vis[k]==i){
				nid[k]=++nps;
				for(int p=pre[k];p!=k;p=pre[p])nid[p]=nps;
			}
		}
		if(!nps)return ret;
		rep(i,1,n)if(!nid[i])nid[i]=++nps;n=nps;
		rep(i,1,m){
			real t=in[e[i].b];
			e[i].a=nid[e[i].a];e[i].b=nid[e[i].b];
			if(e[i].a!=e[i].b)e[i].c-=t;
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lf%d",&a[i],&b[i]);
	scanf("%d",&m);
	rep(i,1,m)scanf("%d%d%lf",&e[i].a,&e[i].b,&e[i].c);
	rep(i,1,n){
		e[++m].b=i;
		e[m].c=a[i];
	}
	rep(i,1,m)dn(a[e[i].b],e[i].c);
	real ans=DMST(n);
	rep(i,1,n)ans+=(b[i]-1)*a[i];
	printf("%.2lf",ans);
	return 0;
}
