#include<cstdlib>
#include<ctime>
#include<iostream>
#define LL long long
#define rand() (LL)rand()*rand()

using namespace std;

LL n=1000000000,m=1,P=1000000000;

int main(){
	srand(time(0));freopen("code.in","w",stdout);
	n=rand()%n+1;P=(rand()%1000000+1)*(rand()%1000000+1);
	printf("%lld %lld %lld\n",P,n,m);
	printf("%lld",rand()%n+1);
	return 0;
}
