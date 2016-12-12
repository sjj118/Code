#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=100000,k,inf=1<<30;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	k=rand()%7;
	printf("%d %d\n",n,k);
	rep(i,1,n){
		rep(j,1,6)printf("%d ",rand()*rand()%inf);puts("");
	}
	return 0;
}
