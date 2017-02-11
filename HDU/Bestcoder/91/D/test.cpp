#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n,dp[40][40];;
int main(){
	dp[0][1]=1;
	rep(i,1,30){
		rep(j,1,i){
			rep(k,j,i){
				dp[i][k]+=dp[i-k][j];
			}
		}
	}
	int ans=0;
	rep(i,1,30)ans+=dp[30][i];
	cout<<ans;
	return 0;
}
