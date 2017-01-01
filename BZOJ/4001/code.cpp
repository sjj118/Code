#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double LB;
int n;
int main(){
	scanf("%d",&n);
	printf("%.9lf",(double)((LB)n/2/(2*n-1)*(n+1)));
	return 0;
}
