#include<iostream>
#include<cstdio>
#include<cstdlib>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int inf=1e6;
int main(){
	freopen("code.in","w",stdout);
	int n=1e5,m=1e5,q=1e5;
	printf("%d %d %d\n",n,m,q);
	rep(i,1,m)printf("%d ",rand()%inf+1);puts("");
	rep(i,1,n)printf("%d ",rand()%inf+1);puts("");
	rep(i,1,n-1)printf("%d %d\n",i+1,i);
	rep(i,1,n)printf("%d ",rand()%m+1);puts("");
	rep(i,1,q)printf("%d %d %d\n",rand()&1,rand()%n+1,rand()%n+1);
}
