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
	int n=5e5,m=2e5;
	printf("%d\n",n);
	rep(i,1,m-1){
		int op=rand()%2+1;
		if(op==1){
			printf("1 %d %d %d\n",rand()%n+1,rand()%n+1,rand()%100+1);
		}else{
			int x1=rand()%n+1,y1=rand()%n+1,x2=rand()%n+1,y2=rand()%n+1;
			if(x1>x2)swap(x1,x2);
			if(y1>y2)swap(y1,y2);
			printf("2 %d %d %d %d\n",x1,y1,x2,y2);
		}
	}
	puts("3");
	return 0;
}
