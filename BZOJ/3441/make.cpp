#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=1e5,m=1e5,x=2e9;
int main(){
	freopen("seed.txt","r",stdin);int seed;
	scanf("%d",&seed);srand(seed);freopen("seed.txt","w",stdout);
	printf("%d",rand()*rand());fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d %d %d\n",n,m,x);
	rep(i,1,n)printf("%d ",rand()*rand()+1);puts("");
	rep(i,1,n)printf("%d ",rand()+1);puts("");
	return 0;
}
