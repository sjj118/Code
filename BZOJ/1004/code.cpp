#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 62
#define maxs 21

using namespace std;

int ans,dp[maxn][maxs][maxs][maxs],vis[maxn],cnt,xun[maxn];
int sr,sb,sg,n,m,mo,change[maxn][maxn];
int power(int base,int exp){
	int ans=1;
	while(exp){
		if(exp&1)ans=ans*base%mo;
		base=base*base%mo;
		exp>>=1;
	}
	return ans;
}

int main(){
	scanf("%d%d%d%d%d",&sr,&sb,&sg,&m,&mo);n=sr+sb+sg;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j)scanf("%d",&change[i][j]);
	}
	for(int i=1;i<=n;++i)change[0][i]=i;
	for(int i=0;i<=m;++i){
		cnt=0;memset(xun,0,sizeof(xun));memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;++j)if(!vis[j]){
			vis[j]=1;int k=change[i][j];xun[++cnt]=1;
			while(k!=j)++xun[cnt],vis[k]=1,k=change[i][k];
		}
		memset(dp,0,sizeof(dp));
		dp[0][0][0][0]=1;
		for(int j=1;j<=cnt;++j){
			for(int r=0;r<=sr;++r){
				for(int b=0;b<=sb;++b){
					for(int g=0;g<=sg;++g){
						if(r>=xun[j])dp[j][r][b][g]=(dp[j][r][b][g]+dp[j-1][r-xun[j]][b][g])%mo;
						if(b>=xun[j])dp[j][r][b][g]=(dp[j][r][b][g]+dp[j-1][r][b-xun[j]][g])%mo;
						if(g>=xun[j])dp[j][r][b][g]=(dp[j][r][b][g]+dp[j-1][r][b][g-xun[j]])%mo;
					}
				}
			}
		}
		ans=(ans+dp[cnt][sr][sb][sg])%mo;
	}
	ans=ans*power(m+1,mo-2)%mo;
	printf("%d\n",ans);
	return 0;
}
