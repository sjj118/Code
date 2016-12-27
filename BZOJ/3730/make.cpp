#include<iostream>
#include<cstdio>
#include<cstdlib>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int inf=1e4;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	//int n=rand()%100000+1,m=rand()%100000+1;
	int n=1e5,m=1e5;
	printf("%d %d\n",n,m);
	rep(i,1,n)printf("%d ",rand()%inf+1);puts("");
	rep(i,1,n-1)printf("%d %d\n",i,i+1);
	rep(i,1,m)printf("%d %d %d\n",rand()&1,rand()%n+1,rand()%n+1);
	return 0;
}
