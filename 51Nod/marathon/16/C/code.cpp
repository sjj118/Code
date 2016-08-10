#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const LL inf=1e9,maxn=1000000+10,mo=1000000007,maxm=20;
const double eps=1e-8;
using namespace std;
inline char gc(){char c=getchar();while(!(c=='-'||c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0,f=1;char c=gc();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp*f;}
inline LL ck(LL&x,LL p){while(x<0)x+=p;while(x>=p)x-=p;return x;}
inline LL ad(LL&x,LL y,LL p){return ck(x+=y,p);}
inline void up(LL&x,LL y){if(y>x)x=y;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
inline LL gcd(LL a,LL b){if(!b)return a;return gcd(b,a%b);}
inline LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
inline LL sqr(LL x){return x*x;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;x=x*x%p,y>>=1)if(y&1)a=a*x%p;return a;}
inline LL exgcd(LL a,LL b,LL&x,LL&y){if(!b)return x=1,y=0,a;LL d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
inline LL inv(LL n,LL p){LL x,y;if(exgcd(n,p,x,y)>1)cerr<<"NO_REV"<<endl;return ck(x,p);}
int n,m,d[maxm],u[maxm],mark[maxn],sel[maxm],f=1;
LL ans,fact[maxn],_fact[maxn],_inv[maxn];
void dfs(int k){
	if(k==m+1){
		int x=n-2,tt=0;LL tmp=fact[x];
		rep(i,1,m)if(sel[i])x-=d[i]-1,tmp=tmp*_fact[d[i]-1]%mo,++tt;
		if(x>=0)tmp=tmp*_fact[x]%mo,tmp=tmp*power(n-tt,x,mo)%mo;else tmp=0;
		ad(ans,f*tmp,mo);
		return;
	}
	dfs(k+1);
	if(!mark[u[k]]){
		mark[u[k]]=1;sel[k]=1;f=-f;
		dfs(k+1);
		mark[u[k]]=0;sel[k]=0;f=-f;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	fact[0]=1;rep(i,1,n)fact[i]=fact[i-1]*i%mo;
	_inv[1]=1;rep(i,2,n)_inv[i]=-mo/i*_inv[mo%i]%mo,ck(_inv[i],mo);
	_fact[0]=1;rep(i,1,n)_fact[i]=_fact[i-1]*_inv[i]%mo;
	rep(i,1,m)scanf("%d%d",&u[i],&d[i]);
	if(n==1){puts("1");return 0;}
	dfs(1);printf("%lld",ans);
	return 0;
}

