#include<iostream>
#include<cstdio>
#define ls (k<<1)
#define rs (k<<1|1)
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,M=2e5+10,P=4*N,V=M*20;
int n,m,t,ans[N];
struct Edge{
	int u,v,s,t;
}e[M];
struct UFS{
	int pa[N],rank[N],mark[N];
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	bool unio(int a,int b,int va,int vb){
		a=find(a);b=find(b);
		if(a==b)return va==vb;
		if(rank[a]<rank[b])swap(a,b);
		pa[b]=a;
		return 1;
	}
}S;
struct Memory{
	int tot,*val[],old[];
	void modify(int&x,int y){old[++tot]=x;val[tot]=&x;x=y;}
	void roll(){val[tot]=old[tot];--tot;}
}mem;
int now=1;
struct VT{
	int tot,head[P],next[V],to[V];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void modify(int ll,int rr,int p,int k,int l,int r){
		if(ll<=l&&r<=rr)return ins(k,p);
		int m=(l+r)>>1;
		if(ll<=m)modify(ll,rr,p,ls,l,m);
		if(rr>m)modify(ll,rr,p,rs,m+1,r);
	}
	int time[P];
	void apply(int k){
		time[k]=mem.tot;
		for(int p=head[k];p;p=next[p])mem.update(now,now&S.unio(e[to[p]].u,e[to[p]].v));
	}
	void roll(int k){
		while(mem.tot>time[k])mem.roll();
	}
	void dfs(int k,int l,int r){
		apply(k);
		if(l==r){ans[l]=now;roll(k);return;}
		int m=(l+r)>>1;
		dfs(ls,l,m);dfs(rs,m+1,r);
		roll(k);
	}
}T;
int main(){
	scanf("%d%d%d",&n,&m,&t);
	rep(i,1,m)scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].s,&e[i].t),++e[i].s;
	rep(i,1,m)T.modify(e[i].s,e[i].t,i,1,1,t);
	S.clear();
	T.dfs(1,1,t);
	return 0;
}
