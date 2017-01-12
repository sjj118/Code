#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n;
int rnd(){return rand()%2000000001-1000000000;}
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	n=100000;
	printf("%d\n",n);
	rep(i,1,n)printf("%d %d\n",rnd(),rnd());
	int m=10000;
	printf("%d\n",m);
	rep(i,1,m)printf("%d %d %d\n",rnd(),rnd(),rand()%min(20,n)+1);
	return 0;
}
