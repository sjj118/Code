#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::min;
typedef long long LL;
const int N=300+10,mo=1e9+7;
int n,k;
int size[N];
LL dp[N][N],C[N][N],fact[N];
void calc(int now,int*a,int p){
	static LL f[N][N];
	cls(f);
	f[0][1]=1;f[0][0]=1;
	int sz=1;
	rep(i,1,p){
		rep(j,0,sz)rep(k,0,size[a[i]])rep(q,0,min(j,k))f[i][j+k-2*q]=(f[i][j+k-2*q]+f[i-1][j]*dp[a[i]][k]%mo*C[j][q]%mo*C[k][q]%mo*fact[q]%mo)%mo;
		sz+=size[a[i]];
	}
	rep(i,0,min(sz,k))dp[now][i]=f[p][i];
}
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k),size[k]+=size[to[p]];
		static int son[N];
		int cnt=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)son[++cnt]=to[p];
		calc(k,son,cnt);
	}
}G;
int main(){
	scanf("%d%d",&n,&k);
	fact[0]=1;rep(i,1,n)fact[i]=fact[i-1]*i%mo;
	rep(i,0,n){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.dfs(1,0);
	printf("%lld",dp[1][0]);
	return 0;
}
