#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=1000,m=500;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d\n",m);
	rep(i,1,m)printf("%d ",rand()%1000+1);puts("");
	printf("%d\n",n);
	rep(i,1,n)printf("%d %d\n",rand()%2001-1000,rand()%2001-1000);
	return 0;
}
