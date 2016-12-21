#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	printf("%d",7*min(min(a,b/2),c/4));
	return 0;
}
