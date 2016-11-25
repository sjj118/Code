#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	/*int n=rand()%100+1,m=rand()%10000+1;
	printf("%d %d\n",n,m);
	rep(i,0,n)printf("%d\n",rand()%201-100);*/
	int n=100,m=1000000;
	printf("%d %d\n",n,m);
	rep(i,0,n){
		if(rand()&1)printf("-");
		rep(i,1,10000)printf("%d",rand()%10);puts("");
	}
	return 0;
}
