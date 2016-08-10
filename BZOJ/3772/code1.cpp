#include<iostream>
#include<cstdio>
#define mp make_pair
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=1e5+10,maxp=1e6;

int n,m;
LL p;
LL gcd(LL a,LL b){
	if(!b)return a;
	return gcd(b,a%b);
}
struct SGT{
	int val[maxp];
	void modify(int p,int v,int k,int l,int r){
		if(l==r){val[k]+=v;return;}
		int m=(l+r)>>1;
		if(p<=m)modify(p,v,k<<1,l,m);
		else modify(p,v,k<<1|1,m+1,r);
		val[k]=val[k<<1]+val[k<<1|1];
	}
	int getsum(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return val[k];
		int m=(l+r)>>1;
		if(rr<=m)return getsum(ll,rr,k<<1,l,m);
		if(ll>m)return getsum(ll,rr,k<<1|1,m+1,r);
		return getsum(ll,rr,k<<1,l,m)+getsum(ll,rr,k<<1|1,m+1,r);
	}
}T;
struct Linker{
	int tot,head[maxn],next[maxn<<2],f[maxn<<2];
	pii val[maxn<<2];
	void ins(int a,pii v,int c){val[++tot]=v;next[tot]=head[a];head[a]=tot;f[tot]=c;}
	void solve(int k){
		for(int q=head[k];q;q=next[q]){
			p+=f[q]*T.getsum(val[q].first,val[q].second,1,1,n);
		}
	}
}llink;
struct Path{
	int tot,head[maxn],next[maxn<<1],to[maxn<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void work(int k){
		for(int p=head[k];p;p=next[p])T.modify(to[p],1,1,1,n);
	}
}path;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],pa[maxn][20],dep[maxn],dfn[maxn],last[maxn],sign;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		for(int i=1;i<20;++i)pa[k][i]=pa[pa[k][i-1]][i-1];if(!pre)dep[k]=1;dfn[k]=last[k]=++sign;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)pa[to[p]][0]=k,dep[to[p]]=dep[k]+1,dfs(to[p],k),last[k]=max(last[k],last[to[p]]);
	}
	int getpa(int a,int d){
		for(int i=19;i>=0;--i)if(dep[pa[a][i]]>=d)a=pa[a][i];
		return a;
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		for(int i=19;i>=0;--i)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		for(int i=19;i>=0;--i)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	void work(int k,int pre){
		if(!pre){
			sign=0;
			llink.solve(0);
		}
		path.work(++sign);
		llink.solve(sign);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)work(to[p],k);
	}
}G;
int read(){
	int tmp=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);
	}
	G.dfs(1,0);
	for(int i=1;i<=m;++i){
		int u,v;scanf("%d%d",&u,&v);
		if(G.dfn[u]>G.dfn[v])swap(u,v);
		path.ins(G.dfn[u],G.dfn[v]);path.ins(G.dfn[v],G.dfn[u]);
		int lca=G.lca(u,v);
		if(u==lca){
			int w=G.getpa(v,G.dep[u]+1);
			llink.ins(0,mp(G.dfn[v],G.last[v]),-1);
			llink.ins(G.dfn[w]-1,mp(G.dfn[v],G.last[v]),1);
			llink.ins(G.last[w],mp(G.dfn[v],G.last[v]),-1);
			llink.ins(n,mp(G.dfn[v],G.last[v]),1);
		}else{
			llink.ins(G.dfn[u]-1,mp(G.dfn[v],G.last[v]),-1);
			llink.ins(G.last[u],mp(G.dfn[v],G.last[v]),1);
		}
	}
	G.work(1,0);
	p-=m;
	LL q=(LL)m*(m-1)/2,d=gcd(p,q);
	printf("%lld/%lld",p/d,q/d);
	return 0;
}
