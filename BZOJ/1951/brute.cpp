#include<iostream>
#include<cstdlib> 
#define ll long long
#define mo 999911659
#define mmo 999911658

using namespace std;

int n,g;

ll fact(ll n){
	ll ans=1;
	for(int i=1;i<=n;++i)ans=ans*i;
	return ans;
}
ll power(ll base,ll exp,ll p){
	ll ans=1;
	while(exp){
		if(exp&1)ans=ans*base%p;
		base=base*base%p;
		exp>>=1;
	}
	return ans;
}
ll C(ll m,ll n,ll p){
	return fact(m)/fact(n)/fact(m-n)%p;
}

int main(){
	freopen("code.in","r",stdin);
	freopen("brute.out","w",stdout);
	scanf("%d%d",&n,&g);
	ll ans=0;
	for(int i=1;i<=n;++i)if(n%i==0)ans=(ans+C(n,i,mmo))%mmo;
	cout<<ans;
	//printf("%lld",power(g,ans,mo));
	return 0;
}
