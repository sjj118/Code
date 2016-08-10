#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int n=200,k;

int main(){
	srand(time(0));freopen("code.in","w",stdout);
	n=rand()%n+1;
	printf("%d %d\n",n,rand()%n+1);
	for(int i=1;i<=n;++i)printf("%d ",rand()+1);printf("\n");
	for(int i=1;i<=n;++i)printf("%d ",rand()+1);printf("\n");
	return 0;
}
