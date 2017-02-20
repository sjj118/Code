#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
using std::cerr;
using std::endl;
using std::sort;
using std::swap;
using std::unique;
const int N=2e5+10,inf=1e9,mo=1e9+7;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,h[N<<1];
LL fact[N],inv[N],_fact[N];
inline LL C(LL n,LL m){
	if(m>n)return 0;
	return fact[n]*_fact[m]%mo*_fact[n-m]%mo;
}
struct Graph{
    int tot,head[N],to[N<<1],next[N<<1],dep[N],pa[N][20],size[N],dfn[N],clo;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		dfn[k]=++clo;
		dep[k]=dep[pre]+1;pa[k][0]=pre;
		rep(i,1,19)pa[k][i]=pa[pa[k][i-1]][i-1];
		size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k),size[k]+=size[to[p]];
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
}G;
bool cmp(int a,int b){return G.dfn[a]<G.dfn[b];}
struct Tree{
	int tot,rt,head[N],to[N<<1],next[N<<1],mark[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int sta[N],top;
	void clear(int k,int pre){
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)clear(to[p],k);
		head[k]=0;mark[k]=0;
	}
	void clear(){
		tot=0;clear(rt,0);rt=0;
	}
	void build(int n,int*node){
		top=0;
		sta[++top]=node[1];mark[node[1]]=1;
		rep(i,2,n){
			int k=node[i],f=G.lca(k,sta[top]);mark[k]=1;
			while(top>1&&G.dfn[f]<=G.dfn[sta[top-1]]){
				addedge(sta[top-1],rt=sta[top]);--top;
			}
			if(sta[top]!=f)addedge(rt=sta[top],f),sta[top]=f;
			sta[++top]=k;
		}
		while(--top)addedge(sta[top+1],rt=sta[top]);
	}
	int leaf,sz1,sz2;
	void dfs(int k,int pre){
		int deg=0;
		for(int p=head[k];p;p=next[p]){
			++deg;
			if(to[p]!=pre){
				dfs(to[p],k);
			}
		}
		if(deg==1){
			++leaf;
			if(sz1==0){
				for(int p=head[k];p;p=next[p]){
					if(to[p]==pre)sz1=G.size[k];
					else sz1=n-G.size[to[p]];
				}
			}else{
				for(int p=head[k];p;p=next[p]){
					if(to[p]==pre)sz2=G.size[k];
					else sz2=n-G.size[to[p]];
				}
			}
		}
	}
	int solve(){
		leaf=0;sz1=sz2=0;
		dfs(rt,0);
		if(sz1>sz2)swap(sz1,sz2);
		if(leaf==2)return C(sz1+sz2,sz1);
		return 1;
	}
}T;
int main(){
	scanf("%d%d",&n,&m);
	fact[0]=1;rep(i,1,n<<1)fact[i]=fact[i-1]*i%mo;
	inv[1]=1;rep(i,2,n<<1)inv[i]=mo-mo/i*inv[mo%i]%mo;
	_fact[0]=1;rep(i,1,n<<1)_fact[i]=_fact[i-1]*inv[i]%mo;
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.dfs(1,0);
	while(m--){
		int t;scanf("%d",&t);
		T.clear();
		rep(i,1,t){
			int a,b;scanf("%d%d",&a,&b);
			h[i*2-1]=a;h[i*2]=b;
		}
		sort(h+1,h+1+t*2,cmp);
		t=unique(h+1,h+1+t*2)-h-1;
		T.build(t,h);
		printf("%d\n",T.solve());
	}
	return 0;
}
