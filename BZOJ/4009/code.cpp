#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define lson son[k][0]
#define rson son[k][1]
const int maxn=4e4+10,maxp=1e7,inf=1e9;
using namespace std;

int n,P,Q,a[maxn],b[maxn],c[maxn];
int read(){
	int tmp=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}
bool comp(int*a,int*b){return *a<*b;}
struct Lisan{
	int*val[maxn],tot,maxval,real[maxn];
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,comp);
		for(int i=1,last=-1;i<=tot;++i){
			if(*val[i]>last)real[++maxval]=last=*val[i];
			*val[i]=maxval;
		}
	}
}lisan;
map<int,int> root[maxn<<2];
struct Lianbiao{
	int tot,head[maxn<<2],next[maxn<<2],val[maxn<<2];
	void ins(int a,int b){val[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void del(int a){head[a]=next[head[a]];}
	int back(int a){return val[head[a]];}
}que;
struct SGT{
	int tot,son[maxp][2],val[maxp];
	int modify(int p,int v,int k,int l,int r){
		int t=++tot;
		if(l==r)return val[t]=val[k]+v,t;
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=modify(p,v,lson,l,m),son[t][1]=rson;
		else son[t][0]=lson,son[t][1]=modify(p,v,rson,m+1,r);
		return val[t]=val[son[t][0]]+val[son[t][1]],t;
	}
	int query(int ll,int rr,int k,int l,int r){
		if(!k)return 0;
		if(ll<=l&&r<=rr)return val[k];
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,lson,l,m);
		if(ll>m)return query(ll,rr,rson,m+1,r);
		return query(ll,rr,lson,l,m)+query(ll,rr,rson,m+1,r);
	}
}T;
void modify(int v,int rt,int p,int v2,int k,int l,int r){
	root[k][rt]=T.modify(p,v2,root[k][que.back(k)],1,2*n);
	que.ins(k,rt);
	if(l==r)return;
	int m=(l+r)>>1;
	if(v<=m)modify(v,rt,p,v2,k<<1,l,m);
	else modify(v,rt,p,v2,k<<1|1,m+1,r);
}
void outq(int v,int rt,int k,int l,int r){
	que.del(k);
	if(l==r)return;
	int m=(l+r)>>1;
	if(v<=m)outq(v,rt,k<<1,l,m);
	else outq(v,rt,k<<1|1,m+1,r);
}
int query(int a,int b,int c,int d,int l1,int r1,int l2,int r2,int p,int k,int l,int r){
	if(l==r)return l;
	int m=(l+r)>>1,
	t=T.query(l1,r1,root[k<<1][a],1,2*n)+T.query(l2,r2,root[k<<1][a],1,2*n);
	t+=T.query(l1,r1,root[k<<1][b],1,2*n);
	t+=T.query(l2,r2,root[k<<1][b],1,2*n);
	t-=(T.query(l1,r1,root[k<<1][c],1,2*n)+T.query(l2,r2,root[k<<1][c],1,2*n)+T.query(l1,r1,root[k<<1][d],1,2*n)+T.query(l2,r2,root[k<<1][d],1,2*n));
	if(t>=p)return query(a,b,c,d,l1,r1,l2,r2,p,k<<1,l,m);
	else return query(a,b,c,d,l1,r1,l2,r2,p-t,k<<1|1,m+1,r);
}
struct List{
	int tot,head[maxn<<1],next[maxn<<1],val[maxn<<1],pos[maxn<<1],f[maxn<<1];
	void ins(int a,int p,int v,int _f){val[++tot]=v;pos[tot]=p;next[tot]=head[a];head[a]=tot;f[tot]=_f;}
	void work(int k){
		for(int p=head[k];p;p=next[p])modify(val[p],k,pos[p],f[p],1,1,lisan.maxval);
	}
	void outque(int k){
		for(int p=head[k];p;p=next[p])outq(val[p],k,1,1,lisan.maxval);
	}
}list;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],dfn[maxn],post[maxn],dep[maxn],sign,pa[maxn][16];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		for(int i=1;i<16;++i)pa[k][i]=pa[pa[k][i-1]][i-1];if(!pre)dep[k]=1;dfn[k]=++sign;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)pa[to[p]][0]=k,dep[to[p]]=dep[k]+1,dfs(to[p],k);
		post[k]=++sign;
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		for(int i=15;i>=0;--i)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		for(int i=15;i>=0;--i)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	void work(int k,int pre){
		list.work(k);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)work(to[p],k);
		list.outque(k);
	}
	int getpa(int a,int d){for(int i=15;i>=0;--i)if(dep[pa[a][i]]>=d)a=pa[a][i];return a;}
}G;

int main(){
	scanf("%d%d%d",&n,&P,&Q);
	for(int i=1;i<n;++i){
		int a=read(),b=read();
		G.addedge(a,b);
	}
	G.dfs(1,0);
	for(int i=1;i<=P;++i)a[i]=read(),b[i]=read(),c[i]=read(),lisan.ins(c[i]);
	lisan.work();
	for(int i=1;i<=P;++i){
		list.ins(a[i],G.dfn[b[i]],c[i],1);
		list.ins(a[i],G.post[b[i]],c[i],-1);
	}
	G.work(1,0);
	for(int i=1;i<=Q;++i){
		int u=read(),v=read(),k=read();
		if(G.dfn[u]>G.dfn[v])swap(u,v);
		int lca=G.lca(u,v),plca=G.pa[lca][0];
		int w=G.getpa(v,G.dep[lca]+1);
		printf("%d\n",lisan.real[query(u,v,lca,plca,G.dfn[lca],G.dfn[u],G.dfn[w],G.dfn[v],k,1,1,lisan.maxval)]);
	}
	return 0;
}
