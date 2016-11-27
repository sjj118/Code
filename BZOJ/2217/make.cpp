#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e6,M=1e6;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=N,m=M;
	printf("%d %d\n",n,m);
	rep(i,1,n)printf("%c",(rand()&1)?'T':'W');puts("");
	rep(i,1,m)printf("%d\n",rand()%(N<<1)+1);
	return 0;
}
