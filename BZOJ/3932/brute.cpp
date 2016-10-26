#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace brute{
	
typedef long long LL;
const int N=1e5+10,inf=1e7;
int n,m;
LL ans=1;
struct Quest{
	int s,e,p;
}Q[N];
int p[N],tot;
int main(){
	scanf("%d%d",&m,&n);
	rep(i,1,m)scanf("%d%d%d",&Q[i].s,&Q[i].e,&Q[i].p);
	while(n--){
		int x,a,b,c,k;scanf("%d%d%d%d",&x,&a,&b,&c);
		k=(a*ans+b)%c+1;
		tot=0;
		rep(i,1,m)if(Q[i].s<=x&&Q[i].e>=x)p[++tot]=Q[i].p;
		sort(p+1,p+1+tot);
		ans=0;
		rep(i,1,min(k,tot))ans+=p[i];
		printf("%lld\n",ans);
	}
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return brute::main();
}
