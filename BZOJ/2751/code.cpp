#include<iostream>
#include<cstdio>
#include<algorithm>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=1e5+10,mo=1e9+7;
inline void ck(LL&x){if(x<0)x+=mo;if(x>=mo)x-=mo;}
inline void ad(LL&x,LL y){x+=y;ck(x);}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
int k;
LL n,m,sum;
pii a[maxn];
int main(){
	scanf("%lld%lld%d",&n,&m,&k);
	sum=(LL)(n+1)*n/2%mo;
	rep(i,1,k)scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+1+k);
	LL ans=1;
	LL tmp=0;
	int last=0;
	rep(i,1,k){
		last=a[i].fi;
		if(a[i]==a[i-1])continue;
		if(i==1||a[i].fi==a[i-1].fi)ad(tmp,a[i].se);
		else{
			ans=ans*(sum-tmp)%mo;tmp=a[i].se;
			ans=ans*power(sum,a[i].fi-a[i-1].fi-1,mo)%mo;
		}
	}
	if(k)ans=ans*(sum-tmp)%mo;
	ans=ans*power(sum,m-last,mo)%mo;ck(ans);
	printf("%lld",ans);
	return 0;
}
