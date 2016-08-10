#include<iostream>
#include<cstdio>
#define maxn 100010
#define maxm 1010
#define LL long long

using namespace std;

int c[5],tot,d[5],s;
LL dp[5][maxn];
LL dfs(int k,int num,int sum){
	if(sum>s)return 0;
	if(k==5)return (num&1?-1:1)*dp[4][s-sum];
	return dfs(k+1,num,sum)+dfs(k+1,num+1,sum+(d[k]+1)*c[k]);
}

int main(){
	scanf("%d%d%d%d%d",&c[1],&c[2],&c[3],&c[4],&tot);
	dp[0][0]=1;
	for(int i=1;i<=4;++i){
		for(int j=0;j<=100000;++j){
			dp[i][j]=(dp[i][j]+dp[i-1][j]);
			if(j>=c[i])dp[i][j]=(dp[i][j]+dp[i][j-c[i]]);
		}
	}
	for(int i=1;i<=tot;++i){
		scanf("%d%d%d%d%d",&d[1],&d[2],&d[3],&d[4],&s);
		printf("%lld\n",dfs(1,0,0));
	}
	return 0;
}
