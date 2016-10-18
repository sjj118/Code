#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=1e3+30,mo=1e9+7;
inline void ck(int&x){if(x<0)x+=mo;if(x>=mo)x-=mo;}
inline void ad(int&x,int y){x+=y;ck(x);};
int n,m,v[maxn],dp[maxn][maxn];
int tmp[maxn];
void tf(int*a,int l,int r){
	if(l==r)return;
	int m=(l+r)>>1;
	tf(a,l,m);tf(a,m+1,r);
	rep(i,l,r)tmp[i]=a[i];
	rep(i,l,m)a[i]=(tmp[i]+tmp[i+m-l+1]),ck(a[i]);
	rep(i,m+1,r)a[i]=(tmp[i-m+l-1]-tmp[i]),ck(a[i]);
}
void utf(int*a,int l,int r){
	if(l==r)return;
	int m=(l+r)>>1;
	utf(a,l,m);utf(a,m+1,r);
	rep(i,l,r)tmp[i]=a[i];
	rep(i,l,m)a[i]=(LL)(tmp[i]+tmp[i+m-l+1])*500000004%mo;
	rep(i,m+1,r)a[i]=(LL)(tmp[i-m+l-1]-tmp[i])*500000004%mo,ck(a[i]);
}
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1];
	void clear(){tot=0;cls(head);}
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)++dp[to[p]][0],tf(dp[to[p]],0,m-1);
		dp[k][v[k]]=1;tf(dp[k],0,m-1);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)rep(i,0,m-1)dp[k][i]=(LL)dp[k][i]*dp[to[p]][i]%mo;
		utf(dp[k],0,m-1);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)utf(dp[to[p]],0,m-1),--dp[to[p]][0];
	}
}G;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		G.clear();
		scanf("%d%d",&n,&m);cls(dp);
		rep(i,1,n)scanf("%d",&v[i]);
		rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
		G.dfs(1,0);
		rep(i,1,n)rep(j,0,m-1)ad(dp[0][j],dp[i][j]);
		printf("%d",dp[0][0]);rep(i,1,m-1)printf(" %d",dp[0][i]);puts("");
	}
	return 0;
}
