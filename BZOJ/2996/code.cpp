#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
int k;
LL calc(LL R){

}
int main(){
	LL l,r;scanf("%lld%lld%d",&l,&r,&k);
	printf("%lld",calc(r)-calc(l-1));
	return 0;
}
