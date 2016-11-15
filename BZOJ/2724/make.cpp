#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=4e4,M=5e4;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=rand()%N+1,m=rand()%M+1;
	printf("%d %d\n",n,m);
	rep(i,1,n)printf("%d ",rand()%N+1);puts("");
	rep(i,1,m)printf("%d %d\n",rand()%n+1,rand()%n+1);
	return 0;
}
