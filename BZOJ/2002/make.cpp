#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>

using namespace std;

int n=200000,m=100000;

int main(){
	freopen("code.in","w",stdout);
	srand(time(NULL));
	printf("%d\n",n);
	for(int i=0;i<n;++i)printf("%d ",rand()%n+1);printf("\n");
	printf("%d\n",m);
	for(int i=0;i<m;++i){
		int op=rand()%2+1;
		printf("%d ",op);
		if(op==1){
			printf("%d\n",rand()%n);
		}else{
			printf("%d %d\n",rand()%n,rand()%n+1);
		}
	}
	return 0;
} 
