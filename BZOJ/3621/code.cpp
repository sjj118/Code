#include<iostream>
#include<cstdio>
#include<complex>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::complex;
using std::cin;
using std::fabs;
typedef double real;
typedef complex<real> Point;
const real eps=1e-4;
inline Point readComplex(){
	real x,y;cin>>x>>y;
	return Point(x,y);
}
Point p[3],_p[3],ans;
int a[3],b[3];
void solve(const Point&a,const Point&b,const Point&c,const Point&_a,const Point&_b,const Point&_c){
	Point t=(_a-_b)/(a-b);
	Point p=(a*t-_a)/(t-Point(1,0));
	Point tmp=c*t-p*t-_c+p;
	if(fabs(tmp.real())<eps&&fabs(tmp.imag())<eps)ans=p;
}
void dfs(int k){
	if(k==3){
		solve(p[0],p[1],p[2],_p[a[0]],_p[a[1]],_p[a[2]]);
	}
	rep(i,0,2)if(!b[i]){
		b[i]=1;a[k]=i;
		dfs(k+1);
		b[i]=0;
	}
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		rep(i,0,2)p[i]=readComplex();
		rep(i,0,2)_p[i]=readComplex();
		dfs(0);
		printf("%.6lf %.6lf\n",(double)ans.real(),(double)ans.imag());
	}
	return 0;
}
