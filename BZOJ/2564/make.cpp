#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int rnd(){return rand()%200000001-100000000;}
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=100000,m=100000;
	printf("%d %d\n",n,m);
	rep(i,1,n)printf("%d %d ",rnd(),rnd());puts("");
	rep(i,1,m)printf("%d %d ",rnd(),rnd());
	return 0;
}
