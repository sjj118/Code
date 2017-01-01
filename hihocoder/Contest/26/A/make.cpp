#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int inf=1e9;
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	int T=10000;
	printf("%d\n",T);
	while(T--){
		printf("%d\n",rand()%inf);
	}
	return 0;
}
