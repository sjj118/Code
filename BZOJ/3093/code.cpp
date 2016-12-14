#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int n,p,q;
int main(){
	int T=0;
	while(scanf("%d%d%d",&n,&p,&q)>0){
		printf("Case %d: %.4lf\n",++T,1.0*(q+1)/(p+2));
	}
	return 0;
}
