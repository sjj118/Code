#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace brute{
	
typedef long long LL;
const int N=1e4+10,P=1e7;
int n,q,tot;
LL a[N],b[P];
void dfs(int k,LL d,bool f){
	if(k==n+1){
		if(f)b[++tot]=d;
		return;
	}
	dfs(k+1,d,f);dfs(k+1,d^a[k],1);
}
int main(){
	int T;scanf("%d",&T);
	rep(cas,1,T){
		printf("Case #%d:\n",cas);
		scanf("%d",&n);
		rep(i,1,n)scanf("%lld",&a[i]);tot=0;
		dfs(1,0,0);
		sort(b+1,b+1+tot);
		b[n=0]=-1;
		rep(i,1,tot)if(b[i]!=b[n])b[++n]=b[i];
		scanf("%d",&q);
		rep(i,1,q){
			LL k;scanf("%lld",&k);
			if(k>n)puts("-1");else printf("%lld\n",b[k]);
		}
	}
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return brute::main();
}
