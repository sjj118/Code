#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=100+10,K=10+5,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,k,a[N][N],dp[N][N][K<<1],s[N][N],ans=-inf,pref[N][K<<1],suff[N][K<<1];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	per(i,n,1)rep(j,1,m)scanf("%d",&a[i][j]);
	rep(i,1,n)rep(j,1,m)s[i][j]=s[i-1][j]+a[i][j];
	rep(i,1,n){
		rep(j,0,m)rep(p,0,n)rep(q,0,k*2+1)dp[j][p][q]=-inf;
		rep(j,1,m){
			dp[j-1][i-1][0]=0;
			rep(p,0,n)rep(q,0,k*2+1)pref[p][q]=suff[p][q]=-inf;
			rep(q,0,k*2+1){
				pref[i-1][q]=dp[j-1][i-1][q];
				rep(p,1,n)pref[p][q]=max(pref[p-1][q],dp[j-1][p][q]);
				suff[n+1][q]=-inf;
				per(p,n,1)suff[p][q]=max(suff[p+1][q],dp[j-1][p][q]);
			}
			rep(p,i,n){
				rep(q,1,k*2+1){
					up(dp[j][p][q],dp[j-1][p][q]+s[p][j]-s[i-1][j]);
					if(q&1){
						up(dp[j][p][q],pref[p-1][q-1]+s[p][j]-s[i-1][j]);
					}else{
						up(dp[j][p][q],suff[p+1][q-1]+s[p][j]-s[i-1][j]);
					}
				}
				up(ans,dp[j][p][k*2+1]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
