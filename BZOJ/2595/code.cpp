#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 11
#define inf 1e9

using namespace std;

const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,map[maxn][maxn],dp[1<<maxn][maxn][maxn],pre[1<<maxn][maxn][maxn],s[maxn][maxn],k;
int st[maxn][maxn];
queue<int> Q;int inq[maxn*maxn<<maxn];
inline void push(int x){if(!inq[x])Q.push(x);inq[x]=1;}
inline void pop(){inq[Q.front()]=0;Q.pop();}
inline int h(int sta,int x,int y){return sta*maxn*maxn+x*maxn+y;}
inline void fh(int h,int&sta,int&x,int&y){y=h%maxn;h/=maxn;x=h%maxn;h/=maxn;sta=h;}
inline bool avail(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m;}
inline bool updata(int&x,int y){if(y<x){x=y;return 1;}return 0;}
void spfa(){
	while(Q.size()){
		int sta,x,y;fh(Q.front(),sta,x,y);pop();
		for(int i=0;i<4;++i)if(avail(x+dir[i][0],y+dir[i][1])/*&&((sta|s[x+dir[i][0]][y+dir[i][1]])==sta)*/){
			if(updata(dp[sta][x+dir[i][0]][y+dir[i][1]],dp[sta][x][y]+map[x+dir[i][0]][y+dir[i][1]]))push(h(sta,x+dir[i][0],y+dir[i][1])),pre[sta][x+dir[i][0]][y+dir[i][1]]=h(sta,x,y);
		}
	}
}
void go(int p){
	if(!p)return;
	int sta,x,y;fh(p,sta,x,y);
	if(!st[x][y])st[x][y]=-1;
	go(pre[sta][x][y]);
	if(pre[sta][x][y]/maxn/maxn!=sta)go(pre[sta^(pre[sta][x][y]/maxn/maxn)][x][y]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){scanf("%d",&map[i][j]);if(!map[i][j])st[i][j]=1<<k,s[i][j]=++k;}
	for(int x=0;x<maxn;++x)for(int y=0;y<maxn;++y)dp[0][x][y]=map[x][y];
	for(int i=0;i<1<<maxn;++i){
		for(int x=1;x<=n;++x)for(int y=1;y<=m;++y){
			dp[i][x][y]=inf;
			if(st[x][y]==i)dp[i][x][y]=0;
		}
	}
	for(int sta=1;sta<1<<k;++sta){
		for(int x=1;x<=n;++x){
			for(int y=1;y<=m;++y){
				for(int j=(sta-1)&sta;j;j=(j-1)&sta)if(updata(dp[sta][x][y],dp[j][x][y]+dp[sta^j][x][y]-map[x][y]))pre[sta][x][y]=h(j,x,y);
				if(dp[sta][x][y]<inf)push(h(sta,x,y));
			}
		}
		spfa();
	}
	int ans=inf,p;
	for(int x=1;x<=n;++x)for(int y=1;y<=m;++y)ans=min(ans,dp[(1<<k)-1][x][y]);
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(st[i][j]){p=h((1<<k)-1,i,j);}
	go(p);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(st[i][j]==-1)printf("o");
			else if(st[i][j]==0)printf("_");
			else printf("x");
		}
		printf("\n");
	}
	return 0;
}
