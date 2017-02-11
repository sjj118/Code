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
	int n=rand()%10000+3,m=n;
	printf("%d %d\n",n,m);
	int s=0;
	rep(i,1,n-1){
		printf("%d %d %d\n",2,i+1,s=rand()%i+1);
	}
	int t=rand()%(n-1)+1;
	while(t==s)t=rand()%(n-1)+1;
	printf("2 %d %d\n",n,t);
	return 0;
}
