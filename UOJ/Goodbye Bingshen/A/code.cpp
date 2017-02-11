#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		if(n<=3)puts("1");
		else puts("-1");
	}
	return 0;
}
