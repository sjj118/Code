#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>

using namespace std;

int n=50000,m=50000;

int main(){
	srand(time(NULL));freopen("code.in","w",stdout);
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;++i){
		int a=rand()%n+1,b=rand()%(n-a+1)+a,op=rand()%2+1,c;
		if(op==1)c=rand()*4241%(2*n+1)-n;else c=rand()*4543%n+1;
		printf("%d %d %d %d\n",op,a,b,c);
	}
	return 0;
}
