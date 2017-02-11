#include<iostream>
#include<cstdio>
#include<cmath>
#include<assert.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=400+10,M=500+10;
typedef long double real;
real eps=1e-10,inf=1e100;
real a[N][M];
int n,m,c;
void pivot(int x,int y){
	rep(i,0,m)if(i!=y)a[x][i]/=a[x][y];a[x][y]=1/a[x][y];
	rep(i,0,n)if(i!=x&&fabs(a[i][y])>eps){
		rep(j,0,m)if(j!=y)a[i][j]-=a[i][y]*a[x][j];a[i][y]=-a[i][y]*a[x][y];
	}
}
void simplex(){
	/*while(1){
		int x=0,y=0;
		rep(i,1,n)if(a[i][0]<-eps)x=i;if(!x)break;
		rep(i,1,m)if(a[x][i]<-eps)y=i;assert(y);
		pivot(x,y);
	}*/
	while(1){
		int x=0,y=0;real mn=inf;
		rep(i,1,m)if(a[0][i]>eps){y=i;break;}if(!y)break;
		rep(i,1,n)if(a[i][y]>eps&&a[i][0]/a[i][y]<mn-eps)mn=a[i][0]/a[i][y],x=i;assert(x);
		pivot(x,y);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&c);
	a[1][0]=c;
	rep(i,1,m){
		int u,v,f,w;scanf("%d%d%d%d",&u,&v,&f,&w);
		a[0][i]=1;a[0][0]+=w;
		a[1][m+i]=f;
		a[i+1][i]=1;
		a[i+1][m+i]=-1;
		a[i+1][2*m+u]=-1;//a[i][2*m+n+u]=1;
		a[i+1][2*m+v]=1;//a[i][2*m+n+v]=-1;
		a[m+i+1][0]=w;
		a[m+i+1][i]=1;
	}
	int _n=n,_m=m;
	n=1+2*_m;m=_n+2*_m;
	simplex();
	printf("%.10lf\n",(double)a[0][0]);
	return 0;
}
