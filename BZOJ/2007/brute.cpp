#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=500+10,maxp=3e5,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,map[maxn][maxn],w1[maxn][maxn],w2[maxn][maxn],w3[maxn][maxn],w4[maxn][maxn],ans=inf;
void dfs(int x,int y){
	if(y==n+2)return dfs(x+1,1);
	if(x==n+1&&y==n+1){
		int tmp=0;
		rep(i,1,n+1)rep(j,1,n)tmp+=max(0,map[i][j+1]-map[i][j])*w1[i][j];
		rep(i,1,n)rep(j,1,n+1)tmp+=max(0,map[i+1][j]-map[i][j])*w2[i][j];
		rep(i,1,n+1)rep(j,1,n)tmp+=max(0,map[i][j]-map[i][j+1])*w3[i][j];
		rep(i,1,n)rep(j,1,n+1)tmp+=max(0,map[i][j]-map[i+1][j])*w4[i][j];
		dn(ans,tmp);
		return;
	}
	map[x][y]=0;dfs(x,y+1);
	map[x][y]=1;dfs(x,y+1);
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n+1)rep(j,1,n)scanf("%d",&w1[i][j]);
	rep(i,1,n)rep(j,1,n+1)scanf("%d",&w2[i][j]);
	rep(i,1,n+1)rep(j,1,n)scanf("%d",&w3[i][j]);
	rep(i,1,n)rep(j,1,n+1)scanf("%d",&w4[i][j]);
	map[1][1]=0;map[n+1][n+1]=1;
	dfs(1,2);
	printf("%d",ans);
	return 0;
}
