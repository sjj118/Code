#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int inf=1e9,maxn=2000000+10,mo=985661441;
const double eps=1e-8;
using namespace std;
inline char gc(){char c=getchar();while(!(c=='-'||c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0,f=1;char c=gc();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp*f;}
inline LL ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;return x;}
inline LL ad(LL&x,LL y,LL p){return ck(x+=y,p);}
inline void up(LL&x,LL y){if(y>x)x=y;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
inline LL gcd(LL a,LL b){if(!b)return a;return gcd(b,a%b);}
inline LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
inline LL sqr(LL x){return x*x;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;x=x*x%p,y>>=1)if(y&1)a=a*x%p;return a;}
inline LL multi(LL x,LL y,LL p){LL a=0;for(;y;x=x*2%p,y>>=1)if(y&1)a=(a+x)%p;return a;}
inline LL exgcd(LL a,LL b,LL&x,LL&y){if(!b)return x=1,y=0,a;LL d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
inline LL inv(LL n,LL p){LL x,y;if(exgcd(n,p,x,y)>1)cerr<<"NO_REV"<<endl;return ck(x,p);}
/*ÏßÐÔÉ¸
int tot,prime[maxn],miu[maxn],phi[maxn];
bool s[maxn];
void sieve(){
	miu[1]=phi[1]=1;
	rep(i,2,maxn-1){
		if(!s[i])prime[++tot]=i,miu[i]=-1,phi[i]=i-1;
		for(int j=1;j<=tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				miu[i*prime[j]]=-miu[i];
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}else{
				miu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
		}
	}
}
//*/
int n,k;
LL ans,fact[maxn],_fact[maxn],Inv[maxn];
inline LL C(LL n,LL m){
	if(m>n)return 0;
	return fact[n]*_fact[m]%mo*_fact[n-m]%mo;
}

int main(){
	Inv[1]=1;rep(i,2,maxn-1)Inv[i]=-mo/i*Inv[mo%i]%mo,ck(Inv[i],mo);
	fact[0]=1;rep(i,1,maxn-1)fact[i]=fact[i-1]*i%mo;
	_fact[0]=1;rep(i,1,maxn-1)_fact[i]=_fact[i-1]*Inv[i]%mo;
	int T;scanf("%d",&T);
	rep(cas,1,T){
		n=read();k=read();ans=0;
		if(k==1){
			ans=1;
		}else if(k==2){
			rep(i,0,n)ad(ans,C(n,i)*power(i,n-i,mo)%mo,mo);
		}else{
			
		}
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}

