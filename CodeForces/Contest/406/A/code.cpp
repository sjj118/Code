#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=7000+10;
int n,k1,k2,s1[N],s2[N],dp[N];
int main(){
	scanf("%d",&n);
	scanf("%d",&k1);rep(i,1,k1)scanf("%d",&s1[i]);
	scanf("%d",&k2);rep(i,1,k2)scanf("%d",&s2[i]);
	dp[0]=-1;
	rep(i,0,n-1)if(!dp[i]){

	}
	return 0;
}
