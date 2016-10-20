#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
int n=1000,inf=1e9;
inline int rnd(){return (LL)rand()*rand()%inf*rand()%inf*rand()%inf;}
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d %d\n",n,rand()%(n+1));
	rep(i,1,n)printf("%d\n",rnd()+1);
	return 0;
}
