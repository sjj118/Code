#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
using namespace std;
int n=3e5,q=3e5;
int main(){
	freopen("seed.txt","r",stdin);
	int seed;scanf("%d",&seed);srand(seed);
	freopen("seed.txt","w",stdout);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d %d\n",n,q);
	rep(i,1,n-1)printf("%d %d\n",i+1,rand()*rand()%i+1);
	rep(i,1,q)printf("%d %d\n",rand()*rand()%n+1,10);
	return 0;
}
