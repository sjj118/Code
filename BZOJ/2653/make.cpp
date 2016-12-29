#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int inf=1e9;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=20000;
	printf("%d\n",n);
	rep(i,1,n)printf("%d\n",rand()%inf);
	int q=25000;
	printf("%d\n",q);
	rep(i,1,q){
		int x[4];rep(j,0,3)x[j]=rand()%(n-3);
		sort(x,x+4);
		rep(j,0,3)printf("%d ",x[j]+j);
		puts("");
	}
	return 0;
}
