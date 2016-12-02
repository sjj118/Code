#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=400,m=n*n,inf=1e9;
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	printf("%d %d %d\n",n,n,m);
	rep(i,1,n)rep(j,1,n)printf("%d %d %d\n",i,j,(i+j-2)*(i+j-2));
	//rep(i,1,m)printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand());
	return 0;
}
