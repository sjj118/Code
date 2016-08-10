#include<iostream>
#include<cstdio>
#define ls son[k][0]
#define rs son[k][1]
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=2e5+10,maxp=1e7;
using namespace std;
inline void dn(int&x,int y){if(y<x)x=y;}
inline int read(){int tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,root,q,qq,mn[maxn];
struct SGT{
	int tot,son[maxp][2],val[maxp],root[maxn];
	int modify(int p,int k,int l,int r){
		int t=++tot;
		if(l==r)return val[t]=val[k]+1,t;
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=modify(p,ls,l,m),son[t][1]=rs;
		else son[t][0]=ls,son[t][1]=modify(p,rs,m+1,r);
		val[t]=val[son[t][0]]+val[son[t][1]];
		return t;
	}
	int getsum(int p,int k,int l,int r){
		if(p<=0||!k)return 0;
		if(r<=p)return val[k];
		int m=(l+r)>>1;
		if(p<=m)return getsum(p,ls,l,m);
		return getsum(p,ls,l,m)+getsum(p,rs,m+1,r);
	}
}T;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],pa[maxn][21],dep[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		rep(i,1,20)pa[k][i]=pa[pa[k][i-1]][i-1];if(!pre)dep[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dep[to[p]]=dep[k]+1,dfs(to[p],k);
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,20,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,20,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	void work(int k,int pre){
		T.root[k]=T.modify(mn[k],T.root[pre],1,q);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)work(to[p],k);
	}
}G;
struct Query{
	int x,y,c,t;
}qu[maxn];
#include<ctime>
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n)if(G.pa[i][0]=read())G.addedge(G.pa[i][0],i);else root=i;
	G.dfs(root,0);
	q=read();
	rep(i,1,n)mn[i]=q;
	rep(i,1,q){
		int op=read();
		if(op==1)++qq,qu[qq].x=read(),qu[qq].y=read(),qu[qq].c=read(),qu[qq].t=i;
		else dn(mn[read()],i);
	}
	G.work(root,0);
	rep(i,1,qq){
		int x=qu[i].x,y=qu[i].y,c=qu[i].c,lca=G.lca(x,y),t=qu[i].t;
		printf("%d %d\n",G.dep[x]+G.dep[y]-2*G.dep[lca]+1,T.getsum(t-c-1,T.root[x],1,q)+T.getsum(t-c-1,T.root[y],1,q)-2*T.getsum(t-c-1,T.root[lca],1,q)+(mn[lca]<t-c));
	}
	cerr<<clock();
	return 0;
}
