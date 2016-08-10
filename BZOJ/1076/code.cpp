#include<iostream>
#include<cstdio>
#define maxn 16
#define maxk 110

using namespace std;

int n,k,c[maxn],pre[maxn];
double dp[maxk][1<<(maxn-1)];

int main(){
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
		int x;scanf("%d",&x);
		while(x)pre[i]|=1<<(x-1),scanf("%d",&x);
	}
	for(int i=1;i<=k;++i){
		for(int j=0;j<1<<n;++j){
			for(int p=1;p<=n;++p){
				dp[i][j]+=1.0/n*max(((pre[p]&j)==pre[p])*(dp[i-1][j|(1<<(p-1))]+c[p]),dp[i-1][j]);
			}
		}
	}
	printf("%lf",dp[k][0]);
	return 0;
}
