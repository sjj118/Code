#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::sort;
using std::lower_bound;
using std::upper_bound;
const int N=2e4+10,P=10*N,V=1e7,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int x[N],y[N];
int n,ps=1;
bool cmp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[N<<1],ml,rl[N<<1];
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,cmp);
		for(int i=1,lst=0;i<=tot;++i){
			if(*val[i]>lst)lst=rl[++ml]=*val[i];
			*val[i]=ml;
		}
	}
}li;
struct Graph{
	int tot,head[P],to[V],next[V],nid[P],nps;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b^1,a^1);}
	int insta[P],sta[P],top,dfn[P],clo,lowlink[P];
	void dfs(int k){
		dfn[k]=lowlink[k]=++clo;
		insta[sta[++top]=k]=1;
		for(int p=head[k];p;p=next[p]){
			if(!dfn[to[p]]){
				dfs(to[p]);dn(lowlink[k],lowlink[to[p]]);
			}else if(insta[to[p]])dn(lowlink[k],dfn[to[p]]);
		}
		if(lowlink[k]==dfn[k]){
			nid[k]=++nps;
			while(sta[top]!=k){
				nid[sta[top]]=nps;
				insta[sta[top--]]=0;
			}
			insta[sta[top--]]=0;
		}
	}
	bool sat2(){
		rep(i,2,ps)if(!dfn[i])dfs(i);
		rep(i,2,ps)if(nid[i]==nid[i^1])return 0;
		return 1;
	}
	void clear(){tot=0;cls(head);cls(dfn);nps=0;clo=0;top=0;}
}G;
#define ls son[k][0]
#define rs son[k][1]
int pid[P][2],rid[N][2],lid[N];
int tot;
int newNode(){
	pid[++tot][0]=++ps;
	pid[tot][1]=++ps;
	return tot;
}
int rt;
struct SGT{
	int son[P][2];
	void build(int&k,int l,int r){
		k=newNode();
		if(l==r){lid[l]=k;return;}
		int m=(l+r)>>1;
		build(ls,l,m);build(rs,m+1,r);
		G.addedge(pid[k][0],pid[ls][0]);
		G.addedge(pid[k][0],pid[rs][0]);
	}
	void link0(int ll,int rr,int p,int k,int l,int r){
		if(ll>rr)return;
		if(ll<=l&&r<=rr)return G.addedge(p,pid[k][0]);
		int m=(l+r)>>1;
		if(ll<=m)link0(ll,rr,p,ls,l,m);
		if(rr>m)link0(ll,rr,p,rs,m+1,r);
	}
}T;
bool check(int d){
	G.clear();
	ps=1;tot=0;
	T.build(rt,1,li.ml);
	rep(i,1,n)rid[i][0]=++ps,rid[i][1]=++ps;
	rep(i,1,n)G.addedge(pid[lid[x[i]]][0],rid[i][0]),G.addedge(pid[lid[y[i]]][0],rid[i][1]);
	rep(i,1,n){
		T.link0(lower_bound(li.rl+1,li.rl+1+li.ml,li.rl[x[i]]-d+1)-li.rl,upper_bound(li.rl+1,li.rl+1+li.ml,li.rl[x[i]]-1)-li.rl-1,rid[i][0],1,1,li.ml);
		T.link0(lower_bound(li.rl+1,li.rl+1+li.ml,li.rl[x[i]]+1)-li.rl,upper_bound(li.rl+1,li.rl+1+li.ml,li.rl[x[i]]+d-1)-li.rl-1,rid[i][0],1,1,li.ml);
		T.link0(lower_bound(li.rl+1,li.rl+1+li.ml,li.rl[y[i]]-d+1)-li.rl,upper_bound(li.rl+1,li.rl+1+li.ml,li.rl[y[i]]-1)-li.rl-1,rid[i][1],1,1,li.ml);
		T.link0(lower_bound(li.rl+1,li.rl+1+li.ml,li.rl[y[i]]+1)-li.rl,upper_bound(li.rl+1,li.rl+1+li.ml,li.rl[y[i]]+d-1)-li.rl-1,rid[i][1],1,1,li.ml);
	}
	return G.sat2();
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&x[i],&y[i]),li.ins(x[i]),li.ins(y[i]);
	li.work();
	int l=0,r=8;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
