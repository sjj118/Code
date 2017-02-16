#include<iostream>
#include<algorithm>
#include<cstdio>
#include<assert.h>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::swap;
using std::min;
using std::reverse;
using std::max;
using std::cin;
typedef long long LL;
const int P=65536+10,LEN=120,mo=998244353;
const LL inf=1e18;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline void up(int&x,int y){if(y>x)x=y;}
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline LL inverse(LL n,LL p){return power(n,p-2,p);}
LL p,fact[P],ans[P],inv[P],_fact[P];
LL g,ind[P],pw[P];
namespace FFT{
	int R[P],L,n;
	const int fft_g=3;
	void init(int m){
		for(n=1;n<m;n<<=1)++L;
		rep(i,0,n-1)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	}
	void fft(LL*a,int f){
		rep(i,0,n-1)if(R[i]<i)swap(a[i],a[R[i]]);
		for(int i=1;i<n;i<<=1){
			LL wn=power(fft_g,mo-1+f*(mo-1)/i/2,mo);
			for(int j=0;j<n;j+=(i<<1)){
				LL w=1;
				for(int k=0;k<i;++k,w=w*wn%mo){
					LL x=a[j+k],y=w*a[j+k+i]%mo;
					a[j+k]=(x+y)%mo;a[j+k+i]=(mo+x-y)%mo;
				}
			}
		}
		LL inn=inverse(n,mo);
		if(f==-1)rep(i,0,n-1)a[i]=a[i]*inn%mo;
	}
}
struct BigNum{
	int deg,val[LEN];
	void input(){
		char c=gc();
		deg=1;
		while(vaild(c)){
			rep(i,1,deg)val[i]=val[i]*10;
			val[1]+=c-'0';
			rep(i,1,deg){
				val[i+1]+=val[i]/p;
				val[i]%=p;
				if(i==deg&&val[i+1])++deg;
			}
			c=getchar();
		}
		while(deg&&val[deg]==0)--deg;
	}
	friend BigNum operator-(const BigNum&a,int b){
		BigNum ret=a;
		ret.val[1]-=b;
		int q=1;
		while(ret.val[q]<0){
			ret.val[q]+=p;
			--ret.val[q+1];
			++q;
		}
		while(ret.deg&&ret.val[ret.deg]==0)--ret.deg;
		return ret;
	}
};
BigNum n,l,r;
inline LL C(LL n,LL m){
	if(m>n)return 0;
	return fact[n]*_fact[m]%p*_fact[n-m]%p;
}
LL dp[LEN][2][P],num[3][P];
void calc(BigNum x,int fu){
	up(x.deg,n.deg);
	if(x.deg==0){
		--ans[0];
		return;
	}
	cls(dp);
	dp[x.deg+1][1][ind[1]]=1;
	per(i,x.deg,1){
		cls(num);
		rep(k,0,p-1)++num[0][ind[C(k,n.val[i])]];
		rep(k,0,x.val[i]-1)++num[1][ind[C(k,n.val[i])]];
		++num[2][ind[C(x.val[i],n.val[i])]];

		LL zero[2];zero[0]=zero[1]=0;

		rep(j,0,p-1)ad(zero[0],num[0][p-1]*dp[i+1][0][j]%mo,mo);
		rep(j,0,p-2)ad(zero[0],num[0][j]*dp[i+1][0][p-1]%mo,mo);
		rep(j,0,p-1)ad(zero[0],num[1][p-1]*dp[i+1][1][j]%mo,mo);
		rep(j,0,p-2)ad(zero[0],num[1][j]*dp[i+1][1][p-1]%mo,mo);
		rep(j,0,p-1)ad(zero[1],num[2][p-1]*dp[i+1][1][j]%mo,mo);
		rep(j,0,p-2)ad(zero[1],num[2][j]*dp[i+1][1][p-1]%mo,mo);

		num[0][p-1]=num[1][p-1]=num[2][p-1]=0;
		dp[i+1][0][p-1]=dp[i+1][1][p-1]=0;

		//rep(j,0,p-2)rep(k,0,p-2)ad(dp[i][0][(j+k)%(p-1)],dp[i+1][0][j]*num[0][k]%mo,mo);
		//rep(j,0,p-2)rep(k,0,p-2)ad(dp[i][0][(j+k)%(p-1)],dp[i+1][1][j]*num[1][k]%mo,mo);
		//rep(j,0,p-2)rep(k,0,p-2)ad(dp[i][1][(j+k)%(p-1)],dp[i+1][1][j]*num[2][k]%mo,mo);

		FFT::fft(dp[i][0],1);FFT::fft(dp[i][1],1);
		FFT::fft(dp[i+1][0],1);FFT::fft(dp[i+1][1],1);
		FFT::fft(num[0],1);FFT::fft(num[1],1);FFT::fft(num[2],1);
		rep(j,0,FFT::n-1)ad(dp[i][0][j],dp[i+1][0][j]*num[0][j]%mo,mo);
		rep(j,0,FFT::n-1)ad(dp[i][0][j],dp[i+1][1][j]*num[1][j]%mo,mo);
		rep(j,0,FFT::n-1)ad(dp[i][1][j],dp[i+1][1][j]*num[2][j]%mo,mo);
		FFT::fft(dp[i][0],-1);FFT::fft(dp[i][1],-1);
		rep(j,p-1,FFT::n)ad(dp[i][0][j-(p-1)],dp[i][0][j]%mo,mo),dp[i][0][j]=0;
		rep(j,p-1,FFT::n)ad(dp[i][1][j-(p-1)],dp[i][1][j]%mo,mo),dp[i][1][j]=0;

		dp[i][0][p-1]=zero[0];dp[i][1][p-1]=zero[1];
	}
	rep(i,0,p-1)ad(ans[i],fu*(dp[1][0][ind[i]]+dp[1][1][ind[i]])%mo,mo);
}
int main(){
	scanf("%lld",&p);
	FFT::init(2*p);
	fact[0]=1;rep(i,1,p-1)fact[i]=fact[i-1]*i%p;
	inv[1]=1;rep(i,2,p-1)inv[i]=p-p/i*inv[p%i]%p;
	_fact[0]=1;rep(i,1,p-1)_fact[i]=_fact[i-1]*inv[i]%p;
	for(g=1;g<p;++g){
		bool flag=1;
		LL x=1;
		rep(i,1,p-2){
			x=x*g%p;
			if(x==1){
				flag=0;
				break;
			}
		}
		if(flag)break;
	}
	ind[pw[0]=1]=0;rep(i,1,p-2)pw[i]=pw[i-1]*g%p,ind[pw[i]]=i;
	ind[0]=p-1;
	n.input();
	l.input();
	r.input();
	calc(r,1);
	if(l.deg)calc(l-1,-1);
	rep(i,0,p-1)printf("%lld\n",ans[i]);
	return 0;
}
