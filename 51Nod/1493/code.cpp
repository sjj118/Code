#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10;
typedef long long LL;
int n,m,a[maxn],b[maxn];
LL ans,tmp,suma,sumb;
int main(){
	scanf("%d%d",&m,&n);
	rep(i,1,m){scanf("%d",&a[i]);suma+=a[i];}
	rep(i,1,n){scanf("%d",&b[i]);sumb+=b[i];}
	sort(a+1,a+1+m);sort(b+1,b+1+n);
	rep(i,1,m-1)if(a[i]>sumb)tmp+=sumb;else tmp+=a[i];tmp+=sumb;
	ans=tmp;tmp=0;
	rep(i,1,n-1)if(b[i]>suma)tmp+=suma;else tmp+=b[i];tmp+=suma;
	ans=min(ans,tmp);
	printf("%lld",ans);
	return 0;
}
