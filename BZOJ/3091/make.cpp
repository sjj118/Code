#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>

using namespace std;

int n=50000,m=50000,inf=1000000;

int main(){
	srand(time(NULL));
	freopen("code.in","w",stdout);
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;++i)printf("%d ",rand()*21341%inf+1);printf("\n");
	for(int i=1;i<n;++i)printf("%d %d\n",i+1,rand()%i+1);
	for(int i=1;i<=m;++i){
		int op=rand()%4+1,u=rand()%n+1,v=rand()%n+1;
		printf("%d ",op);
		printf("%d %d ",u,v);
		if(op==3)printf("%d",rand()%100+1);
		printf("\n");
	}
	return 0;
}
