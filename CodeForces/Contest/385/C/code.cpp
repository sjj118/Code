#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=20,V=(1<<16)+10,inf=1e9;
inline bool vaild(char c){return c=='R'||c=='B';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,c[N],r[N],b[N],dp[V][N*N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		c[i]=gc()=='B';
		scanf("%d%d",&r[i],&b[i]);
	}
	int v=1<<n;
	rep(i,0,v-1)rep(j,0,n*(n-1)/2)dp[i][j]=-inf;
	dp[0][0]=0;
	rep(i,0,v-1){
		int tr=0,tb=0;
		rep(j,0,n-1)if((i>>j)&1){if(c[j+1]==0)++tr;else ++tb;}
		rep(j,0,tr*(tr+tb))if(dp[i][j]>=0){
			rep(k,0,n-1)if(((i>>k)&1)==0){
				up(dp[i|(1<<k)][j+max(0,tr-max(0,tr-r[k+1]))],dp[i][j]+max(0,tb-max(0,tb-b[k+1])));
			}
		}
	}
	int sr=0,sb=0;
	rep(i,1,n)sr+=r[i],sb+=b[i];
	int ans=max(sr,sb);
	rep(i,0,n*(n-1)/2)dn(ans,max(sr-i,sb-dp[v-1][i]));
	printf("%d",ans+n);
	return 0;
}
