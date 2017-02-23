#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	int n=10000,m=100000,p=10;
	printf("%d %d %d\n",n,m,p);
	rep(i,1,m)printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()%50000+1);
	return 0;
}
