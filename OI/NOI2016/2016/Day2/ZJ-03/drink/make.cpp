#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

int n=500,k=500,p=200;

int main(){
	srand(time(0));freopen("drink.in","w",stdout);
	k=rand()%k;
	printf("%d %d %d\n",n,k,p);printf("1 ");
	for(int i=2;i<=n;++i)printf("%d ",rand()%100000+1);
	return 0;
}
