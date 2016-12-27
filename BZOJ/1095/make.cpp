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
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=100000;
	printf("%d\n",n);
	rep(i,1,n-1)printf("%d %d\n",rand()%i+1,i+1);
	int q=500000;
	printf("%d\n",q);
	rep(i,1,q){
		int op=rand()&1;
		if(op)puts("G");
		else printf("C %d\n",rand()%n+1);
	}
	return 0;
}
