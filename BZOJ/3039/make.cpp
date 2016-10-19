#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=1000,m=1000;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	srand(seed);freopen("seed.txt","w",stdout);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	n=rand()%n+1;m=rand()%m+1;
	printf("%d %d\n",n,m);
	rep(i,1,n){
		rep(j,1,m)printf("%c ",(rand()&1)?'F':'R');puts("");
	}
	return 0;
}
