#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=1e7+10,mo=998244353;
inline void ck(LL&x){x%=mo;if(x<0)x+=mo;if(x>=mo)x-=mo;}
int n,m;
LL g[maxn];
int main(){
	scanf("%d%d",&n,&m);
	if(n&1){
		LL tmp=m;
		rep(i,2,n)tmp=tmp*(m-1)%mo,g[i]=tmp-g[i-1],ck(g[i]);
		printf("%lld",g[n]);
	}else{
		g[0]=1;rep(i,1,n)g[i]=g[i-1]*(m-1)%mo;
	}
	return 0;
}
