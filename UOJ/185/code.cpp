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
LL g[maxn][maxn][maxv];
int a[maxn],cnt,size[maxn];
void fwt(LL*a,int l,int r){
	if(l==r)return;
	int m=(l+r)>>1;
	fwt(a,l,m);fwt(a,m+1,r);
	rep(i,0,m-l){
		LL x=a[l+i],y=a[m+1+i];
		a[l+i]=x+y;a[m+1+i]=x-y;
	}
}
void ufwt(LL*a,int l,int r){
	if(l==r)return;
	int m=(l+r)>>1;
	ufwt(a,l,m);ufwt(a,m+1,r);
	rep(i,0,m-l){
		LL x=a[l+i],y=a[m+1+i];
		a[l+i]=(x+y)/2;a[m+1+i]=(x-y)/2;
	}
}
LL tmp[maxv];
void getdp(){
	rep(i,1,cnt){
		rep(q,1,n)fwt(dp[a[i]][q],0,v-1);
//		rep(p,1,n){
//			rep(j,0,v-1)g[i][p][j]=0;
//			fwt(g[i-1][p],0,v-1);
//			rep(q,1,n)if(w[p][q]){
//				rep(j,0,v-1){
//					tmp[j]=g[i-1][p][j]*dp[a[i]][q][j];
//				}
//				ufwt(tmp,0,v-1);
//				rep(j,0,v-1){
//					g[i][p][j]+=tmp[j];
//				}
//			}
//			ufwt(g[i-1][p],0,v-1);
//		}
		rep(q,1,n)ufwt(dp[a[i]][q],0,v-1);
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
		rep(i,1,n)rep(j,0,v-1)if(co[j]==size[k])dp[k][i][j]=g[cnt][i][j];
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
	printf("%lld",ans);
	return 0;
}
