#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>

using namespace std;

int n=100000,m=100000,k=20,maxn=1000;

int main(){
	srand(time(NULL));
//	n=rand()%n+1;
//	m=rand()%m+1;
//	k=rand()%k+1;
//	maxn=rand()%maxn+1; 
	freopen("code.in","w",stdout);
	printf("%d %d %d\n",n,m,k);
	for(int i=0;i<n;++i)printf("%d ",rand()%maxn);
	printf("\n");
	for(int i=0;i<m;++i){
		int x,y,delta;
		delta=rand()%(n-k)+k;
		x=rand()%(n-delta)+1;
		y=x+delta;
		printf("%d %d ",x,y);
		for(int j=0;j<k;++j)printf("%d ",rand()%maxn);
		printf("\n");
	}
	return 0;
}
