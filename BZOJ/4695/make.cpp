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
	int n=5e5;
	printf("%d\n",n);
	rep(i,1,n)printf("%d ",rand()%200000001-100000000);puts("");
	int m=5e5;
	printf("%d\n",m);
	rep(i,1,m){
		int op=rand()%6+1,l=rand()%n+1,r=rand()%n+1;
		if(l>r)swap(l,r);
		if(op==1){
			printf("%d %d %d %d\n",op,l,r,rand()%2001-1000);
		}else if(op<=3){
			printf("%d %d %d %d\n",op,l,r,rand()%200000001-100000000);
		}else printf("%d %d %d\n",op,l,r);
	}
	return 0;
}
