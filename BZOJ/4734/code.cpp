#include<iostream>
#include<cstdio>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int M=20000+10,mo=998244353;
inline void ck(LL&x,LL p){if(x>=p)x-=p;if(x<0)x+=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
int m;
LL n,x,a[M<<2],q[M<<2],C[2][M],p1[M],p2[M<<2],inv[M],fact[M],_fact[M];
LL _pr[M],*pr,sf[M],invpr[M],invsf[M];
namespace FFT{
	const int g=3,p=mo;
	int n,R[M<<2],L,_n;
	void init(int m){
		for(L=0,n=1;n<=m;n<<=1)++L;
		rep(i,0,n-1)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		_n=power(n,p-2,p);
	}
	void fft(LL*a,int f){
		rep(i,0,n-1)if(i<R[i])swap(a[i],a[R[i]]);
		for(int i=1;i<n;i<<=1){
			LL wn=power(g,p-1+f*(p-1)/i/2,p);
			for(int j=0;j<n;j+=i<<1){
				LL w=1;
				for(int k=0;k<i;++k,w=w*wn%p){
					LL x=a[j+k],y=w*a[j+k+i]%p;
					a[j+k]=x+y;a[j+k+i]=x-y;
					ck(a[j+k],p);ck(a[j+k+i],p);
				}
			}
		}
		if(f==-1)rep(i,0,n-1)a[i]=a[i]*_n%p;
	}
}
int main(){
	scanf("%lld%d%lld",&n,&m,&x);
	rep(i,0,m)scanf("%lld",&a[i]);
	inv[1]=1;rep(i,2,m)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	fact[0]=1;rep(i,1,m)fact[i]=fact[i-1]*i%mo;
	_fact[0]=1;rep(i,1,m)_fact[i]=_fact[i-1]*inv[i]%mo;
	p1[0]=1;rep(i,1,m)p1[i]=p1[i-1]*x%mo;
	p2[0]=1;rep(i,1,m)p2[i]=p2[i-1]*(mo+1-x)%mo;
	rep(i,0,m)p2[i]=p2[i]*_fact[i]%mo;
	rep(i,0,m)a[i]=a[i]*p1[i]%mo*_fact[i]%mo;
	FFT::init(m*2);
	FFT::fft(a,1);FFT::fft(p2,1);
	rep(i,0,FFT::n-1)q[i]=a[i]*p2[i]%mo;
	FFT::fft(q,-1);
	rep(i,0,m)q[i]=q[i]*fact[i]%mo;
	LL ans=0;
	pr=_pr+1;
	pr[-1]=1; rep(i,0,m)pr[i]=pr[i-1]*(n-i)%mo;
	sf[m+1]=1;per(i,m,0)sf[i]=sf[i+1]*(n-i)%mo;
	invpr[0]=1;rep(i,1,m)invpr[i]=invpr[i-1]*inv[i]%mo;
	rep(i,0,m){
		LL tmp=q[i]*pr[i-1]%mo*sf[i+1]%mo;
		tmp=tmp*invpr[i]%mo*invpr[m-i]%mo;
		if((m-i)&1)tmp=mo-tmp;
		ad(ans,tmp,mo);
	}
	printf("%lld",ans);
	return 0;
}
