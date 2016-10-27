#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
int N=20,inf=2e9;
int rnd(){return (LL)rand()*rand()*rand()%inf*rand()%inf;}
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=rand()%N+1;
	printf("%d\n",n);
	rep(i,1,n)printf("%d ",rand()%50);
	return 0;
}
