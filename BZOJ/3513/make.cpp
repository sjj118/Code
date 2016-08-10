#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>

using namespace std;

int T=2,n=100000,inf=100000;

int main(){
	srand(time(NULL));
	freopen("code.in","w",stdout);
	printf("%d\n",T);
	while(T--){
		printf("%d\n",n);
		for(int i=1;i<=n;++i)printf("%d ",rand()*11%inf+1);
		printf("\n");
	}
	return 0;
}
