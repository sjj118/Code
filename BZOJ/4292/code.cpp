#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::min;
typedef long long LL;
LL k,a,b;
inline LL sqr(LL x){return x*x;}
LL f(LL n){
	LL ret=0;
	while(n)ret+=sqr(n%10),n/=10;
	return ret;
}
int main(){
	scanf("%lld%lld%lld",&k,&a,&b);
	int ans=0;
	rep(i,a/k,min(1500ll,b/k))if(a<=k*i&&k*i<=b&&f(k*i)*k==k*i)++ans;
	printf("%d",ans);
	return 0;
}
