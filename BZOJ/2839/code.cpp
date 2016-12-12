#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e6+10,mo=1e9+7;
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
int n,k;
LL ans=0,mi=2,f=1,fact[N],inv[N],_fact[N];
inline LL C(LL n,LL m){
	if(m>n)return 0;
	return fact[n]*_fact[m]%mo*_fact[n-m]%mo;
}
int main(){
	scanf("%d%d",&n,&k);
	inv[1]=1;rep(i,2,n)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	fact[0]=1;rep(i,1,n)fact[i]=fact[i-1]*i%mo;
	_fact[0]=1;rep(i,1,n)_fact[i]=_fact[i-1]*inv[i]%mo;
	if((n-k)&1)f=-1;else f=1;
	per(i,n-k,0)ad(ans,C(n,k)*f*(mi-1)%mo*C(n-k,i)%mo,mo),mi=mi*mi%mo,f=-f;
	printf("%lld",ans);
	return 0;
}
