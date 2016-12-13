#include<iostream>
#include<cstdio>
#include<assert.h>
#include<cstring>
#include<cmath>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
inline void ck(LL&x,LL p){if(x>=p)x-=p;if(x<0)x+=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL exgcd(LL a,LL b,LL&x,LL&y){
	if(!b)return x=1,y=0,a;
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
LL inv(LL n,LL p){
	LL x,y;
	assert(exgcd(n,p,x,y)==1);
	ck(x,p);return x;
}
LL getphi(LL p){
	LL ret=p;
	for(LL i=2;i*i<=p;++i)if(p%i==0){
		ret=ret/i*(i-1);
		while(p%i==0)p/=i;
	}
	if(p>1)ret=ret/p*(p-1);
	return ret;
}
const int ha=233333,N=1e5;
struct Hash{
	int tot,head[ha],next[N],key[N],val[N];
	void ins(int a,int b){key[++tot]=a;a%=ha;next[tot]=head[a];head[a]=tot;val[tot]=b;}
	int find(int a){for(int p=head[a%ha];p;p=next[p])if(key[p]==a)return val[p];return -1;}
	void clear(){tot=0;cls(head);}
}hash;
LL BSGS(LL a,LL b,LL p){
	hash.clear();
	LL pp=getphi(p);
	LL L=round(sqrt(pp));
	LL _a=inv(a,p),pl=power(a,L,p),_pl=inv(pl,p),_pa=1;
	per(i,L-1,0)pl=pl*_a%p,hash.ins(pl,i);
	for(LL i=0;i*L<pp;++i){
		int t=hash.find(b*_pa%p);
		if(t>=0)return i*L+t;
		_pa=_pa*_pl%p;
	}
	return -1;
}
LL exBSGS(LL a,LL b,LL p){
	LL d=gcd(a,p),g=0,t=1;
	while(d>1){
		if(t==b)return g;
		if(b%d)return -1;
		b/=d;p/=d;
		++g;t=t*a/d%p;
		d=gcd(a,p);
	}
	LL ret=BSGS(a,b*inv(t,p)%p,p);
	if(ret==-1)return ret;
	return ret+g;
}
const int P=20;
int tot,prime[P],cnt[P],mod[P];
void get_factor(LL p){
	tot=0;
	for(LL i=2;i*i<=p;++i)if(p%i==0){
		prime[++tot]=i;cnt[tot]=0;mod[tot]=1;
		while(p%i==0)++cnt[tot],mod[tot]*=i,p/=i;
	}
	if(p>1)cnt[++tot]=1,prime[tot]=mod[tot]=p;
}
void factor(int k,LL n,LL&t,LL&u){
	if(n==0)return;
	if(n>=mod[k]){
		LL tt=1;
		rep(i,1,mod[k])if(i%prime[k])tt=tt*i%mod[k];
		t=t*power(tt,n/mod[k],mod[k])%mod[k];
	}
	u+=n/prime[k];
	per(i,n%mod[k],1)if(i%prime[k])t=t*i%mod[k];
	factor(k,n/prime[k],t,u);
}
LL calc(int k,LL n,LL m){
	LL t1,t2,t3,u1,u2,u3;t1=t2=t3=1;u1=u2=u3=0;
	factor(k,n,t1,u1);factor(k,m,t2,u2);factor(k,n-m,t3,u3);
	assert(u1>=u2+u3);
	return t1*inv(t2,mod[k])%mod[k]*inv(t3,mod[k])%mod[k]*power(prime[k],u1-u2-u3,mod[k])%mod[k];
}
LL C(LL n,LL m,LL p){
	if(m>n)return 0;
	LL ret=0;
	rep(i,1,tot){
		ad(ret,p/mod[i]*inv(p/mod[i],mod[i])%p*calc(i,n,m)%p,p);
	}
	return ret;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int op,y,z,p;scanf("%d%d%d%d",&op,&y,&z,&p);
		if(op==1){
			printf("%lld\n",power(y,z,p));
		}else if(op==2){
			LL ans=exBSGS(y,z,p);
			if(ans==-1)puts("Math Error");else printf("%lld\n",ans);
		}else{
			get_factor(p);
			printf("%lld\n",C(z,y,p));
		}
	}
	return 0;
}
