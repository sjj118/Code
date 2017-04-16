#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const int N=200000+10;
int n,m;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],size[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	LL f[N],g[N];
	int cnt[N][5];
	void dfs(int k,int pre){
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
		cnt[k][0]=1;
		size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			f[k]+=f[to[p]];
			f[k]+=g[to[p]]*size[k]+g[k]*size[to[p]];
			f[k]+=(LL)cnt[to[p]][0]*size[k];
			size[k]+=size[to[p]];
			rep(i,0,m-1)rep(j,1,m-1)if(i+j+1<=m)f[k]-=(LL)cnt[k][j]*cnt[to[p]][i];
			rep(i,0,m-1)cnt[k][(i+1)%m]+=cnt[to[p]][i];
			g[k]+=g[to[p]];
			g[k]+=cnt[to[p]][0];
		}
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n-1){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	G.dfs(1,0);
	printf("%I64d",G.f[1]);
	return 0;
}
