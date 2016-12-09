#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=100000,M=200000,T=100000;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	//int n=rand()*rand()%N+1,m=rand()*rand()%M+1,t=rand()*rand()%T+1;
	int n=N,m=M,t=T;
	printf("%d %d %d\n",n,m,t);
	rep(i,1,m){
		int s=rand()*rand()%(t+1),t=rand()*rand()%(t+1);
		if(s>t)swap(s,t);
		printf("%d %d %d %d\n",rand()*rand()%n+1,rand()*rand()%n+1,s,t);
	}
	return 0;
}
