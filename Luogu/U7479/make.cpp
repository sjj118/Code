#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=60000,m=60000;
	printf("%d %d\n",n,m);
	rep(i,1,n)printf("%c",rand()%26+'a');puts("");
	rep(i,1,m){
		int l=rand()%n+1,r=rand()%n+1;
		if(l>r)swap(l,r);
		printf("%d %d\n",l,r);
	}
	return 0;
}
