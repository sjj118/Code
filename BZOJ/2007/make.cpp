#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=500;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	srand(seed);freopen("seed.txt","w",stdout);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d\n",n);
	rep(i,1,4*n*(n+1))printf("%d\n",rand()*rand()%1000001);
	return 0;
}
