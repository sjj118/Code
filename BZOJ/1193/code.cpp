#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
using namespace std;

int xp,yp,xs,ys,dp[30][30];

int main(){
	scanf("%d%d%d%d",&xp,&yp,&xs,&ys);
	if(xp>xs)swap(xp,xs);
	if(yp>ys)swap(yp,ys);
	rep(i,0,29)rep(j,0,29)dp[i][j]=1e9;
	rep(i,-10,10)
	rep(j,-10,10){
		int x=xs+i-xp,y=ys+j-yp;
		if((2*x+y)%4==0&&(2*x+y)>=0&&(y-x*2)%4==0&&(y-x*2)>=0)dp[i+15][j+15]=min(dp[i+15][j+15],(y)/2);
		if((2*x-y)%3==0&&(2*x-y)>=0&&(2*y-x)%3==0&&(2*y-x)>=0)dp[i+15][j+15]=min(dp[i+15][j+15],(x+y)/3);
		if((x+2*y)%4==0&&(x+2*y)>=0&&(x-2*y)%4==0&&(x-2*y)>=0)dp[i+15][j+15]=min(dp[i+15][j+15],x/2);
	}
	rep(i,1,100){
		rep(x,-10,10)rep(y,-10,10){
			dp[x+15][y+15]=min(dp[x+15][y+15],dp[x+15+1][y+15+2]+1);
			dp[x+15][y+15]=min(dp[x+15][y+15],dp[x+15+2][y+15+1]+1);
			dp[x+15][y+15]=min(dp[x+15][y+15],dp[x+15-1][y+15+2]+1);
			dp[x+15][y+15]=min(dp[x+15][y+15],dp[x+15-2][y+15+1]+1);
			dp[x+15][y+15]=min(dp[x+15][y+15],dp[x+15-1][y+15-2]+1);
			dp[x+15][y+15]=min(dp[x+15][y+15],dp[x+15-2][y+15-1]+1);
			dp[x+15][y+15]=min(dp[x+15][y+15],dp[x+15+1][y+15-2]+1);
			dp[x+15][y+15]=min(dp[x+15][y+15],dp[x+15+2][y+15-1]+1);
		}
	}
	printf("%d\n",dp[15][15]);
	return 0;
}
