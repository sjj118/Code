#include<cstdio>
#include<algorithm>
#include<cmath>
#include<complex>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10;
using std::swap;
using std::complex;
typedef double real;
const real pi=acos(-1);
inline real read(){double x;scanf("%lf",&x);return x;}
struct Complex{
	real x,y;
	Complex(){}
	Complex(real x,real y):x(x),y(y){}
	friend Complex operator+(const Complex&a,const Complex&b){return Complex(a.x+b.x,a.y+b.y);}
	friend Complex operator-(const Complex&a,const Complex&b){return Complex(a.x-b.x,a.y-b.y);}
	friend Complex operator*(const Complex&a,const Complex&b){return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
	void operator*=(const Complex&b){*this=(*this)*b;}
	void operator/=(int b){x/=b;y/=b;}
	void operator=(real a){x=a;y=0;}
};
namespace FFT{
	const int N=(1<<18)+10;
	int n,L,R[N];
	void init(int m){
		for(L=0,n=1;n<=m;n<<=1)++L;
		rep(i,0,n-1)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	}
	void fft(Complex*a,int f){
		rep(i,0,n-1)if(i<R[i])swap(a[i],a[R[i]]);
		for(int i=1;i<n;i<<=1){
			Complex wn(cos(pi/i),f*sin(pi/i));
			for(int j=0;j<n;j+=i<<1){
				Complex w(1,0);
				for(int k=0;k<i;++k,w*=wn){
					Complex x=a[j+k],y=w*a[j+k+i];
					a[j+k]=x+y;a[j+k+i]=x-y;
				}
			}
		}
		if(f==-1)rep(i,0,n-1)a[i]/=n;
	}
}
int n;
Complex a[FFT::N],b[FFT::N],c[FFT::N];
real e[N],q[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)q[i]=read();
	FFT::init(2*n);
	rep(i,1,n)a[i]=1.0/i/i;
	FFT::fft(a,1);

	rep(i,1,n)b[i]=q[i];
	FFT::fft(b,1);
	rep(i,0,FFT::n-1)c[i]=a[i]*b[i];
	FFT::fft(c,-1);
	rep(i,1,n)e[i]+=c[i].x;

	rep(i,0,FFT::n-1)b[i]=0;
	rep(i,1,n)b[i]=q[n-i+1];
	FFT::fft(b,1);
	rep(i,0,FFT::n-1)c[i]=a[i]*b[i];
	FFT::fft(c,-1);
	rep(i,1,n)e[n-i+1]-=c[i].x;

	rep(i,1,n)printf("%lf\n",e[i]);
	return 0;
}
