#include<cstdio>
#include<algorithm>
typedef long long LL;
inline LL mul(LL x,LL y,LL p){LL a=0;for(;y;y>>=1,x=(x<<1)%p)if(y&1)a=(a+x)%p;return a;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=mul(x,x,p))if(y&1)a=mul(a,x,p);return a;}
int main(){
	LL n,m,p;scanf("%lld%lld%lld",&n,&m,&p);
	printf("%lld",mul(power(n,m-1,p),power(m,n-1,p),p));
	return 0;
}
