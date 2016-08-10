#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const LL inf=1e9,maxn=20,mo=1e9+7,maxmi=1e7;
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
int n;
LL k,p[maxn],s[maxn][maxn],m,middle;
LL minDelta=inf;
int sel[maxn],asel[maxn];
void dfs(int k,LL mul){
	if(k==n+1){
		if(mul>=middle&&mul-middle<minDelta){
			minDelta=mul-middle;
			memcpy(asel,sel,sizeof(sel));
		}
		return;
	}
	dfs(k+1,mul);
	sel[k]=1;dfs(k+1,mul*s[k][0]);
	sel[k]=0;
}
LL a[maxmi],b[maxmi];
int ta,tb;
void dfa(int k,LL sum){
	if(!asel[k]){
		a[++ta]=sum;
		return;
	}
	rep(i,1,s[k][0])dfa(k+1,(sum+s[k][i])%m);
}
void dfb(int k,LL sum){
	if(asel[k]){
		b[++tb]=sum;
		return;
	}
	rep(i,1,s[k][0])dfb(k-1,(sum+s[k][i])%m);
}
int main(){
	scanf("%d%lld",&n,&k);
	int tmp=0;
	rep(i,1,n){
		LL x=read(),y=read();
		if(y==1)read();
		else{
			p[++tmp]=y;
			s[tmp][0]=x;
			rep(j,1,x)s[tmp][j]=read();
		}
	}
	n=tmp;m=1;
	rep(i,1,n)m=m*p[i];
	middle=1;
	rep(i,1,n)middle*=s[i][0];
	LL ans=(k-1)/middle%mo*(m%mo)%mo;k=(k-1)%middle+1;
	middle=floor(sqrt(middle));
	dfs(1,1);
	for(int i=1,j=n;i<j;++i,--j){
		while(i<j&&asel[i])++i;
		while(i<j&&!asel[j])--j;
		swap(asel[i],asel[j]);swap(s[i],s[j]);swap(p[i],p[j]);
	}
	rep(i,1,n)rep(j,1,s[i][0])s[i][j]=multi(multi(s[i][j],(m/p[i]),m),inv((m/p[i])%p[i],p[i]),m);
	dfa(1,0);dfb(n,0);
	sort(a+1,a+1+ta);sort(b+1,b+1+tb);
	LL l=0,r=m-1;
	while(l<r){
		LL mid=(l+r)>>1,tmp=0;
		for(int i=1,j=tb,q=tb+1,p=tb;i<=ta;++i){
			while(j&&a[i]+b[j]>mid)--j;
			tmp+=j;
			while(q>1&&a[i]+b[q-1]>=m)--q;
			while(p&&a[i]+b[p]>m+mid)--p;
			tmp+=p-q+1;
		}
		if(tmp<k)l=mid+1;else r=mid;
	}
	printf("%lld",(ans+l%mo)%mo);
	return 0;
}

