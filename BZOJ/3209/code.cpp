#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
#define mo 10000007
#define phi 9988440
 
using namespace std;
 
ll n,len;
ll C[60][60];
void getC(){
	C[0][0]=1;
	for(int i=1;i<60;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%phi;
	}
}
ll power(ll base,ll exp,ll mode=1){
	ll ans=1;
	while(exp){
		if(exp&1)ans*=base;
		base*=base;
		if(mode)ans%=mo,base%=mo;
		exp>>=1;
	}
	return ans;
}
 
int a[60];
ll F(ll k){
	ll ans=0;
	for(ll i=len;i>=1;--i){
		if(a[i]){
			ans=(ans+C[i-1][k])%phi;
			--k;
		}
		if(k<0)return ans;
	}
	return ans;
}
 
int main(){
	getC();
	scanf("%lld",&n);
	++n;
	ll ans=1;
	while(n)a[++len]=n&1,n>>=1;
	for(int i=1;i<=len;++i)
	ans=ans*power(i,F(i))%mo;
	printf("%lld",ans);
	return 0;
}
