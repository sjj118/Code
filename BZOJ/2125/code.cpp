#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=2e4+10,maxm=4e4+10;
inline void dn(int&x,int y){if(y<x)x=y;}
inline int abs(int x){return x>0?x:-x;}
int n,m,q,ps;
struct Tree{
	int tot,head[maxn],to[maxm],next[maxm],len[maxm],dep[maxn],height[maxn],pa[maxn][14],radius[maxn];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void dfs(int k,int pre){
		dep[k]=dep[pre]+1;pa[k][0]=pre;
		rep(i,1,13)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])height[to[p]]=height[k]+len[p],dfs(to[p],k);
	}
	int jump(int k,int p){
		per(i,13,0)if(dep[pa[k][i]]>=p)k=pa[k][i];
		return k;
	}
	int LCA(int a,int b){
		if(dep[a]>dep[b])swap(a,b);
		b=jump(b,dep[a]);
		if(a==b)return a;
		per(i,13,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	int dis(int a,int b){
		int lca=LCA(a,b);
		if(lca<=n)return height[a]+height[b]-2*height[lca];
		int u=jump(a,dep[lca]+1),v=jump(b,dep[lca]+1);
		int d=abs(radius[u]-radius[v]);
		return height[a]-height[u]+height[b]-height[v]+min(d,radius[lca]-d);
	}
}T;
struct Cactus{
	int tot,head[maxn],to[maxm],next[maxm],len[maxm],dfn[maxn],lowlink[maxn],clock;
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	int sta[maxn],top;
	void dfs(int k,int pre){
		lowlink[k]=dfn[k]=++clock;sta[++top]=k;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			if(dfn[to[p]]){
				dn(lowlink[k],dfn[to[p]]);
				if(dfn[to[p]]<dfn[k])T.radius[k]=T.radius[to[p]]+len[p];
			}else{
				dfs(to[p],k);dn(lowlink[k],lowlink[to[p]]);
				if(lowlink[to[p]]>dfn[k])--top;
				if(lowlink[to[p]]==dfn[k]){
					T.ins(k,++ps,0);T.radius[ps]=T.radius[to[p]]+len[p];
					while(top){
						T.ins(ps,sta[top],min(T.radius[sta[top]],T.radius[ps]-T.radius[sta[top]]));
						if(sta[top--]==to[p])break;
					}
				}
				if(lowlink[to[p]]>dfn[k])T.ins(k,to[p],len[p]);
				if(lowlink[to[p]]<dfn[k])T.radius[k]=T.radius[to[p]]+len[p];
			}
		}
	}
}C;
int main(){
	scanf("%d%d%d",&n,&m,&q);ps=n;
	rep(i,1,m){int u,v,w;scanf("%d%d%d",&u,&v,&w);C.addedge(u,v,w);}
	C.dfs(1,0);
	T.dfs(1,0);
	rep(i,1,q){int u,v;scanf("%d%d",&u,&v);printf("%d\n",T.dis(u,v));}
	return 0;
}
