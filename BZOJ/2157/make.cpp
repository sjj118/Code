#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=20000,m=20000;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d\n",n);
	rep(i,1,n-1)printf("%d %d %d\n",i,rand()%i,rand()%2001-1000);
	printf("%d\n",m);
	while(m--){
		int op=rand()%5;
		if(op==0)printf("C %d %d\n",rand()%(n-1)+1,rand()%2001-1000);
		if(op==1)printf("N %d %d\n",rand()%n,rand()%n);
		if(op==2)printf("SUM %d %d\n",rand()%n,rand()%n);
		if(op==3)printf("MAX %d %d\n",rand()%n,rand()%n);
		if(op==4)printf("MIN %d %d\n",rand()%n,rand()%n);
	}
	return 0;
}
