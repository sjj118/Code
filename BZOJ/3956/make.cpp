#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)

int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(rand()+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	//int n=rand()%100+1,m=rand()%100+1,type=rand()&1;
	int n=3e5,m=3e5,type=0;
	printf("%d %d %d\n",n,m,type);
	rep(i,1,n)printf("%d ",rand()%1000000000+1);puts("");
	rep(i,1,m)printf("%d %d\n",rand()%n+1,rand()%n+1);
	return 0;
}
