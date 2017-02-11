#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=40+5,M=40*100000+10,mo=998244353;
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
int n,w[N],m;
LL fact[M],inv[M],_fact[M],dp[2][M];
inline LL A(LL n,LL m){
	if(m>n)return 0;
	return fact[n]*_fact[n-m]%mo;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&w[i]),m+=w[i];
	rep(i,1,n){
		per(j,m-w[i]-1,0){
			if(dp[0][j])dp[1][j+w[i]+1]+=dp[0][j];
			if(dp[1][j])dp[0][j+w[i]+1]+=dp[1][j];
		}
	}
	dp[0][1]=1;
	fact[0]=1;rep(i,1,m)fact[i]=fact[i-1]*i%mo;
	inv[1]=1;rep(i,2,m)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	_fact[0]=1;rep(i,1,m)_fact[i]=_fact[i-1]*inv[i]%mo;
	LL ans=fact[m];
	rep(i,0,m){
		if(dp[0][i])ad(ans,-dp[0][i]*fact[i]%mo*fact[m-i]%mo,mo);
		if(dp[1][i])ad(ans,dp[1][i]*fact[i]%mo*fact[m-i]%mo,mo);
	}
	printf("%lld",ans);
	return 0;
}
