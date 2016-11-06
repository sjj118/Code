#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=3e5,inf=1e9;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=1e3,m=3e3,q=3e3;
	printf("%d %d\n",n,m);
	rep(i,1,m)printf("%d ",rand()%n+1);puts("");
	rep(i,1,n)printf("%d ",rand()%inf+1);puts("");
	printf("%d\n",q);
	rep(i,1,q)printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()%inf+1);
	return 0;
}
