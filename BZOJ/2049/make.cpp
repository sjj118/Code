#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>
#define maxn 1000

using namespace std;

int n=10,m=100;
int link[maxn][maxn];

int main(){
	freopen("code.in","w",stdout);
	srand(time(NULL));
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;++i){
		int op=rand()%3,u=rand()%n+1,v=rand()%n+1;
		while(u==v)v=rand()%n+1;
		if(op==0&&(!link[u][v]))printf("C "),link[u][v]=link[v][u]=1;
		else if(op==1&&link[u][v])printf("D "),link[u][v]=link[v][u]=0;
		else printf("Q ");
		printf("%d %d\n",u,v);
	}
	return 0;
}
