#include<iostream>
#include<cstdio>
#include<assert.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
int n,p;
int main(){
	scanf("%d%d",&n,&p);
	LL ans=1;
	rep(i,1,n)ans=ans*i%p;
	if(n&1)ans/=2;
	printf("%lld",ans);
	return 0;
}
