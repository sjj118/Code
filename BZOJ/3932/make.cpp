#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int M=1000,N=1000,inf=1e7;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
//	int n=N,m=M;
	int n=rand()%N+1,m=rand()%M+1;
	printf("%d %d\n",m,n);
	rep(i,1,m){
		int s=rand()%n+1,e=rand()%(n-s+1)+s,p=rand()%inf+1;
		printf("%d %d %d\n",s,e,p);
	}
	rep(i,1,n)printf("%d %d %d %d\n",rand()%n+1,rand()%M,rand()%M,rand()%m+1);
	return 0;
}
