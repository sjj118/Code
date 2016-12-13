#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=10,inf=1e9;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d\n",n);
	while(n--)printf("%d %d %d %d\n",3,rand()*rand()%inf+1,rand()*rand()%inf+1,rand()*rand()%(inf/1000)+1);
	return 0;
}
