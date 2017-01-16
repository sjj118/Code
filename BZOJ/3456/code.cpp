#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=270000,mo=479*(1<<21)+1;
inline void ck(LL&x,LL p){if(x>=p)x-=p;if(x<0)x+=p;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
int n;
LL inv[N],fact[N],_fact[N];
struct Polynomial{
	LL a[N];
	int n;
	Polynomial(){}
	LL&operator[](int x){return a[x];}
	LL operator[](int x)const{return a[x];}
	void fft(int deg,int f){
		static int R[N];
		int L=0,oldn=n;
		for(n=1;n<deg;n<<=1)++L;
		rep(i,oldn,n-1)a[i]=0;
		rep(i,0,n-1)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		rep(i,0,n-1)if(i<R[i])swap(a[i],a[R[i]]);
		for(int i=1;i<n;i<<=1){
			LL wn=power(3,mo-1+f*(mo-1)/i/2,mo);
			for(int j=0;j<n;j+=(i<<1)){
				LL w=1;
				for(int k=0;k<i;++k,w=w*wn%mo){
					LL x=a[j+k],y=a[j+k+i]*w%mo;
					a[j+k]=(x+y)%mo;a[j+k+i]=(mo+x-y)%mo;
				}
			}
		}
		if(f==-1)rep(i,0,n-1)a[i]=a[i]*inv[n]%mo;
	}
	void inverse(Polynomial&b,int deg){
		if(deg==1){b.n=1;b[0]=power(a[0],mo-2,mo);return;}
		inverse(b,(1+deg)>>1);
		static Polynomial tmp;
		tmp.n=deg;rep(i,0,deg-1)tmp[i]=a[i];
		tmp.fft(deg<<1,1);
		b.fft(deg<<1,1);
		rep(i,0,tmp.n-1)tmp[i]=tmp[i]*b[i]%mo;
		rep(i,0,tmp.n-1)tmp[i]=(mo+2-tmp[i])%mo;
		rep(i,0,tmp.n-1)b[i]=b[i]*tmp[i]%mo;
		b.fft(deg<<1,-1);b.n=deg;
	}
	Polynomial inverse(){
		static Polynomial ret;
		inverse(ret,n);
		return ret;
	}
}b,c,_c;
int main(){
	inv[1]=1;rep(i,2,N-1)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	fact[0]=1;rep(i,1,N-1)fact[i]=fact[i-1]*i%mo;
	_fact[0]=1;rep(i,1,N-1)_fact[i]=_fact[i-1]*inv[i]%mo;
	scanf("%d",&n);
	b.n=c.n=n+1;
	rep(i,1,n)b[i]=power(2,(LL)i*(i-1)/2,mo)*_fact[i-1]%mo;
	rep(i,0,n)c[i]=power(2,(LL)i*(i-1)/2,mo)*_fact[i]%mo;
	_c=c.inverse();
	LL ans=0;
	rep(i,0,n)(ans+=b[i]*_c[n-i]%mo)%=mo;
	printf("%lld",ans*fact[n-1]%mo);
	return 0;
}
