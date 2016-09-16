#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=1e5,m=2e5,q=2e5;
int main(){
	freopen("seed.txt","r",stdin);int seed;
	scanf("%d",&seed);srand(seed);
	freopen("seed.txt","w",stdout);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d %d %d\n",n,m,q);
	rep(i,1,n-1)printf("%d %d\n",i+1,rand()%i+1);
	rep(i,1,m-n+1)printf("%d %d\n",rand()%n+1,rand()%n+1);
	rep(i,1,q)printf("%d %d\n",rand()%n+1,rand()%n+1);
	return 0;
}
