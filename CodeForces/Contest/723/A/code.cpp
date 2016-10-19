#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int x[3];
int main(){
	rep(i,0,2)scanf("%d",&x[i]);
	sort(x,x+3);
	printf("%d",x[2]-x[0]);
	return 0;
}
