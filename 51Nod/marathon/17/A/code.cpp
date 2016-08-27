#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
typedef long long LL;
using namespace std;
const int maxn=1e5+10;
LL n,k,a[maxn];
LL getsg(LL x){
	if(x==1)return 0;
	if(x%k==1)return getsg(x/k);
	return (x-1)/k*(k-1)+(x-1)%k;
}
LL find(LL x,LL u){
	LL p=(x-1)/(k-1)*k+(x-1)%(k-1)+2;
	while(p<=(u-1)/k&&p*k+1<u)p=p*k+1;
	return p;
}
int main(){
	scanf("%lld%lld",&n,&k);
	LL ans=0;
	rep(i,1,n){
		scanf("%lld",&a[i]);
		ans^=getsg(a[i]);
	}
	if(ans){
		int p;
		rep(i,1,n)if((ans^getsg(a[i]))<getsg(a[i])){p=i;break;}
		printf("Alice %d %lld",p,find(ans^getsg(a[p]),a[p]));
	}else puts("Bob");
	return 0;
}
