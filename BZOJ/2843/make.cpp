#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=30000,m=100000;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d\n",n);
	rep(i,1,n)printf("%d ",rand()%1001);puts("");
	printf("%d\n",m);
	rep(i,1,m){
		int op=rand()%3;
		if(op==0)printf("bridge %d %d\n",rand()%n+1,rand()%n+1);
		if(op==1)printf("penguins %d %d\n",rand()%n+1,rand()%1001);
		if(op==2)printf("excursion %d %d\n",rand()%n+1,rand()%n+1);
	}
	return 0;
}
