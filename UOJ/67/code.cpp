#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,iscut[maxn];
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],deg[maxn],dfn[maxn],lowlink[maxn],clock;
	Graph(){tot=1;}
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;++deg[a];}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		dfn[k]=lowlink[k]=++clock;int sons=0;
		for(int p=head[k];p;p=next[p])if((p>>1)!=(pre>>1)){
			if(dfn[to[p]])dn(lowlink[k],dfn[to[p]]);
			else{
				dfs(to[p],p);++sons;
				dn(lowlink[k],lowlink[to[p]]);
				if(lowlink[to[p]]>=dfn[k]&&pre)iscut[k]=1;
			}
		}
		if(!pre&&sons>1)iscut[k]=1;
	}
}G;
int ans[maxn],cnt;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.dfs(1,0);
	rep(i,1,n)if(!iscut[i]&&G.deg[i]==m-n+2)ans[++cnt]=i;
	printf("%d\n",cnt);
	rep(i,1,cnt)printf("%d ",ans[i]);
	return 0;
}
