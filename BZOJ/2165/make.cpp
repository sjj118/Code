#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	int T=5;
	printf("%d\n",T);
	while(T--){
		int n=100;LL m=1e18;
		printf("%d %lld\n",n,m);
		rep(i,1,n){
			rep(j,1,n)printf("%lld ",(LL)rand()*rand()%1000000000ll);puts("");
		}
	}
	return 0;
}
