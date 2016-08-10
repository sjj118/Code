#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1010
#define LL long long

using namespace std;

int T,n,m,M,q[maxn],p[maxn];
LL dp[maxn][maxn],C[maxn][maxn];
LL ans;
LL power(LL base,int exp){
	LL ans=1;
	while(exp){
		if(exp&1)ans=ans*base%M;
		base=base*base%M;
		exp>>=1;
	}
	return ans;
}
bool work(){
	memset(p,0,sizeof(p));memset(q,0,sizeof(q));memset(dp,0,sizeof(dp));
	scanf("%d%d%d",&n,&m,&M);
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	}
	for(int i=1;i<=m;++i)scanf("%*d%d",&q[i]);
	for(int i=1;i<=m;++i){
		while(p[q[i]])++q[i];
		if(q[i]>n)return 0;
		p[q[i]]=1;
	}
	for(int i=1,j=1,tmp=0;i<=n;++i){
		++tmp;
		if(!p[i])q[j++]=tmp,tmp=0;
	}
	dp[0][0]=1;
	for(int i=1;i<=n-m;++i){
		for(int j=i;j<=n-m;++j){
			int tmp=1;
			for(int k=0;k<=j-i+1;++k,tmp=(LL)tmp*q[i]%M)dp[i][j]=(dp[i][j]+dp[i-1][j-k]*C[n-m-j+k][k]%M*tmp)%M;
		}
	}
	ans=dp[n-m][n-m];
	return 1;
}

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		if(work())printf("YES %d\n",ans);else printf("NO\n");
	}
	return 0;
}
