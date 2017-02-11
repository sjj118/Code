#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=12;
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	int n=9,m=9;
	printf("%d %d\n",n,m);
	rep(i,1,n){
		rep(j,1,m)printf("%c",rand()%9?'.':'*');puts("");
	}
	return 0;
}
