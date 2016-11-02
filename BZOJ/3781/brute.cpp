#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=5e4+10;
int n,m,k,a[N],c[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m){
		int l,r;scanf("%d%d",&l,&r);
		LL ans=0;
		cls(c);
		rep(j,l,r)++c[a[j]];
		rep(j,1,k)ans+=c[j]*c[j];
		printf("%lld\n",ans);
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
