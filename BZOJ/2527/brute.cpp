#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=3e5+10;
int n,m,q,o[N],ans[N];
LL p[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d",&o[i]);
	rep(i,1,n)scanf("%lld",&p[i]);
	scanf("%d",&q);
	rep(i,1,q){
		int l,r,a;scanf("%d%d%d",&l,&r,&a);
		if(l<=r)rep(j,l,r)p[o[j]]-=a;
		else{rep(j,l,m)p[o[j]]-=a;rep(j,1,r)p[o[j]]-=a;}
		rep(j,1,n)if(p[j]<=0&&ans[j]==0)ans[j]=i;
	}
	rep(i,1,n)if(ans[i])printf("%d\n",ans[i]);else puts("NIE");
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
