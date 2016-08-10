#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>

using namespace std;

int n=100000,q=100000,inf=10000;
int link[100010];

int main(){
	freopen("tree.in","w",stdout);
	srand(time(NULL));
	printf("%d %d\n",n,q);
	for(int i=2;i<=n;++i){
		int x=rand()%(i-1)+1;
		link[i]=x;
		printf("%d %d\n",i,x);
	}
	for(int i=1;i<=q;++i){
		int op=rand()%4;
		if(op==0)printf("+ %d %d %d\n",rand()%n+1,rand()%n+1,rand()%inf+1);
		if(op==1)printf("* %d %d %d\n",rand()%n+1,rand()%n+1,rand()%inf+1);
		if(op==2)printf("/ %d %d\n",rand()%n+1,rand()%n+1);
		if(op==3){
			int u1=rand()%(n-1)+2,v1=link[u1],v2=rand()%(u1-1)+1;
			link[u1]=v2;
			printf("- %d %d %d %d\n",u1,v1,u1,v2);
		}
	}
}
