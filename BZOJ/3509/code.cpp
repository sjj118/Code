#include<iostream>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
using std::swap;
using std::max;
using std::min;
typedef double real;
struct Complex{
	real x,y;
	Complex(){}
	Complex(real x,real y):x(x),y(y){}
	friend Complex operator+(const Complex&a,const Complex&b){return Complex(a.x+b.x,a.y+b.y);}
	friend Complex operator-(const Complex&a,const Complex&b){return Complex(a.x-b.x,a.y-b.y);}
	friend Complex operator*(const Complex&a,const Complex&b){return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
	void operator/=(int b){x/=b;y/=b;}
	void operator=(int a){x=a;y=0;}
};
inline void up(int&x,int y){if(y>x)x=y;}
const real pi=acos(-1);
const int N=1e5+10,M=66000;
int n,a[N],pr[M],sf[M],m,B=3000;
LL ans=0;
Complex f1[M],f2[M];
namespace FFT{
	int n,L,R[M];
	void init(int m){
		for(L=0,n=1;n<=m;n<<=1)++L;
		rep(i,0,n-1)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	}
	void fft(Complex*a,int f){
		rep(i,0,n-1)if(R[i]<i)swap(a[i],a[R[i]]);
		for(int i=1;i<n;i<<=1){
			Complex wn(cos(pi/i),f*sin(pi/i));
			for(int j=0;j<n;j+=i<<1){
				Complex w(1,0);
				for(int k=0;k<i;++k,w=w*wn){
					Complex x=a[j+k],y=w*a[j+k+i];
					a[j+k]=x+y;a[j+k+i]=x-y;
				}
			}
		}
		if(f==-1)rep(i,0,n-1)a[i]/=n;
	}
};
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),up(m,a[i]);
	B=ceil(sqrt(m*log(m)/log(2)))*4;
	FFT::init(2*m);
	rep(i,1,n)++sf[a[i]];
	int r1=n/B;rep(i,0,r1){
		int r2=min(n,i*B+B-1);rep(j,max(i*B,1),r2)--sf[a[j]];
		rep(j,0,FFT::n-1)f1[j]=pr[j];
		rep(j,0,FFT::n-1)f2[j]=sf[j];
		FFT::fft(f1,1);FFT::fft(f2,1);
		rep(j,0,FFT::n-1)f1[j]=f1[j]*f2[j];
		FFT::fft(f1,-1);
		r2=min(i*B+B-1,n);rep(j,max(1,i*B),r2)ans+=f1[a[j]*2].x+0.5;
		rep(j,max(1,i*B),r2){
			rep(k,j+1,r2){
				if(2*a[j]-a[k]>=0)ans+=pr[2*a[j]-a[k]];
			}
			++pr[a[j]];
		}
		r2=max(1,i*B);per(j,min(i*B+B-1,n),r2){
			per(k,j-1,r2){
				if(2*a[j]-a[k]>=0)ans+=sf[2*a[j]-a[k]];
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
