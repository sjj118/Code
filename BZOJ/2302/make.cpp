#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>

using namespace std;

int T=10,n=300,m,M=1000000007;

int main(){
	srand(time(NULL));
	freopen("code.in","w",stdout);
	printf("%d\n",T);
	while(T--){
		m=rand()%(n+1);
		printf("%d %d %d\n",n,m,M);
		for(int i=1;i<=m;++i)printf("%d %d ",rand()%n+1,rand()%n+1);printf("\n");
	}
	return 0;
}
