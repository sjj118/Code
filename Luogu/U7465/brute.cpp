#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=100+10,mo=1e9+7;
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
int n,a[N];
LL x,b[N];
inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
inline LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
LL f(int n){
	LL ret=0;
	rep(i,0,n)ret=(ret+power(x,i,mo))%mo;
	return ret;
}
int main(){
	scanf("%lld%d",&x,&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)b[i]=f(a[i]);
	LL ans=1;
	rep(i,1,n)ans=lcm(ans,b[i]);
	printf("%lld",ans%mo);
	return 0;
}
