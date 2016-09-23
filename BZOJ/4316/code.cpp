#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxm=12e4+10;
inline void dn(int&x,int y){if(y<x)x=y;}
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,ps,f[maxn][2],g[maxn][2],a[maxn];
int dp(int l,int r){
	g[l-1][0]=g[l-1][1]=0;
	rep(i,l,r)g[i][0]=f[a[i]][0]+max(g[i-1][0],g[i-1][1]),g[i][1]=f[a[i]][1]+g[i-1][0];
	return max(g[r][0],g[r][1]);
}
struct Tree{
	int tot,head[maxn],to[maxm],next[maxm];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void dfs(int k){
		for(int p=head[k];p;p=next[p])dfs(to[p]);
		if(k<=n){
			for(int p=head[k];p;p=next[p])f[k][0]+=max(f[to[p]][0],f[to[p]][1]);
			for(int p=head[k];p;p=next[p])f[k][1]+=f[to[p]][0];f[k][1]++;
		}else{
			int l=1,r=0;
			for(int p=head[k];p;p=next[p])a[++r]=to[p];
			f[k][1]=dp(l,r);
			f[k][0]=dp(l+1,r-1)+f[a[l]][0]+f[a[r]][0];
		}
	}
}T;
struct Cactus{
	int tot,head[maxn],to[maxm],next[maxm],dfn[maxn],lowlink[maxn],clock;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int sta[maxn],top;
	void dfs(int k,int pre){
		dfn[k]=lowlink[k]=++clock;sta[++top]=k;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			if(dfn[to[p]])dn(lowlink[k],dfn[to[p]]);
			else{
				dfs(to[p],k);dn(lowlink[k],lowlink[to[p]]);
				if(lowlink[to[p]]>dfn[k])T.ins(k,to[p]),--top;
				if(lowlink[to[p]]==dfn[k]){
					T.ins(k,++ps);
					while(top){
						T.ins(ps,sta[top]);
						if(sta[top--]==to[p])break;
					}
				}
			}
		}
	}
}G;
int main(){
	scanf("%d%d",&n,&m);ps=n;
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.dfs(1,0);
	T.dfs(1);
	printf("%d\n",max(f[1][0],f[1][1]));
	return 0;
}
