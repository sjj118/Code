#include<cstdio>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::fabs;
const int N=20+1,UNBOUNDED=0,INFEASIBLE=1,CORRECT=2;
typedef double real;
const real eps=1e-8,inf=1e100;
inline real read(){double x;scanf("%lf",&x);return x;}
inline void swap(int&a,int&b){int t=a;a=b;b=t;}
int n,m,t,id[N<<1];
real a[N][N];
void pivot(int x,int y){
	swap(id[m+x],id[y]);
	rep(j,0,m)if(j!=y)a[x][j]/=a[x][y];a[x][y]=1/a[x][y];
	rep(i,0,n)if(i!=x&&fabs(a[i][y])>eps){
		rep(j,0,m)if(j!=y)a[i][j]-=a[x][j]*a[i][y];a[i][y]*=-a[x][y];
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
		rep(i,1,n)if(a[i][y]>eps&&a[i][0]/a[i][y]<mn-eps)x=i,mn=a[i][0]/a[i][y];if(!x)return UNBOUNDED;
		pivot(x,y);
	}
	return CORRECT;
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	swap(n,m);
	rep(i,1,m)a[0][i]=read();
	rep(i,1,n){
		rep(j,1,m)a[i][j]=read();
		a[i][0]=read();
	}
	int k=simplex();
	if(k==UNBOUNDED)puts("Unbounded");
	if(k==INFEASIBLE)puts("Infeasible");
	if(k==CORRECT){
		printf("%.10lf\n",(double)-a[0][0]);
		rep(i,1,m)a[0][i]=0;
		rep(i,1,n)if(id[m+i]<=m)a[0][id[m+i]]=a[i][0];
		if(t)rep(i,1,m)printf("%.10lf ",(double)a[0][i]);
	}
	return 0;
}
