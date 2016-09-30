#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
using namespace std;
typedef long long LL;
const int maxn=3e5+10,mo=998244353;
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
LL power(LL x,LL y,LL p){ck(y,p-1);LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
int n,fn,R[maxn],L;
LL a[maxn],b[maxn];
void ntt(LL*a,int f,int n){
	rep(i,0,n-1)if(i<R[i])swap(a[i],a[R[i]]);
	for(int i=1;i<n;i<<=1){
		LL wn=power(3,f*(mo-1)/i/2,mo);
		for(int j=0;j<n;j+=i<<1){
			LL w=1;
			for(int k=0;k<i;++k,w=w*wn%mo){
				LL x=a[j+k],y=w*a[j+k+i]%mo;
				a[j+k]=x+y;a[j+k+i]=x-y;ck(a[j+k],mo);ck(a[j+k+i],mo);
			}
		}
	}
	LL inv=power(n,mo-2,mo);
	if(f==-1)rep(i,0,n-1)a[i]=a[i]*inv%mo;
}
int main(){
	scanf("%d",&n);
	rep(i,0,n-1)scanf("%lld%lld",&a[i],&b[n-i-1]);
	for(fn=1;fn<=n*2-1;fn<<=1)++L;
	rep(i,0,fn-1)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	ntt(a,1,fn);ntt(b,1,fn);
	rep(i,0,fn-1)a[i]=a[i]*b[i]%mo;
	ntt(a,-1,fn);
	rep(i,n-1,n*2-2)printf("%lld\n",a[i]);
	return 0;
}
