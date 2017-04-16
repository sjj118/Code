#include<iostream>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=500;
	printf("%d\n",n);
	rep(i,1,n){
		//int l=rand()%100000000+1,r=rand()%100000000+1;
		int l=i,r=1e9-i;
		if(l>r)swap(l,r);
		printf("%d %d\n",l,r);
	}
	return 0;
}
