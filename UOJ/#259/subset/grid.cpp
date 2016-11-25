#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=15,V=(1<<12)+10,M=20+5;
int n=12,v=1<<n,m=20,p=998244353;
void ad(int&x,int y){x+=y;if(x>=p)x-=p;}
int dp[N][V][M];
int main(){
	dp[0][0][0]=1;
	rep(i,1,n){
		rep(j,0,v-1){
			bool flag=0;
			rep(k,0,n-2)if(((j>>k)&1)&&((j>>(k+1))&1))flag=1;
			if(flag)continue;
			int num=0;
			rep(k,0,n-1)num+=(j>>k)&1;
			rep(k,num,m){
				int p=(v-1)^j;
				for(int q=p;;q=(q-1)&p){
					ad(dp[i][j][k],dp[i-1][q][k-num]);
					if(q==0)break;
				}
			}
		}
	}
	int ans=0;
	rep(j,0,v-1)ad(ans,dp[n][j][m]);
	printf("%d",ans);
}
