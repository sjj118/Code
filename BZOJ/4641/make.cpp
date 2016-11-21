#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int cas=10,C=1e6,N=1e6;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d %d\n",cas,C);
	while(cas--){
		int n=rand()%N+1,m=rand()%N+1;
		printf("%d %d\n",n,m);
		rep(i,1,n)printf("%d ",rand()%C+1);puts("");
		rep(i,1,m)printf("%d ",rand()%C+1);puts("");
		puts("");
	}
	return 0;
}
