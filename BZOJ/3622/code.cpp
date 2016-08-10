#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int mo=1e9+9,maxn=2016;
typedef long long LL;
using namespace std;
inline void ck(LL&x){int cnt=0;while(x<0)x+=mo,++cnt;while(x>=mo)x-=mo,++cnt;if(cnt>1)cerr<<"ERROR"<<endl;}
inline void ad(LL&x,LL y){x+=y;ck(x);}
inline int read(){
	int tmp=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}
inline LL power(LL x,LL y,LL p){
	LL a=1;
	while(y){
		if(y&1)a=a*x%p;
		x=x*x%p;
		y>>=1;
	}
	return a;
}
inline LL inv(LL n,LL mo){return power(n,mo-2,mo);}

int n,k,a[maxn],b[maxn];
LL f[maxn][maxn],g[maxn],fact[maxn],rev[maxn];

int main(){
	scanf("%d%d",&n,&k);
	if((n+k)&1){puts("0");return 0;}k=(n+k)>>1;
	rep(i,1,n)a[i]=read();
	rep(i,1,n)b[i]=read();
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	int p=0;
	f[0][0]=1;
	rep(i,1,n){
		while(p<n&&a[i]>b[p+1])++p;
		rep(j,0,p){
			ad(f[i][j],f[i-1][j]);
			if(j)ad(f[i][j],f[i-1][j-1]*(p-j+1)%mo);
		}
	}
	rep(i,1,n)rev[i]=inv(i,mo);
	fact[0]=1;rep(i,1,n)fact[i]=fact[i-1]*i%mo;
	per(i,n,k){
		g[i]=f[n][i]*fact[n-i]%mo;
		LL c=1;
		rep(j,i+1,n)c=c*j%mo*rev[j-i]%mo,ad(g[i],-g[j]*c%mo);
	}
	printf("%lld",g[k]);
	return 0;
}
