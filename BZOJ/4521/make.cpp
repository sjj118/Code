#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#define LL long long

using namespace std;

int main(){
	srand(time(NULL));freopen("number.in","w",stdout);
	LL L=(LL)rand()*924352231411%90000000000+10000000000,R=L+(LL)rand()*421%(100000000000-L);
	printf("%lld %lld",L,R);
	return 0;
}
