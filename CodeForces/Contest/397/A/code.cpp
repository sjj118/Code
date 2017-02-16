#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
int n;
int main(){
	scanf("%d",&n);
	if(n&1)puts("contest");else puts("home");
	return 0;
}
