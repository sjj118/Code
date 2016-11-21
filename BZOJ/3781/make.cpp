#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=5e4,m=5e4,k=5e4;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
//	n=rand()%n+1;m=rand()%m+1,k=rand()%k+1;
	printf("%d %d %d\n",n,m,k);
	rep(i,1,n)printf("%d ",rand()%k+1);puts("");
	rep(i,1,m){
		int l=rand()%n+1,r=rand()%n+1;
		if(l>r)swap(l,r);
		printf("%d %d\n",l,r);
	}
	return 0;
}
