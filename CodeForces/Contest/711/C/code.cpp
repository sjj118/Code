#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
inline void dn(LL&x,LL y){if(y<x)x=y;}
const int maxn=100+10;
const LL inf=1e14;
int n,m,k,c[maxn];
LL dp[maxn][maxn][maxn],pre[maxn][maxn][maxn],suf[maxn][maxn][maxn],w[maxn][maxn]; 
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%d",&c[i]);
	rep(i,1,n)rep(j,1,m)scanf("%I64d",&w[i][j]);
	rep(i,0,n+1)rep(j,0,m+1)rep(p,0,k+1)dp[i][j][p]=inf,pre[i][j][p]=inf,suf[i][j][p]=inf;
	if(c[1]==0){
		rep(i,1,m)dn(dp[1][i][1],w[1][i]);
	}else{
		dp[1][c[1]][1]=0;
	}
	rep(j,1,m){
		rep(p,1,k){
			pre[1][j][p]=min(pre[1][j-1][p],dp[1][j][p]);
		}
	}
	per(j,m,1){
		rep(p,1,k){
			suf[1][j][p]=min(suf[1][j+1][p],dp[1][j][p]);
		}
	}
	rep(i,2,n){
		if(c[i]==0)rep(j,1,m){
			rep(p,1,k){
				dn(dp[i][j][p],dp[i-1][j][p]+w[i][j]);
				dn(dp[i][j][p],min(pre[i-1][j-1][p-1],suf[i-1][j+1][p-1])+w[i][j]);
			}
		}else{
			rep(p,1,k){
				dp[i][c[i]][p]=dp[i-1][c[i]][p];
				rep(j,1,m)if(j!=c[i])dn(dp[i][c[i]][p],dp[i-1][j][p-1]);
			}
		}
		rep(j,1,m){
			rep(p,1,k){
				pre[i][j][p]=min(pre[i][j-1][p],dp[i][j][p]);
			}
		}
		per(j,m,1){
			rep(p,1,k){
				suf[i][j][p]=min(suf[i][j+1][p],dp[i][j][p]);
			}
		}
	}
	LL ans=inf;
	rep(i,1,m)dn(ans,dp[n][i][k]);
	if(ans==inf)puts("-1");else printf("%I64d",ans);
}
