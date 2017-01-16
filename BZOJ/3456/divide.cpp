#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=270000,mo=1004535809;
inline void ck(LL&x,LL p){if(x>=p)x-=p;if(x<0)x+=p;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
int n;
LL a[N],inv[N],d[N],fact[N],_fact[N];
/*bool check(LL g){
	for(int i=2;i*i<mo;++i)if((mo-1)%i==0)if(power(g,(mo-1)/i,mo)==1||power(g,i,mo)==1)return 0;
	return 1;
}*/
struct Polynomial{
	int n;
	LL a[N];
	Polynomial(){}
	LL&operator[](int x){return a[x];}
	const LL operator[](int x)const{return a[x];}
	void fft(int deg,int f){
		static int R[N];
		int L=0,oldn=n;
		for(n=1;n<deg;n<<=1)++L;
		rep(i,oldn,n-1)a[i]=0;
		rep(i,0,n-1)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		rep(i,0,n-1)if(R[i]>i)swap(a[i],a[R[i]]);
		for(int i=1;i<n;i<<=1){
			LL wn=power(3,mo-1+f*(mo-1)/i/2,mo);
			for(int j=0;j<n;j+=(i<<1)){
				LL w=1;
				for(int k=0;k<i;++k,w=w*wn%mo){
					LL x=a[j+k],y=w*a[j+k+i]%mo;
					a[j+k]=(x+y)%mo;a[j+k+i]=(mo+x-y)%mo;
				}
			}
		}
		if(f==-1)rep(i,0,n-1)a[i]=a[i]*inv[n]%mo;
	}
};
void solve(int l,int r){
	if(l==r){a[l]=(d[l]+mo-fact[l-1]*a[l]%mo)%mo;return;}
	int mid=(l+r)>>1;
	solve(l,mid);
	static Polynomial f,g;
	f.n=mid-l+1;g.n=r-l+1;
	rep(i,0,mid-l)f[i]=a[l+i]*_fact[l+i-1]%mo;
	rep(i,0,r-l)g[i]=d[i+1]*_fact[i+1]%mo;
	f.fft(2*(r-l+1),1);
	g.fft(2*(r-l+1),1);
	rep(i,0,f.n-1)f[i]=f[i]*g[i]%mo;
	f.fft(2*(r-l+1),-1);
	rep(i,mid+1,r)(a[i]+=f[i-l-1])%=mo;
	solve(mid+1,r);
}
int main(){
	scanf("%d",&n);
	int fn;
	for(fn=1;fn<=(n<<1);fn<<=1);
	inv[1]=1;rep(i,2,fn)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	fact[0]=1;rep(i,1,fn)fact[i]=fact[i-1]*i%mo;
	_fact[0]=1;rep(i,1,fn)_fact[i]=_fact[i-1]*inv[i]%mo;
	rep(i,1,fn)d[i]=power(2,(LL)i*(i-1)/2,mo)%mo;
	solve(1,n);
	printf("%lld",a[n]);
	return 0;
}
