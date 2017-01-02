#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int alp=3;
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	int n=rand()%100+1;
	rep(i,1,n)printf("%c",rand()%alp+'a');puts("");
	int T=100;printf("%d\n",T);
	while(T--){
		int m=rand()%3+1;
		rep(i,1,m)printf("%c",rand()%alp+'a');puts("");
	}
	return 0;
}
