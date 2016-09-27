#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=25e4+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,k,h[maxn],sta[maxn],top;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],len[maxn<<1],dep[maxn],pa[maxn][20],mc[maxn][20],dfn[maxn],clock;
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	void dfs(int k,int pre){
		dep[k]=dep[pre]+1;pa[k][0]=pre;dfn[k]=++clock;
		rep(i,1,19)pa[k][i]=pa[pa[k][i-1]][i-1],mc[k][i]=min(mc[k][i-1],mc[pa[k][i-1]][i-1]);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)mc[to[p]][0]=len[p],dfs(to[p],k);
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	int mincut(int a,int b){
		if(dep[a]<dep[b])swap(a,b);int ans=inf;
		per(i,19,0)if(dep[pa[a][i]]>=dep[b])dn(ans,mc[a][i]),a=pa[a][i];
		if(a==b)return ans;
		per(i,19,0)if(pa[a][i]!=pa[b][i])dn(ans,mc[a][i]),dn(ans,mc[b][i]),a=pa[a][i],b=pa[b][i];
		dn(ans,mc[a][0]);dn(ans,mc[b][0]);
		return ans;
	}
}G;
struct Tree{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],len[maxn<<1],mark[maxn],root;
	void clear(int k,int pre){
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)clear(to[p],k);
		mark[k]=0;head[k]=0;
	}
	void clear(){clear(root,0);tot=0;root=0;}
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	LL dfs(int k,int pre){
		LL ans=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			if(mark[to[p]])ans+=len[p];
			else ans+=min((LL)len[p],dfs(to[p],k));
		}
		return ans;
	}
}T;
bool comp(int a,int b){return G.dfn[a]<G.dfn[b];}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int u,v,w;scanf("%d%d%d",&u,&v,&w);G.addedge(u,v,w);}
	G.dfs(1,0);
	int m;scanf("%d",&m);
	while(m--){
		scanf("%d",&k);bool flag=0;
		rep(i,1,k){scanf("%d",&h[i]);if(h[i]==1)flag=1;}
		if(!flag)h[++k]=1;
		sort(h+1,h+1+k,comp);T.clear();
		top=0;sta[++top]=h[1];T.mark[h[1]]=1;
		rep(i,2,k)if(h[i]!=h[i-1]){
			int x=h[i],f=G.lca(x,sta[top]);T.mark[x]=1;
			while(top>1&&G.dfn[sta[top-1]]>=G.dfn[f]){
				T.addedge(sta[top-1],sta[top],G.mincut(sta[top-1],sta[top]));--top;
			}
			if(sta[top]!=f)T.addedge(f,sta[top],G.mincut(f,sta[top])),sta[top]=f;
			sta[++top]=x;
		}
		while(--top)T.addedge(sta[top],sta[top+1],G.mincut(sta[top],sta[top+1]));
		T.root=1;
		G.mincut(19,2);
		printf("%lld\n",T.dfs(T.root,0));
	}
	return 0;
}
