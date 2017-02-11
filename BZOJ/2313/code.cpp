#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int mo=1e9-401,P=mo-1,prime[4]={2,13,5281,7283},N=10000;
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
inline LL inv(LL n,LL p){return power(n,p-2,p);}
LL fact[N];
LL calcmi(LL n,LL p){
	if(n==0)return 0;
	return n/p+calcmi(n/p,p);
}
LL calcdi(LL n,LL p){
	if(n==0)return 1;
	return power(fact[p-1],n/p,p)*fact[n%p]%p*calcdi(n/p,p)%p;
}
LL calc(LL n,LL m,LL p){
	if(calcmi(n,p)-calcmi(m,p)*(n/m)-calcmi(n/m,p))return 0;
	return calcdi(n,p)*power(inv(calcdi(m,p),p),n/m,p)%p*inv(calcdi(n/m,p),p)%p;
	//fact[n]/fact[m]^(n/m)/fact[n/m];
}
LL calc(LL n){
	LL ret=0;;
	rep(ttp,0,3){
		LL tmp=0;
		LL p=prime[ttp];
		fact[0]=1;rep(i,1,p-1)fact[i]=fact[i-1]*i%p;
		for(LL i=1;i*i<=n;++i)if(n%i==0){
			ad(tmp,calc(n,i,p),p);
			if(i*i!=n)ad(tmp,calc(n,n/i,p),p);
		}
		ad(ret,P/p*inv(P/p,p)%P*tmp%P,P);
	}
	return ret;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,m;scanf("%d%d",&n,&m);
		printf("%lld\n",power(m,calc(n),mo));
	}
	return 0;
}
