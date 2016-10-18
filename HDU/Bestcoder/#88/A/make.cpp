#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int T=1,n=1e5;
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	printf("%d\n",T);
	while(T--){
		rep(i,1,n)printf("q");puts("");
	}
	return 0;
}
