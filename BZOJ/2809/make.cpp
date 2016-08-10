#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#define LL long long

using namespace std;

int n=100000,m=1000000000;

int main(){
	srand(time(NULL));freopen("code.in","w",stdout);
	printf("%d %d\n",n,m);
	printf("%d %lld %lld\n",0,(LL)rand()*21411%m+1,(LL)rand()*12341%m+1);
	for(int i=2;i<=n;++i)printf("%d %lld %lld\n",rand()%(i-1)+1,(LL)rand()*21411%m+1,(LL)rand()*12341%m+1);
	return 0;
}
