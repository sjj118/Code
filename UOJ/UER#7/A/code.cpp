#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
const LL inf=1e18;
LL n,a[maxn],sa[maxn],ma[maxn],f[maxn];
int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",&a[i]);
	per(i,n,0)sa[i]=sa[i+1]+a[i];
	ma[n+1]=n+1;ma[n]=n;
	per(i,n-1,0)if(a[i]<a[ma[i+1]])ma[i]=i;else ma[i]=ma[i+1];
	per(i,n,0){
		f[i]=sa[i+1]-sa[ma[i+1]]+(ma[i+1]-i+1)*a[ma[i+1]]+f[ma[i+1]];
	}
	LL ans=inf;
	per(i,n,0)ans=min(ans,(f[i]+2*i*a[i])*2+a[i]);
	printf("%lld",ans);
	return 0;
}
