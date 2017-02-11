#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double real;
const int N=1000000+10;
inline real readreal(){double x;scanf("%lf",&x);return x;}
int n;
real p,q,f[2][N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);p=readreal();q=readreal();
		n=min(n,100000);
		rep(i,1,n){
			real A,B,C,D;
			if(i&1){
				A=p*(1-f[1][i-1])+1-p;B=p-1;
				C=q*(1-f[0][i-1])+1-q;D=q-1;
			}else{
				A=(1-p)*(1-f[1][i-1])+p;B=-p;
				C=(1-q)*(1-f[0][i-1])+q;D=-q;
			}
			f[0][i]=(A+B*C)/(1-B*D);
			f[1][i]=C+D*f[0][i];
			//printf("%.10lf %.10lf\n",(double)f[0][i],(double)f[1][i]);
		}
		printf("%.6lf\n",(double)f[0][n]);
	}
	return 0;
}
