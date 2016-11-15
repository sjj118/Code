#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
LL n,k;
int main(){
	scanf("%lld%lld",&n,&k);
	LL ans=0;
	for(int i=1,ne;i<=n;i=ne+1){
		if(k/i==0)ne=n;
		else ne=min(n,k/(k/i));
		ans+=k*(ne-i+1)-(k/i)*(i+ne)*(ne-i+1)/2;
	}
	printf("%lld",ans);
	return 0;
}
