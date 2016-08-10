#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>

using namespace std;

int n=500,m=800,inf=1000000;

int main(){
	srand(time(NULL));
	freopen("code.in","w",stdout);
	printf("%d %d %d\n",n,m,rand()%n+1);
	for(int i=1;i<n;++i)printf("%d %d %d\n",i+1,rand()%i+1,rand()%inf+1);
	for(int i=1;i<=m-n+1;++i)printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()%inf+1);
	return 0;
}
