#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
using std::min;
int main(){
	LL n,m;scanf("%lld%lld",&n,&m);
	LL ans=min(n,m/2);
	n-=ans;m-=2*ans;
	if(n==0)ans+=m/4;
	printf("%lld",ans);
	return 0;
}
