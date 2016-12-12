#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
#define ls (k<<1)
#define rs (k<<1|1)
using namespace std;
typedef long long LL;
const int N=1e6+10;
int n,p,size[N];
LL f[N],fact[N],_fact[N],inv[N];
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
LL C(LL n,LL m){
	if(m>n)return 0;
	if(n<p)return fact[n]*_fact[m]%p*_fact[n-m]%p;
	return C(n%p,m%p)*C(n/p,m/p)%p;
}
int main(){
	scanf("%d%d",&n,&p);
	int fr=min(n,p-1);
	inv[1]=1;rep(i,2,fr)inv[i]=-p/i*inv[p%i]%p,ck(inv[i],p);
	fact[0]=1;rep(i,1,fr)fact[i]=fact[i-1]*i%p;
	_fact[0]=1;rep(i,1,fr)_fact[i]=_fact[i-1]*inv[i]%p;
	per(k,n,1){
		size[k]=1;
		if(ls<=n)size[k]+=size[ls];
		if(rs<=n)size[k]+=size[rs];
		if(rs>n)f[k]=1;
		else f[k]=C(size[k]-1,size[ls])*f[ls]%p*f[rs]%p;
	}
	printf("%lld",f[1]);
	return 0;
}
