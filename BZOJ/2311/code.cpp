#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<assert.h>
#define pb push_back
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double real;
const int N=50+5,P=N*N,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const real eps=1e-8;
inline real readreal(){double x;scanf("%lf",&x);return x;}
int n,m;
inline int id(int x,int y){return (x-1)*m+y;}
inline int dblcmp(real x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
struct Matrix{
	int n,m;
	real val[P][P];
	Matrix(){n=m=0;cls(val);}
	Matrix(int n,int m):n(n),m(m){cls(val);}
	real*operator[](int x){return val[x];}
	const real*operator[](int x)const{return val[x];}
	void gauss(int l,int r){
		if(l==r)return;
		int mid=(l+r)>>1;
		vector<vector<real> > a(mid-l+1);
		rep(i,l,mid){
			a[i-l].pb(0);
			rep(j,1,m)a[i-l].pb(val[i][j]);
		}
		gauss(l,mid);
		rep(i,l,mid){
			int cnt=0;
			rep(j,mid+1,r)if(dblcmp(val[j][i])){
				assert(++cnt<=4);
				real t=val[j][i]/val[i][i];
				rep(k,1,m)val[j][k]-=val[i][k]*t;
			}
		}
		gauss(mid+1,r);
		rep(i,l,mid)rep(j,1,m)val[i][j]=a[i-l][j];
		rep(i,mid+1,r){
			int cnt=0;
			rep(j,l,mid)if(dblcmp(val[j][i])){
				//assert(++cnt<=4);
				real t=val[j][i]/val[i][i];
				rep(k,1,m)val[j][k]-=val[i][k]*t;
			}
		}
		gauss(l,mid);
	}
}mat;
int main(){
	scanf("%d%d",&n,&m);
	mat.n=n*m;mat.m=n*m+1;
	rep(i,1,n)rep(j,1,m)mat[id(i,j)][id(i,j)]--,mat[id(i,j)][n*m+1]=1;
	mat[id(n,m)][n*m+1]=0;
	rep(p,0,3){
		rep(i,1,n)rep(j,1,m){
			mat[id(i,j)][id(i+dx[p],j+dy[p])]+=readreal();
		}
	}
	mat.gauss(1,n*m);
	printf("%.3lf",-(double)(mat[1][n*m+1]/mat[1][1]));
	return 0;
}
