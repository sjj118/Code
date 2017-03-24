#include<iostream>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
int main(){
	freopen("code.in","w",stdout);
	int n=2e5,m=1e6;
	printf("%d\n",n);
	rep(i,1,n)printf("%d %d\n",rand()%10000000,rand()%10000000);
	printf("%d\n",m);
	rep(i,1,m)printf("%d %d\n",rand()%n+1,rand()%n+1);
	return 0;
}
