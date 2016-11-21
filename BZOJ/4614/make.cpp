#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int N=2000,inf=1e6;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=rand()%N+1;
	printf("%d\n",n);
	rep(i,1,n)printf("%d %d %d\n",rand()%(2*inf+1)-inf,rand()%(2*inf+1)-inf,i);
	return 0;
}
