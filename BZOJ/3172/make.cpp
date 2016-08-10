#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#define LL long long
using namespace std;

int n=20,alp=26;

int main(){
	srand(time(NULL));freopen("code.in","w",stdout);
	printf("%d\n",n);
	for(int i=1;i<=n;++i){
		LL l=rand()*4551%50000;
		for(int j=0;j<=l;++j)printf("%c",'a'+rand()%alp);printf("\n");
	}
}
