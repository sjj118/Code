#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::swap;
using std::fabs;
typedef long double real;
real inf=1e100,eps=1e-10;
real read(){double x;scanf("%lf",&x);return x;}
inline void dn(real&x,real y){if(y<x)x=y;}
const int N=100+10,K=10;
int n,c[N],l[K][N],mx[K][K];
real p[K][N],f[K][K];
real ans=inf;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&c[i]);
	rep(k,1,7)rep(i,1,n)p[k][i]=read();
	rep(k,1,7)rep(i,1,n)scanf("%d",&l[k][i]);
	rep(i,1,7)rep(j,i+1,8)f[i][j]=inf;
	rep(j,1,8){
		per(i,j-1,1){
			rep(k,1,n)dn(f[i][j],(c[k]+p[i][k]*f[i+1][j]+(1-p[i][k])*f[i-l[i][k]][i])/p[i][k]);
		}
	}
	if(f[1][8]+eps>=inf)puts("-1");
	else printf("%.10lf",(double)f[1][8]);
	return 0;
}
