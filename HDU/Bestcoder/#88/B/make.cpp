#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int T=10,n=1e5;
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	printf("%d\n",T);
	while(T--){
		printf("%d\n",n);
		rep(i,1,n)printf("%d ",rand()%n+1);puts("");
	}
	return 0;
}
