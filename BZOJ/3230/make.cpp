#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int N=1e5,Q=1e5;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=rand()%N+1,q=rand()%Q+1;
	printf("%d %d\n",n,q);
	rep(i,1,n)printf("%c",rand()%26+'a');puts("");
	rep(i,1,q){int x=rand()%(n*n)+1,y=rand()%(n*n)+1;if(x>y)swap(x,y);printf("%d %d\n",x,y);}
	return 0;
}
