#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)

using namespace std;

int n=2e5,q=2e5;

int main(){
	srand(time(0));freopen("code.in","w",stdout);
	printf("%d\n",n);
	printf("0");rep(i,2,n)printf(" %d",rand()%(i-1)+1);puts("");
	printf("%d\n",q);
	rep(i,1,q){
		int op=rand()%2+1;printf("%d ",op);
		if(op==1)printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()%(n+1));
		else printf("%d\n",rand()%n+1);
	}
	return 0;
}
