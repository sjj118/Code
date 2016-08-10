#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
#define pa pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn=510;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'))c=getchar();return c;}
int n,m,a[maxn][maxn],dis[maxn][maxn];
int ql,qr;
pa q[maxn*maxn];
bool avail(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m;}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)a[i][j]=gc()-'0',dis[i][j]=1e9;
	ql=qr=0;q[qr++]=mp(1,1);dis[1][1]=0;
	while(ql!=qr){
		int x=q[ql].fi,y=q[ql++].se;
		rep(i,0,3)if(avail(x+dx[i]*a[x][y],y+dy[i]*a[x][y])&&dis[x][y]+1<dis[x+dx[i]*a[x][y]][y+dy[i]*a[x][y]]){
			dis[x+dx[i]*a[x][y]][y+dy[i]*a[x][y]]=dis[x][y]+1;q[qr++]=mp(x+dx[i]*a[x][y],y+dy[i]*a[x][y]);
		}
	}
	if(dis[n][m]==1e9)printf("IMPOSSIBLE");else printf("%d",dis[n][m]);
	return 0;
}
