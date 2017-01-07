#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
int n;
int main(){
	scanf("%d",&n);
	LL ans=0;
	rep(i,1,n)ans+=n/i;
	printf("%lld",ans);
	return 0;
}
