#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int mo=9999991;
int main(){
	int n;scanf("%d",&n);
	LL ans=1;rep(i,1,n-2)ans=ans*n%mo;
	rep(i,1,n-1)ans=ans*i%mo;
	printf("%lld",ans);
	return 0;
}
