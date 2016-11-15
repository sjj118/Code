#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=100000,M=100000;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=rand()%N+1,m=rand()%M+1;
	printf("%d %d\n",n,m);
	rep(i,1,m){
		int op=rand()&1;
		int l=rand()%n+1,r=rand()%n+1;
		while(l==r)r=rand()%n+1;
		if(l>r)swap(l,r);
		if(op==0)printf("C %d %d %d\n",l,r,rand()%2001-1000);
		else printf("Q %d %d\n",l,r);
	}
	return 0;
}
