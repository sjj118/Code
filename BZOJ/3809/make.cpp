#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
int n=10000,m=10000;
int main(){
	srand(time(NULL));freopen("code.in","w",stdout);
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;++i)printf("%d ",rand()%n+1);printf("\n");
	for(int i=1;i<=m;++i){
		int l=rand()%n+1,a=rand()%n+1;
		printf("%d %d %d %d\n",l,rand()%(n-l+1)+l,a,rand()%(n-a+1)+a);
	}
}
