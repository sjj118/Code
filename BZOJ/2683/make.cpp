#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>

using namespace std;

int n=1000,m=1000,inf=2000;

int main(){
	srand(time(NULL));
	freopen("code.in","w",stdout);
	printf("%d\n",n);
	for(int i=1;i<=m;++i){
		int op=rand()%2+1;
		printf("%d ",op);
		if(op==1){
			int x=rand()%n+1,y=rand()%n+1,a=rand()%inf+1;
			printf("%d %d %d\n",x,y,a);
		}else{
			int x1=rand()%n+1,y1=rand()%n+1,x2=rand()%(n-x1+1)+x1,y2=rand()%(n-y1+1)+y1;
			printf("%d %d %d %d\n",x1,y1,x2,y2);
		}
	}
	printf("3");
	return 0;
}
