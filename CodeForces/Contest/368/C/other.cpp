#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
#define cls(a) memset(a,0,sizeof(a))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
LL n,m,k;
LL check(LL x){
	LL d=round(sqrt(x));
	if(d*d==x)return d;return 0;
}
int main(){
	scanf("%lld",&n);
	for(int i=1;i*i<=n;++i){
		LL f=n+i;
		if(check(f*f+n*n))return 1;
		if(check(f*f-n*n))return 1;
		f=n-i;
		if(check(f*f+n*n))return 1;
		if(f*f>n*n&&check(f*f-n*n))return 1;
	}
	return 0;
}
