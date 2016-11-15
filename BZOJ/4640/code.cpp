#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int mo=1e9+7;
int k,n;
inline void up(LL&x,LL y){if(y>x)x=y;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
inline void ck(LL&x){if(x<0)x+=mo;if(x>=mo)x-=mo;}
inline void ad(LL&x,LL y){x+=y;ck(x);}
namespace k1{
	const int N=1e6+10;
	int a[N],b[N];
	LL ans,fact[N],inv[N],_fact[N];
	int main(){
		rep(i,1,n)scanf("%d",&a[i]);
		rep(i,1,n)scanf("%d",&b[i]);
		fact[0]=1;rep(i,1,n)fact[i]=fact[i-1]*i%mo;
		inv[1]=1;rep(i,2,n)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i]);
		_fact[0]=1;rep(i,1,n)_fact[i]=_fact[i-1]*inv[i]%mo;
		for(int i=1,j=0;i<=n;++i){
			while(j<n&&a[i]>=b[j+1])++j;
			ad(ans,j*fact[n-1]%mo);
		}
		ans=ans*_fact[n]%mo;
		printf("%lld\n",ans);
		return 0;
	}
}
namespace k2{
	const int N=1e6+10;
	int a[N],b[N];
	LL ans,fact[N],inv[N],_fact[N];
	int main(){
		rep(i,1,n)scanf("%d",&a[i]);
		rep(i,1,n)scanf("%d",&b[i]);
		fact[0]=1;rep(i,1,n)fact[i]=fact[i-1]*i%mo;
		inv[1]=1;rep(i,2,n)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i]);
		_fact[0]=1;rep(i,1,n)_fact[i]=_fact[i-1]*inv[i]%mo;
		LL sum=0;
		for(int i=1,j=0;i<=n;++i){
			while(j<n&&a[i]>=b[j+1])++j;
			ad(ans,2*sum*(j-1)%mo*fact[n-2]%mo);
			ad(ans,j*fact[n-1]%mo);
			sum+=j;
		}
		ans=ans*_fact[n]%mo;
		printf("%lld\n",ans);
		return 0;
	}
}
namespace kk{
	const int N=2000+10;
	int a[N],b[N];
	LL f[N][N];
	int main(){
		rep(i,1,n)scanf("%d",&a[i]);
		rep(i,1,n)scanf("%d",&b[i]);

		return 0;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	if(k==1)return k1::main();
	else if(k==2)return k2::main();
	else return kk::main();
}
