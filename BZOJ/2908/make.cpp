#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>

using namespace std;

int n=10000,m=10000,k=32,inf=1e9;

int main(){
	srand(time(NULL));freopen("code.in","w",stdout);
	printf("%d %d %d\n",n,m,k);
	for(int i=1;i<=n;++i)printf("%d ",rand()%inf);printf("\n");
	for(int i=1;i<n;++i)printf("%d %d\n",i+1,rand()%i+1);
	for(int i=1;i<=m;++i){
		int op=rand()%2;
		if(op){
			printf("Replace %d %d\n",rand()%n+1,rand()%inf);
		}else printf("Query %d %d\n",rand()%n+1,rand()%n+1);
	}
	return 0;
}
