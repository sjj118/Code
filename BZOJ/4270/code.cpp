#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
typedef long long LL;
inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
inline LL abs(LL x){return x>0?x:-x;}
LL solve(LL a,LL b,LL l,LL r){
	if(l==0)return 0;
	LL d=abs(gcd(a,b));
	if((l-1)/d>=r/d)return -1;
	if((l-1)/b<r/b)return (l-1)/b+1;
	LL x=solve(b,a%b,b-1-(r-1)%b,b-1-(l-1)%b);
	if(x<0)return -1;
	l+=a*x;r+=a*x;
	return (l-1)/b+1;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		LL m,d,l,r;scanf("%lld%lld%lld%lld",&m,&d,&l,&r);
		if(r>=m)r=m-1;
		printf("%lld\n",solve(m,d,l,r));
	}
	return 0;
}
