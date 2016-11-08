#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int N=250,inf=1e9;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int m=N,n=N,k=rand()%n+1;
	printf("%d %d %d\n",n,m,k);
	rep(i,1,n){
		rep(j,1,m)printf("%d ",rand()%inf+1);puts("");
	}
	return 0;
}
