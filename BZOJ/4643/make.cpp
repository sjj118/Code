#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	int n=150;
	printf("%d\n",n);
	rep(i,1,n){
		rep(j,1,n)printf("%d ",rand()%1000000000+1);puts("");
	}
	rep(i,1,n){
		rep(j,1,n)printf("%d ",rand()%1000000000+1);puts("");
	}
	return 0;
}
