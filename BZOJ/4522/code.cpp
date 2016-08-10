#include<iostream>
#include<cstdio>
#include<stdlib.h>
#define LL long long

using namespace std;

LL e,n,c,p,q,r,d;
LL abs(LL x){if(x<0)x=-x;return x;}
LL exgcd(LL a,LL b,LL&x,LL&y){
	if(!b){
		x=1;y=0;
		return a;
	}
	LL d=exgcd(b,a%b,x,y);
	LL t=x;x=y;y=t-a/b*y;
	return d;
}
LL gcd(LL a,LL b){
	if(!b)return a;
	return gcd(b,a%b);
}
LL mul(LL a,LL b,LL mo){
	LL ans=0;
	while(b){
		if(b&1)ans=(ans+a)%mo;
		a=(a*2)%mo;
		b/=2;
	}
	return ans;
}
LL b;
LL f(LL x){return (mul(x,x,n)+b)%n;}
LL rho(LL n){
	LL x=1,y=1,p=1;
	while(p==1){
		x=f(x);y=f(f(y));
		p=gcd(abs(x-y),n);
	}
	return p;
}
LL power(LL base,LL exp,LL mo){
	LL ans=1;
	while(exp){
		if(exp&1)ans=mul(ans,base,mo);
		base=mul(base,base,mo);
		exp/=2;
	}
	return ans;
}

int main(){
	scanf("%lld%lld%lld",&e,&n,&c);
	b=10007;
	do{
		p=rho(n);
		--b;
	}while(p==n);
	q=n/p;
	r=(p-1)*(q-1);
	LL t;
	exgcd(e,r,d,t);
	d=(d%r+r)%r;
	printf("%lld %lld",d,power(c,d,n));
	return 0;
}
