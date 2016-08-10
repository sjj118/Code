#include<iostream>
#include<cstdio>
#define mo 12345678
#define LL long long
#define maxn 155
#define maxk 22

using namespace std;
 
int n,m,k;
LL dp[maxn][maxn][maxk][maxk];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	dp[0][0][0][0]=1;
	for(int x=0;x<=n;++x){
		for(int y=0;y<=m;++y){
			for(int i=0;i<=k;++i){
				for(int j=0;j<=k;++j){
					if(x&&i)dp[x][y][i][j]=(dp[x][y][i][j]+dp[x-1][y][i-1][j+1]+(j==0?dp[x-1][y][i-1][j]:0))%mo;
					if(y&&j)dp[x][y][i][j]=(dp[x][y][i][j]+dp[x][y-1][i+1][j-1]+(i==0?dp[x][y-1][i][j-1]:0))%mo;
				}
			}
		}
	}
	LL ans=0;
	for(int i=0;i<=k;++i)for(int j=0;j<=k;++j)ans=(ans+dp[n][m][i][j])%mo;
	printf("%d",ans);
	return 0;
}
