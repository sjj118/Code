#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int N=200,M=1e4;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=N,m=M;
	printf("%d %d\n",n,m);
	rep(i,1,n-1)printf("%d %d %d %d\n",i,rand()%i,rand()%256,rand()%256);
	rep(i,n,m)printf("%d %d %d %d\n",rand()%n,rand()%n,rand()%256,rand()%256);
}
