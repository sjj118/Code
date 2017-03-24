#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
#define ls son[k][0]
#define rs son[k][1]
typedef long long LL;
using std::swap;
const int N=1e5+10;
namespace SGT{
	struct Data{
		LL val;
		int add,len;
		Data(){}
		Data(int len):len(len),add(0),val(0){}
		void maintain_add(int v){
			add+=v;
			val+=(LL)len*v;
		}
		friend Data operator+(const Data&a,const Data&b){
			Data ret;
			ret.len=a.len+b.len;
			ret.add=0;
			ret.val=a.val+b.val;
			return ret;
		}
	}data[N];
	int tot,son[N][2];
	void update(int k){
		data[k]=data[ls]+data[rs];
	}
	void maintain(int k){
		if(data[k].add)data[ls].maintain_add(data[k].add),data[rs].maintain_add(data[k].add),data[k].add=0;
	}
	void build(int&k,int l,int r){
		k=++tot;
		if(l==r){data[k]=Data(1);return;}
		int m=(l+r)>>1;
		build(ls,l,m);build(rs,m+1,r);
		update(k);
	}
	void modify_add(int ll,int rr,int v,int k,int l,int r){
		if(ll<=l&&r<=rr)return data[k].maintain_add(v);
		maintain(k);
		int m=(l+r)>>1;
		if(ll<=m)modify_add(ll,rr,v,ls,l,m);
		if(rr>m)modify_add(ll,rr,v,rs,m+1,r);
		update(k);
	}
	LL query_val(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return data[k].val;
		maintain(k);
		int m=(l+r)>>1;
		if(rr<=m)return query_val(ll,rr,ls,l,m);
		if(ll>m)return query_val(ll,rr,rs,m+1,r);
		return query_val(ll,rr,ls,l,m)+query_val(ll,rr,rs,m+1,r);
	}
}
namespace Graph{
	int tot,head[N],to[N<<1],next[N<<1],size[N],clo,in[N],out[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		in[k]=++clo;size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k),size[k]+=size[to[p]];
		out[k]=clo;
	}
}
namespace LCT{
	int son[N][2],pa[N];
	bool rev[N];
	inline void update(int k){
	}
	inline void maintain_rev(int k){
		rev[k]^=1;
		swap(ls,rs);
	}
	inline void maintain(int k){
		if(rev[k])maintain_rev(ls),maintain_rev(rs),rev[k]=0;
	}
	inline void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	inline bool ws(int k){return son[pa[k]][1]==k;}
	inline bool canrot(int k){return son[pa[k]][ws(k)]==k;}
	inline void rot(int k){
		int f=pa[k],gf=pa[f],w=ws(k);
		if(canrot(f))set(k,gf,ws(f));else pa[k]=gf;
		set(son[k][!w],f,w);set(f,k,!w);
		update(f);
	}
	inline void preview(int k){if(canrot(k))preview(pa[k]);maintain(k);}
	inline void splay(int k){
		preview(k);
		while(canrot(k)){
			if(canrot(pa[k])&&ws(k)==ws(pa[k]))rot(pa[k]);rot(k);
		}
		update(k);
	}
	inline int access(int k){
		int u=0;
		while(k){
			splay(k);

			rs=u;
			update(u=k);
			k=pa[k];
		}
		return u;
	}
	inline void makeroot(int k){
		maintain_rev(access(k));
		splay(k);
	}
	inline int findroot(int k){
		for(k=access(k);maintain(k),ls;k=ls);
		return k;
	}
	inline void link(int a,int b){
		makeroot(b);pa[b]=a;
	}
}
int main(){
	return 0;
}
