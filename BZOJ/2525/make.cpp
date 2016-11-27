#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=rand()%N+1,m=rand()%n+1;
	printf("%d %d\n",n,m);
	rep(i,1,n)printf("%d ",rand()%5==0);puts("");
	rep(i,1,n-1)printf("%d %d\n",rand()%i+1,i+1);
	return 0;
}
