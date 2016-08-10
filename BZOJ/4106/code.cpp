#include<iostream>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
const int maxn=1e6+10;
using namespace std;

int p,a,b,c,d,n;
double x[maxn];

int main(){
	while(scanf("%d%d%d%d%d%d",&p,&a,&b,&c,&d,&n)>0){
		rep(i,1,n)x[i]=p*(sin(a*i+b)+cos(c*i+d)+2);
		double tmp=0,ans=0;
		rep(i,1,n)tmp=max(tmp,x[i]),ans=max(ans,tmp-x[i]);
		printf("%.6lf\n",ans);
	} 
	return 0;
}
