#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int N=5e4,M=1e5;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=N,m=M;
	printf("%d %d\n",n,m);
	rep(i,1,m){
		int op=rand()%3+1,l=rand()%n+1,r=rand()%n+1;
		if(l>r)swap(l,r);
		if(op==1)printf("%d %d %d %d\n",op,l,r,rand()%2001-1000);
		else printf("%d %d %d\n",op,l,r);
	}
	return 0;
}
