#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>

using namespace std;

int n=100,m=10000;

int main(){
	srand(time(NULL));freopen("code.in","w",stdout);
	printf("%d\n",n);
	for(int i=1;i<=m;++i){
		int op=rand()%5;
		if(op==0)printf("Close ");
		else if(op==1)printf("Ask ");
		else printf("Open ");
		int r1=rand()%2+1,c1=rand()%n+1,r2,c2;
		if(rand()%2)r2=r1,c2=c1<n?c1+1:c1-1;
		else c2=c1,r2=3-r1;
		printf("%d %d %d %d\n",r1,c1,r2,c2);
	}
	printf("Exit\n");
	return 0;
}
