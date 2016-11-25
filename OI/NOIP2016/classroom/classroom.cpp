#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2000+10,V=300+10,inf=1e8;
template<class T>inline void dn(T&x,T y){if(y<x)x=y;}
int n,m,v,e,c[N],d[N],dis[V][V];
double p[N],ans=inf,f[N][N][2];
int main(){
	scanf("%d%d%d%d",&n,&m,&v,&e);
	rep(i,1,n)scanf("%d",&c[i]);
	rep(i,1,n)scanf("%d",&d[i]);
	rep(i,1,n)scanf("%lf",&p[i]);
	rep(i,1,v)rep(j,1,v)if(i==j)dis[i][j]=0;else dis[i][j]=inf;
	rep(i,1,e){int u,v,w;scanf("%d%d%d",&u,&v,&w);dn(dis[u][v],w);dn(dis[v][u],w);}
	rep(k,1,v)rep(i,1,v)rep(j,1,v)dn(dis[i][j],dis[i][k]+dis[k][j]);
	rep(i,1,m)f[0][i][0]=f[0][i][1]=inf;
	rep(i,1,n)rep(j,0,m){
		f[i][j][0]=f[i][j][1]=inf;
		dn(f[i][j][0],f[i-1][j][0]+dis[c[i-1]][c[i]]);dn(f[i][j][0],f[i-1][j][1]+p[i-1]*dis[d[i-1]][c[i]]+(1-p[i-1])*dis[c[i-1]][c[i]]);
		if(j)dn(f[i][j][1],f[i-1][j-1][0]+p[i]*dis[c[i-1]][d[i]]+(1-p[i])*dis[c[i-1]][c[i]]);
		if(j)dn(f[i][j][1],f[i-1][j-1][1]+p[i]*p[i-1]*dis[d[i-1]][d[i]]+p[i]*(1-p[i-1])*dis[d[i]][c[i-1]]+(1-p[i])*p[i-1]*dis[c[i]][d[i-1]]+(1-p[i])*(1-p[i-1])*dis[c[i]][c[i-1]]);
	}
	rep(i,0,m)dn(ans,f[n][i][0]),dn(ans,f[n][i][1]);
	printf("%.2lf",ans);
	return 0;
}
