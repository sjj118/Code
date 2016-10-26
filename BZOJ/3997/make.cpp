#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int T=5,N=5,M=5,inf=3;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d\n",T);
	while(T--){
		int n=rand()%N+1,m=rand()%M+1;
		printf("%d %d\n",n,m);
		rep(i,1,n){
			rep(j,1,m)printf("%d ",rand()%inf);puts("");
		}
	}
	return 0;
}
