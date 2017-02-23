#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
int main(){
	freopen("code.in","w",stdout);
	int n=1e5;
	printf("%d\n",n);
	rep(i,1,n)printf("%d ",rand()%30000+1);
	return 0;
}
