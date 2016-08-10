#include<iostream>
#include<cstdlib> 
#include<stdlib.h>
#include<time.h>

using namespace std;

int n=10000,P=12304221,m=10000;

int main(){
	srand(time(NULL));
	freopen("code.in","w",stdout);
	printf("%d %d\n",n,P);
	for(int i=1;i<=n;++i)printf("%d ",rand()%10000);
	printf("\n%d\n",m);
	for(int i=1;i<=m;++i){
		int op=rand()%3+1;
		int t=rand()%n+1;
		int g=rand()%(n-t+1)+t;
		printf("%d ",op);
		if(op==1||op==2){
			printf("%d %d %d\n",t,g,rand()%10000);
		}else{
			printf("%d %d\n",t,g);
		}
	}
	return 0;
}
