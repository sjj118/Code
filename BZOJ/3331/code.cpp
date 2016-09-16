#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=2e5+10,maxm=4e5+10,maxq=2e5+10;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,q,cnt;
bool iscut[maxn];
int ans[maxn];
struct Tree{
	int tot,head[maxn],to[maxm],next[maxm],c[maxn],pa[maxn][20],dep[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		pa[k][0]=pre;dep[k]=dep[pre]+1;
		rep(i,1,19)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
	}
	int lca(int a,int b){
		if(dep[a]>dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[b][i]]>=dep[a])b=pa[b][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	int getans(int k,int pre){
		int sum=c[k];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)sum+=getans(to[p],k);
		if(iscut[k])ans[k]+=sum;
		return sum;
	}
}T;
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],dfn[maxn],lowlink[maxn],clock,stack[maxn],top;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		dfn[k]=lowlink[k]=++clock;stack[++top]=k;int son=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			if(!dfn[to[p]]){
				dfs(to[p],k);dn(lowlink[k],lowlink[to[p]]);++son;
				if(lowlink[to[p]]>=dfn[k]){
					T.addedge(k,++cnt);iscut[k]=1;
					while(stack[top+1]!=to[p])T.addedge(cnt,stack[top--]);
				}
			}else dn(lowlink[k],dfn[to[p]]);
		}
		if(!pre&&son<=1)iscut[k]=0;
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);cnt=n;
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.dfs(1,0);
	T.dfs(1,0);
	rep(i,1,q){
		int u,v;scanf("%d%d",&u,&v);
		++T.c[u];++T.c[v];
		int lca=T.lca(u,v);
		--T.c[lca];--T.c[T.pa[lca][0]];
		if(!iscut[u])++ans[u];
		if(!iscut[v])++ans[v];
	}
	T.getans(1,0);
	rep(i,1,n)printf("%d\n",ans[i]);
	return 0;
}
