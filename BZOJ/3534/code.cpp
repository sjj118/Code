#include<iostream>
#include<cstdio>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::swap;
typedef double real;
const int N=50+10;
const real eps=1e-7;
int n;
real sum=1;
struct Matrix{
	int n;
	real val[N][N];
	real*operator[](int x){return val[x];}
	const real*operator[](int x)const{return val[x];}
	real Determinant(){
		real ret=1;
		rep(i,1,n){
			int k=i;
			rep(j,i+1,n)if(fabs(val[j][i])>fabs(val[k][i]))k=j;
			if(k!=i){
				ret=-ret;
				rep(j,i,n)swap(val[k][j],val[i][j]);
			}
			rep(j,i+1,n){
				real t=val[j][i]/val[i][i];
				rep(k,i,n)val[j][k]-=val[i][k]*t;
			}
		}
		rep(i,1,n)ret*=val[i][i];
		return ret;
	}
}mat;
int main(){
	scanf("%d",&n);
	mat.n=n-1;
	rep(i,1,n)rep(j,1,n){
		real x;scanf("%lf",&x);
		if(i==j)continue;
		if(x==1)x-=eps;
		if(i<j)sum*=(1-x);
		mat[i][j]=-x/(1-x);
		mat[i][i]+=x/(1-x);
	}
	printf("%.8lf",mat.Determinant()*sum);
	return 0;
}
