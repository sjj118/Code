#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
#define mo 999911659
#define mmo 999911658

using namespace std;


const int p[4]={2,3,4679,35617};
ll m[4];
int n,g;
ll fact[40000];
void getfact(int n=40000){
	fact[0]=1;
	for(int i=1;i<n;++i){
		fact[i]=fact[i-1]*i%mmo;
	}
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
	if(m<n)return 0;
	return fact[m]*power(fact[n],p-2,p)%p*power(fact[m-n],p-2,p)%p;
}
ll lucas(ll m,ll n,ll p){
	ll ans=1;
	while(n){
		ans=ans*C(m%p,n%p,p)%p;
		m/=p;n/=p;
	}
	return ans;
}
ll get(int p){
	ll ans=0;
	int h=floor(sqrt(n));
	for(int i=1;i<=h;++i)if(n%i==0){
		ans=(ans+lucas(n,i,p))%p;
		if(i*i!=n)ans=(ans+lucas(n,n/i,p))%p;
	}
	return ans;
}
ll getans(){
	ll ans=0;
	for(int i=0;i<4;++i){
		ans=(ans+power(mmo/p[i],p[i]-1,mmo)*m[i])%mmo;
	}
	return ans;
}

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	getfact();
	scanf("%d%d",&n,&g);
	if(g==mo){
		printf("%d",0);
		return 0;
	}
	for(int i=0;i<4;++i)m[i]=get(p[i]);
	printf("%d",int(power(g,getans(),mo)));
	return 0;
} 
