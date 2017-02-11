#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(time(0)+seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=rand()%50+1,m=rand()%200+1;
	printf("%d %d %d\n",n,m,rand()%1000);
	rep(i,1,n)printf("%d %d %d %d\n",rand()%n+1,rand()%n+1,rand()%100+1,rand()%100+1);
	return 0;
}
