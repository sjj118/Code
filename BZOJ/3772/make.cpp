#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int n=1e5,m=1e5;

int main(){
	srand(time(0));freopen("code.in","w",stdout);
	printf("%d %d\n",n,m);
	for(int i=2;i<=n;++i)printf("%d %d\n",i,rand()%(i-1)+1);
	for(int i=1;i<=m;++i){
		int a=rand()%m+1,b=rand()%m+1;
		while(a==b)b=rand()%m+1;
		printf("%d %d\n",a,b);
	}
	return 0;
}
