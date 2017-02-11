#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const char c[4]={'A','T','G','C'};
char change(int x){
	return c[x];
}
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int T=10;
	printf("%d\n",T);
	while(T--){
		int n=100000;
		rep(i,1,n)printf("%c",change(rand()%4));puts("");
	}
}
