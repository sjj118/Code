#include<iostream>
#include<cstdio>
const int maxn=410,mo=1e9+7;
typedef long long LL;
using namespace std;

int n,m,c;
inline void ck(LL&x){if(x>=mo)x-=mo;if(x<0)x+=mo;}
inline void ad(LL&x,LL y){x=x+y;ck(x);}
LL ans=0,fact[maxn],ifact[maxn];
inline LL exgcd(LL a,LL b,LL&x,LL&y){
	if(!b)return x=1,y=0,a;
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
inline LL inv(LL n,LL mo){
	LL x,y;
	if(exgcd(n,mo,x,y)>1)return 1;
	return x<0?x+mo:x;
}
inline LL C(int n,int m){
	if(m>n)return 0;
	return (LL)fact[n]*ifact[m]%mo*ifact[n-m]%mo;
}
inline LL power(LL base,LL exp,LL mo){
	LL ans=1;ck(base);
	while(exp){
		if(exp&1)ans=(LL)ans*base%mo;
		base=(LL)base*base%mo;
		exp>>=1;
	}
	return ans;
}
inline void pre(){
	fact[0]=ifact[0]=1;int t1=max(c,max(n,m));
	for(int i=1;i<=t1;++i)fact[i]=(LL)fact[i-1]*i%mo,ifact[i]=inv(fact[i],mo);
}
 
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d%d",&n,&m,&c);pre();
	for(int i=0,f1=(m&1)?-1:1;i<=n;++i,f1=-f1)for(int k=0,f2=1;k<=c;++k,f2=-f2)
	ad(ans,(LL)f1*f2*C(n,i)*C(c,k)%mo*power(1-power(c-k+1,n-i,mo),m,mo)%mo);
	printf("%lld",ans);
	return 0;
}
