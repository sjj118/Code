#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=15000,m=30000,k=15000,inf=1e9;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	freopen("code.in","w",stdout);
	printf("%d %d %d\n",n,m,k);
	rep(i,1,n-1)printf("%d %d %d\n",i+1,rand()%i+1,rand()*rand()%inf+1);
	rep(i,n,m)printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()*rand()%inf+1);
	rep(i,1,k)printf("%d %d\n",rand()%n+1,rand()%n+1);
	return 0;
}
