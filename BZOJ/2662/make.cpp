#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=50,m=1000,k=50;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	k=rand()%(k+1);
	printf("%d %d %d\n",n,m,k);
	rep(i,1,n-1)printf("%d %d %d\n",i+1,rand()%i+1,(rand()%1000+1)*2);
	rep(i,n,m)printf("%d %d %d\n",rand()%n+1,rand()%n+1,(rand()%1000+1)*2);
	return 0;
}
