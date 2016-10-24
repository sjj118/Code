#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=20,m=71;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d %d\n",n,m);
	rep(i,1,n)printf("%d ",rand()&1);puts("");
	rep(i,1,m)printf("%d %d\n",rand()%n+1,rand()%n+1);
	return 0;
}
