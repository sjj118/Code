#include<bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=55,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,m,k,vis[maxn][maxn],cnt;
char a[maxn][maxn];
struct Lake{
	int size,x,y;
	Lake(int _x=0,int _y=0,int _s=0){x=_x;y=_y;size=_s;}
}lake[maxn*maxn];
int dfs(int x,int y){
	vis[x][y]=1;int size=1;
	rep(i,0,3){
		int sx=x+dx[i],sy=y+dy[i];
		if(sx>=1&&sx<=n&&sy>=1&&sy<=m){
			if(a[sx][sy]=='*'||vis[sx][sy])continue;
			int t=dfs(sx,sy);
			if(t==-1||size==-1)size=-1;
			else size+=t;
		}else size=-1;
	}
	return size;
}
void fill(int x,int y){
	a[x][y]='*';
	rep(i,0,3){
		int sx=x+dx[i],sy=y+dy[i];
		if(sx>=1&&sx<=n&&sy>=1&&sy<=m){
			if(a[sx][sy]=='*')continue;
			fill(sx,sy);
		}
	}
}
bool cmp(Lake a,Lake b){return a.size<b.size;}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)rep(j,1,m)scanf("\n%c",&a[i][j]);
	rep(i,1,n)rep(j,1,m)if(!vis[i][j]&&a[i][j]=='.'){
		int t=dfs(i,j);
		if(t!=-1)lake[++cnt]=Lake(i,j,t);
	}
	sort(lake+1,lake+1+cnt,cmp);int ans=0;
	rep(i,1,cnt-k)fill(lake[i].x,lake[i].y),ans+=lake[i].size;
	printf("%d\n",ans);
	rep(i,1,n){
		rep(j,1,m)printf("%c",a[i][j]);puts("");
	}
	return 0;
}
