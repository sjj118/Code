#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=1e6,q=10;
int main(){
	freopen("seed.txt","r",stdin);
	int seed;scanf("%d",&seed);srand(seed);
	freopen("seed.txt","w",stdout);
	printf("%d",rand()*rand());fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d %d\n",n,q);
	rep(i,1,n)printf("%d ",rand()%1000+1);puts("");
	rep(i,1,q){
		int op=rand()&1,l=rand()%n+1,r=rand()%(n-l+1)+l;
		printf("%c %d %d %d\n",op?'M':'A',l,r,op?(rand()%1000+1):(rand()));
	}
	return 0;
}
