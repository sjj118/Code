#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxm=4e5+10,maxq=2e5+10;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,q;
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],dfn[maxn],lowlink[maxn],vis[maxn],sign,stack[maxn],top,id[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k){
		vis[k]=1;dfn[k]=lowlink[k]=++sign;stack[++top]=k;
		for(int p=head[k];p;p=next[p])if(!vis[to[p]])dfs(to[p]),dn(lowlink[k],lowlink[to[p]]);else dn(lowlink[k],dfn[to[p]]);
		if(lowlink[k]==dfn[k])while(stack[top+1]!=k)id[stack[top--]]=k;
	}
}G;
int ans[maxn];
struct Tree{
	int tot,head[maxn],to[maxm],next[maxm],vis[maxn],c[maxn],pa[maxn][20];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void dfs(int k,int pre){
		vis[k]=1;pa[k][0]=pre;dep[k]=dep[pre]+1;
		rep(i,1,19)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])if(!vis[to[p]])dfs(to[p],k);
	}
	int lca(int a,int b){
		if(dep[a]>dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[b][i]]>=dep[a])b=pa[b][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	void getans(int k,int h){

	}
}T;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.dfs(1);
	rep(k,1,n)for(int p=G.head[k];p;p=G.next[p])if(G.id[k]!=G.id[to[p]])T.ins(G.id[k],G.id[to[p]]);
	T.dfs(1,0);
	rep(i,1,q){int u,v;scanf("%d%d",&u,&v);++G.c[u];++G.c[v];int lca=G.lca(u,v);--G.c[lca];--G.c[G.pa[lca][0]];}
	cls(T.vis);
	T.getans(1,0);
	return 0;
}
