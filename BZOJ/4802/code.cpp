#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const int tot_pri=8,pri[tot_pri]={2,3,5,7,11,13,17,19};
inline LL multi(LL x,LL y,LL p){LL a=0;for(;y;y>>=1,x=x*2%p)if(y&1)a=(a+x)%p;return a;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=multi(x,x,p))if(y&1)a=multi(a,x,p);return a;}
inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
bool isPrime(LL p){
	if(p==1)return 1;
	rep(id_a,0,tot_pri-1){
		LL a=pri[id_a],u=p-1,t=0;
		if(a==p)return 1;
		while((u&1)==0)u>>=1,++t;
		a=power(a,u,p);
		rep(i,1,t){
			LL pre=a;
			a=multi(a,a,p);
			if(a==1&&pre!=1&&pre!=p-1)return 0;
		}
		if(a!=1)return 0;
	}
	return 1;
}
LL getNext(LL x,LL p){return multi(x+3,x+5,p);}
LL getFactor(LL n){
	LL d=n;
	while(d==n){
		LL x=rand(),y=getNext(x,n);
		while(gcd(n,std::abs(x-y))==1)x=getNext(x,n),y=getNext(getNext(y,n),n);
		d=gcd(n,std::abs(x-y));
	}
	return d;
}
LL phi(LL n){
	LL ret=n;
	while(!isPrime(n)){
		LL p=getFactor(n);
		ret=ret/p*(p-1);
		while(n%p==0)n/=p;
	}
	if(n>1)ret=ret/n*(n-1);
	return ret;
}
int main(){
	srand(20000107);
	LL n;scanf("%lld",&n);
	printf("%lld",phi(n));
	return 0;
}
