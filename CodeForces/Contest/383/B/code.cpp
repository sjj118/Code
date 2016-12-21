#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef pair<int,int> pii;
const int N=1000+10,M=2e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,W,dp[2][N],w[N],b[N],vis[N];
struct Graph{
	int tot,head[N],to[M],next[M];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	pii dfs(int k,int x){
		vis[k]=1;
		pii ret=mp(w[k],b[k]);
		rep(i,0,W-w[k])up(dp[x][i+w[k]],dp[x^1][i]+b[k]);
		for(int p=head[k];p;p=next[p])if(!vis[to[p]]){
			pii tmp=dfs(to[p],x);
			ret.fi+=tmp.fi;ret.se+=tmp.se;
		}
		return ret;
	}
}G;
int main(){
	scanf("%d%d%d",&n,&m,&W);
	rep(i,1,n)scanf("%d",&w[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	rep(i,1,m){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	int x=0;
	rep(i,1,n)if(!vis[i]){
		x^=1;
		rep(j,0,W)dp[x][j]=dp[x^1][j];
		pii sum=G.dfs(i,x);
		rep(j,0,W-sum.fi)up(dp[x][j+sum.fi],dp[x^1][j]+sum.se);
	}
	int ans=0;
	rep(i,0,W)up(ans,dp[x][i]);
	printf("%d",ans);
	return 0;
}
