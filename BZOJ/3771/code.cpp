#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
using std::swap;
const int N=132000,mo=998244353;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){char c=gc();int ret=0;while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
inline int power(LL x,int y,int p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline void ck(int&x,int p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(int&x,int y,int p){x+=y;ck(x,p);}
const int _2=power(2,mo-2,mo),_6=power(6,mo-2,mo);
int n,a[N];
int x[N],y[N],z[N],t[N];
namespace FFT{
	int n,L,R[N],_n;
	void init(int m){
		for(L=0,n=1;n<=m;n<<=1)++L;
		rep(i,0,n-1)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		_n=power(n,mo-2,mo);
	}
	void work(int*a,int f){
		rep(i,0,n-1)if(R[i]<i)swap(a[i],a[R[i]]);
		for(int i=1;i<n;i<<=1){
			int wn=power(3,mo-1+f*(mo-1)/i/2,mo);
			for(int j=0;j<n;j+=i<<1){
				int w=1;
				for(int k=0;k<i;++k,w=(LL)w*wn%mo){
					int x=a[j+k],y=(LL)w*a[j+k+i]%mo;
					a[j+k]=x+y;a[j+k+i]=x-y;ck(a[j+k],mo);ck(a[j+k+i],mo);
				}
			}
		}
		if(f==-1)rep(i,0,n-1)a[i]=(LL)a[i]*_n%mo;
	}
};
int main(){
	scanf("%d",&n);
	FFT::init(3*40000);
	rep(i,1,n)a[i]=read();
	rep(i,1,n)x[a[i]]=1,y[2*a[i]]=1,z[3*a[i]]=1;
	FFT::work(x,1);FFT::work(y,1);FFT::work(z,1);
	rep(i,0,FFT::n-1)t[i]=(x[i]+((LL)x[i]*x[i]%mo-y[i])*_2%mo+((LL)x[i]*x[i]%mo*x[i]%mo-3ll*x[i]*y[i]%mo+2*z[i])*_6%mo)%mo,ck(t[i],mo);
	FFT::work(t,-1);
	rep(i,0,FFT::n-1)if(t[i])printf("%d %d\n",i,t[i]);
	return 0;
}
