#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e6+10,inf=1e7;
int n,a[maxn],dp[maxn][3];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,-1,1)if(a[1]==i)dp[1][i+1]=0;else dp[1][i]=0;

	return 0;
}
