#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
int T=30,N=1e4,Q=1e4;
LL inf=1e18;
LL rnd(){return (LL)rand()*rand()*rand();}
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d\n",T);
	while(T--){
		int n=rand()%N+1;
		printf("%d\n",n);
		rep(i,1,n)printf("%lld ",rnd()+1);puts("");
		int q=rand()%Q+1;
		printf("%d\n",q);
		rep(i,1,q)printf("%d ",rand()%10000+1);puts("");
	}
	return 0;
}
