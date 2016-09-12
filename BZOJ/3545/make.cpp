#include<iostream>
#include<cstdio>
#include<cstdlib>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int n=1e5,m=5e5,q=5e5;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	srand(seed);freopen("seed.txt","w",stdout);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d %d %d\n",n,m,q);
	rep(i,1,n)printf("%d ",rand()+1);puts("");
	rep(i,1,m)printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()+1);
	rep(i,1,q)printf("%d %d %d\n",rand()%n+1,rand()+1,rand()%n+1);
	return 0;
}
