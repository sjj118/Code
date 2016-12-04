#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int one(int n){
	int l=0;
	while(n)l+=n&1,n>>=1;
	return l;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		printf("%d\n",n-one(n));
	}
	return 0;
}
