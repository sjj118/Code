#include<iostream>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
typedef double real;
inline void dn(LL&x,LL y){if(y<x)x=y;}
inline void dn(real&x,real y){if(y<x)x=y;}
const int N=100+10;
const LL inf=1e18;
int n,q,e[N],s[N];
LL dis[N][N];
real tim[N][N];
int main(){
	int tasknumber;scanf("%d",&tasknumber);
	rep(taskid,1,tasknumber){
		scanf("%d%d",&n,&q);
		rep(i,1,n)scanf("%d%d",&e[i],&s[i]);
		rep(i,1,n)rep(j,1,n){scanf("%lld",&dis[i][j]);if(dis[i][j]==-1)dis[i][j]=inf;}
		rep(i,1,n)dis[i][i]=0;
		rep(k,1,n)rep(i,1,n)rep(j,1,n)dn(dis[i][j],dis[i][k]+dis[k][j]);
		rep(i,1,n)rep(j,1,n)if(dis[i][j]<=e[i])tim[i][j]=1.0*dis[i][j]/s[i];else tim[i][j]=inf;
		rep(k,1,n)rep(i,1,n)rep(j,1,n)dn(tim[i][j],tim[i][k]+tim[k][j]);
		printf("Case #%d: ",taskid);
		while(q--){
			int u,v;scanf("%d%d",&u,&v);
			printf("%.8lf ",tim[u][v]);
		}
		puts("");
	}
	return 0;
}
