#include<iostream>
#include<cstdio>
#define ls (k<<1)
#define rs (k<<1|1)
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
const int N=1e6+10,M=2e6+10,P=1e7,V=2e7,MEM=1e7;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,m,t,ans[N];
struct Edge{
	int u,v,s,t;
}e[M];
struct Memory{
	int tot,*val[MEM],old[MEM];
	void update(int&x,int y){old[++tot]=x;val[tot]=&x;x=y;}
	void roll(){*val[tot]=old[tot];--tot;}
}mem;
struct UFS{
	int pa[N],rank[N],mark[N];
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0,mark[i]=0;}
	int find(int k,int&v){return pa[k]==k?k:(v^=mark[k],find(pa[k],v));}
	bool unio(int a,int b,int v){
		a=find(a,v);b=find(b,v);
		if(a==b)return !v;
		if(rank[a]<rank[b])swap(a,b);
		mem.update(pa[b],a);mem.update(mark[b],v);
		if(rank[a]==rank[b])mem.update(rank[a],rank[a]+1);
		return 1;
	}
}S;
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
		for(int p=head[k];p;p=next[p])mem.update(now,now&S.unio(e[to[p]].u,e[to[p]].v,1));
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
	rep(i,1,m)e[i].u=read(),e[i].v=read(),e[i].s=read()+1,e[i].t=read();
	rep(i,1,m)if(e[i].s<=e[i].t)T.modify(e[i].s,e[i].t,i,1,1,t);
	S.clear();
	T.dfs(1,1,t);
	rep(i,1,t)if(ans[i])puts("Yes");else puts("No");
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("big.out","w",stdout);
	return sjj118::main();
}
