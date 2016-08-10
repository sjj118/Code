#include<iostream>
#include<cstdio>
#define maxn 100009
#define LL long long

using namespace std;

LL n,P,m;
LL x[maxn];

int main(){
	freopen("code.in","r",stdin);
	freopen("brute.out","w",stdout);
	scanf("%lld%lld",&n,&P);
	for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
	scanf("%lld",&m);
	for(int i=0;i<m;++i){
		int op;
		scanf("%d",&op);
		if(op==1){
			int t,g,c;
			scanf("%d%d%d",&t,&g,&c);
			for(int i=t;i<=g;++i)x[i]=x[i]*c%P;
		}else if(op==2){
			int t,g,c;
			scanf("%d%d%d",&t,&g,&c);
			for(int i=t;i<=g;++i)x[i]=(x[i]+c)%P;
		}else{
			int t,g;
			scanf("%d%d",&t,&g);
			LL ans=0;
			for(int i=t;i<=g;++i)ans=(ans+x[i])%P;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
