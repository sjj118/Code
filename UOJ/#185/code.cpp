#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=17+3,maxv=(1<<17)+10,maxm=17*17+10;
int n,m,w[maxn][maxn],v,co[maxv],lg[maxv];
LL dp[maxn][maxn][maxv];
int g[maxn][maxn][maxv];
int a[maxn],cnt,size[maxn];
void getdp(){
	int tmp=1;
	rep(i,1,cnt){
		tmp+=size[a[i]];
		rep(j,0,v-1)if(co[j]==tmp){
			int x=j,p;
			while(x){
				p=lg[x];x-=1<<(p-1);
				g[i][p][j]=0;
			}
			for(int t=j;t;t=(t-1)&j)if(co[t]==tmp-size[a[i]]){
				int x=t,p;
				while(x){
					p=lg[x];x-=1<<(p-1);
					int ss=j^t,q;
					while(ss){
						q=lg[ss];ss-=1<<(q-1);
						if(w[p][q])g[i][p][j]+=g[i-1][p][t]*dp[a[i]][q][j^t];
					}
				}
			}
		}
	}
}
struct Tree{
	int tot,head[maxn],to[maxm],next[maxm];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k),size[k]+=size[to[p]];
		cnt=0;for(int p=head[k];p;p=next[p])if(to[p]!=pre)a[++cnt]=to[p];
		getdp();
		rep(i,1,n)rep(j,0,v-1)dp[k][i][j]=g[cnt][i][j];
	}
}T;
int main(){
	scanf("%d%d",&n,&m);v=1<<n;
	rep(i,1,v-1)co[i]=co[i>>1]+(i&1);
	rep(i,1,v-1)lg[i]=lg[i>>1]+1;
	rep(i,1,m){int x,y;scanf("%d%d",&x,&y);w[x][y]=w[y][x]=1;}
	rep(i,1,n-1){int x,y;scanf("%d%d",&x,&y);T.addedge(x,y);}
	rep(p,1,n)g[0][p][1<<(p-1)]=1;
	T.dfs(1,0);
	LL ans=0;
	rep(i,1,n)ans+=dp[1][i][v-1];
	printf("%d",ans);
	return 0;
}
