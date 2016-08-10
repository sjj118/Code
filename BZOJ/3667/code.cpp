#include<iostream>
#include<cstdio>
#include<stdlib.h>
#define LL long long

using namespace std;

const LL prime[9]={2,3,5,7,11,13,17,19,23};
LL readint(){
	LL tmp=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}
LL abs(LL x){if(x<0)x=-x;return x;}
LL gcd(LL a,LL b){
	if(!b)return a;
	return gcd(b,a%b);
}
LL mul(LL a,LL b,LL p){
    LL tmp=(a*b-(LL)((long double)a/p*b+1e-8)*p);
    return tmp<0?tmp+p:tmp;
}
LL power(LL base,LL exp,LL mo){
	LL ans=1;
	while(exp){
		if(exp&1)ans=mul(ans,base,mo);
		base=mul(base,base,mo);
		exp>>=1;
	}
	return ans;
}
bool MR(LL n){
	if(n<=1)return 0;
	LL u=n-1,t=0;
	while((u&1)==0)u>>=1,++t;
	for(LL i=0;i<9;++i){
		if(n==prime[i])return 1;
		LL x=power(prime[i],u,n);
		for(LL last=x,tmp=1;tmp<=t;++tmp,last=x){
			x=mul(x,x,n);
			if(x==1&&last!=1&&last!=n-1)return 0;
		}
		if(x!=1)return 0;
	}
	return 1;
}
LL rho(LL n){
	LL b,x,y,p=n;
	while(p==n){
		x=y=rand()%n;p=1;b=rand()%(n-1)+1;
		for(LL i=1,k=2;p==1;++i){
			x=(mul(x,x,n)+b)%n;
			p=gcd(abs(x-y),n);
			if(i==k)k<<=1,y=x;
		}
	}
	return p;
}
LL solve(LL n){
	if(n==1||MR(n))return n;
	LL p=rho(n);
	LL ans=max(solve(p),solve(n/p));
	return ans;
}

int main(){
	int T=readint();
	while(T--){
		LL n=readint();
		if(MR(n))printf("Prime\n");
		else printf("%lld\n",solve(n));
	}
	return 0;
}
