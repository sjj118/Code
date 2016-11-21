#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int N=2e4,M=2e5,inf=2e4;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=N,m=M;
	printf("%d %d\n",n,m);
	rep(i,1,n-1)printf("%d %d %d\n",i+1,i,rand()%inf+1);
	rep(i,n,m){
		int u=rand()%n+1,v=rand()%n+1;
		while(u==v)v=rand()%n+1;
		printf("%d %d %d\n",u,v,rand()%inf+1);
	}
	int u=rand()%n+1,v=rand()%n+1;
	while(u==v)v=rand()%n+1;
	printf("%d %d %d\n",u,v,rand()%inf+1);
	return 0;
}
