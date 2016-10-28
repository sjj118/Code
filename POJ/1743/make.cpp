#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e4;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int T=rand()%10;
	while(T--){
		int n=rand()%N+1;
		printf("%d\n",n);
		rep(i,1,n)printf("%d ",rand()%88+1);puts("");
	}
	puts("0");
	return 0;
}
