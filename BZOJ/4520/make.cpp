#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#define LL long long
using namespace std;

int n=100000,k=100;
LL inf=1<<31;

int main(){
	srand(time(NULL));freopen("code.in","w",stdout);
	printf("%d %d\n",n,k);
	for(int i=1;i<=n;++i)printf("%lld %lld\n",(LL)rand()*951721%inf,(LL)rand()*451641%inf);
	return 0;
}
