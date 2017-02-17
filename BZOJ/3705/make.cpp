#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	//int n=rand()%1000+1,m=rand()%1000+1;
	int n=1000,m=1000;
	printf("%d %d\n",n,m);
	rep(i,1,n){
		rep(j,1,m)printf("%d ",rand()%2+1);puts("");
	}
	return 0;
}
