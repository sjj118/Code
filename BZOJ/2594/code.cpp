#include<iostream>
#include<cstdio>
#include<map>
#include<ctime>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,M=1e6+10;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,m,q;
struct Edge{
	int u,v,t,bad,id;
}e[M];
const int P=N<<1;
#define ls son[k][0]
#define rs son[k][1]
struct LCT{
	int pa[P],son[P][2],tot,val[P],maxp[P],rev[P];
	inline int ws(int k){return son[pa[k]][1]==k;}
	inline bool canrot(int k){return pa[k]&&son[pa[k]][ws(k)]==k;}
	inline void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	void update(int k){
		maxp[k]=k;
		if(ls&&val[maxp[ls]]>val[maxp[k]])maxp[k]=maxp[ls];
		if(rs&&val[maxp[rs]]>val[maxp[k]])maxp[k]=maxp[rs];
	}
	void maintain_rev(int k){
		rev[k]^=1;
		swap(ls,rs);
	}
	void maintain(int k){
		if(rev[k]){
			if(ls)maintain_rev(ls);
			if(rs)maintain_rev(rs);
			rev[k]=0;
		}
	}
	void preview(int k){
		if(canrot(k))preview(pa[k]);
		maintain(k);
	}
	void rot(int k){
		int f=pa[k],gf=pa[f],w=ws(k);
		if(canrot(f))set(k,gf,ws(f));else pa[k]=gf;
		set(son[k][!w],f,w);set(f,k,!w);
		update(f);
	}
	void splay(int k){
		preview(k);
		while(canrot(k)){
			if(canrot(pa[k])&&ws(k)==ws(pa[k]))rot(pa[k]);
			rot(k);
		}
		update(k);
	}
	int access(int k){
		int v=0;
		while(k){
			splay(k);
			rs=v;
			update(v=k);
			k=pa[k];
		}
		return v;
	}
	void makeroot(int k){
		maintain_rev(access(k));
	}
	int getroot(int k){
		for(k=access(k);maintain(k),ls;k=ls);
		return k;
	}
	void link(int a,int b){
		makeroot(a);splay(a);
		pa[a]=b;
	}
	void cut(int a,int b){
		makeroot(a);access(b);splay(a);
		pa[b]=0;son[a][1]=0;update(a);
	}
	bool isLink(int a,int b){
		return getroot(a)==getroot(b);
	}
	int getmaxEdge(int a,int b){
		makeroot(a);
		return maxp[access(b)];
	}
}T;
int id[P];
void addedge(Edge k){
	int t;
	if(T.isLink(k.u,k.v)){
		t=T.getmaxEdge(k.u,k.v);
		if(T.val[t]<=k.t)return;
		T.cut(t,e[id[t]].u);
		T.cut(t,e[id[t]].v);
	}else t=++T.tot;
	T.val[t]=k.t;
	id[t]=k.id;
	T.link(t,k.u);
	T.link(t,k.v);
}
struct Query{
	int k,x,y,ans;
}o[N];
map<int,int> eid[N];
struct UFS{
	int pa[N],rank[N];
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	bool unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return 0;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
		return 1;
	}
}S;
void MST(){
	S.clear();
	rep(i,1,m)if(!e[i].bad){
		if(S.unio(e[i].u,e[i].v))addedge(e[i]);
	}
}
bool operator<(const Edge&a,const Edge&b){return a.t<b.t;}
int main(){
	n=read();m=read();q=read();
	rep(i,1,m){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].t);
		if(e[i].u>e[i].v)swap(e[i].u,e[i].v);
	}
	sort(e+1,e+1+m);
	rep(i,1,m)eid[e[i].u][e[i].v]=i,e[i].id=i;
	rep(i,1,q){
		scanf("%d%d%d",&o[i].k,&o[i].x,&o[i].y);
		if(o[i].k==2){
			if(o[i].x>o[i].y)swap(o[i].x,o[i].y);
			e[eid[o[i].x][o[i].y]].bad=1;
		}
	}
	T.tot=n;
	MST();
	per(i,q,1){
		if(o[i].k==1){
			if(T.isLink(o[i].x,o[i].y))o[i].ans=e[id[T.getmaxEdge(o[i].x,o[i].y)]].t;
			else o[i].ans=-1;
		}else{
			addedge(e[eid[o[i].x][o[i].y]]);
		}
	}
	rep(i,1,q)if(o[i].k==1)printf("%d\n",o[i].ans);
	return 0;
}
