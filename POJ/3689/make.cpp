#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)

int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=rand()%100000,m=rand()%10000;
	printf("%d %d\n",n,m);
	rep(i,1,n)printf("%d %d %d\n",rand()%10000+1,rand()%10000+1,rand()%10000+1);
	rep(i,1,m)printf("%d %d\n",rand()%10000+1,rand()%10000+1);
}
