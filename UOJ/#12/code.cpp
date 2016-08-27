#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
LL g,l;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&g,&l);
		printf("%lld %lld\n",2*(LL)round(sqrt(l/g))*g,g*(1+l/g));
	}
}
