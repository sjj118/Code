#include<cstdio>
#include<algorithm>
#include<cmath>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::swap;
typedef double real;
const int N=20+5;
const real eps=1e-8,inf=1e20;
int n,m,t;
namespace Simplex{
	const int OK=0,UNBOUNDED=1,INFEASIBLE=2;
	int n,m,id[N<<1];
	real a[N][N];
	void init(int _n,int _m){
		n=_n;m=_m;
	}
	void pivot(int x,int y){
		swap(id[m+x],id[y]);
		rep(i,0,m)if(i!=y)a[x][i]/=a[x][y];a[x][y]=1/a[x][y];
		rep(i,0,n)if(i!=x&&fabs(a[i][y])>eps){
			rep(j,0,m)if(j!=y)a[i][j]-=a[i][y]*a[x][j];a[i][y]=-a[i][y]*a[x][y];
		}
	}
	int simplex(){
		rep(i,1,n+m)id[i]=i;
		while(1){
			int x=0,y=0;real mn=0;
			rep(i,1,n)if(a[i][0]<mn-eps)x=i,mn=a[i][0];if(!x)break;
			rep(j,1,m)if(a[x][j]<-eps)y=j;if(!y)return INFEASIBLE;
			pivot(x,y);
		}
		while(1){
			int x=0,y=0;real mn=inf;
			rep(j,1,m)if(a[0][j]>eps){y=j;break;}if(!y)break;
			rep(i,1,n)if(a[i][y]>eps&&a[i][0]/a[i][y]<mn)x=i,mn=a[i][0]/a[i][y];if(!x)return UNBOUNDED;
			pivot(x,y);
		}
		return OK;
	}
	real ans[N];
	void solve(){
		int sign=Simplex::simplex();
		if(sign==UNBOUNDED)puts("Unbounded");
		if(sign==INFEASIBLE)puts("Infeasible");
		if(sign==OK){
			printf("%.10lf\n",-a[0][0]);
			if(!t)return;
			rep(i,1,n)if(id[m+i]<=m)ans[id[m+i]]=a[i][0];
			rep(i,1,m)printf("%.10lf ",ans[i]);
		}
	}
};
int main(){
	scanf("%d%d%d",&n,&m,&t);
	Simplex::init(m,n);
	rep(i,1,n)scanf("%lf",&Simplex::a[0][i]);
	rep(i,1,m){
		rep(j,1,n)scanf("%lf",&Simplex::a[i][j]);
		scanf("%lf",&Simplex::a[i][0]);
	}
	Simplex::solve();
	return 0;
}
