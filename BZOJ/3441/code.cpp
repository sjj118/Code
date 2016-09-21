#include<iostream>
#include<cstdio>
#include<cstdlib>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,x,ans,w[maxn],a[maxn];
struct Treap{
	int tot,root,ls[maxn],rs[maxn],rnd[maxn],add[maxn],val[maxn],size[maxn],low[maxn];
	int newnode(int x){++tot;rnd[tot]=rand();val[tot]=low[tot]=x;size[tot]=1;return tot;}
	void update(int k){
		low[k]=val[k];
		if(ls[k])dn(low[k],low[ls[k]]);
		if(rs[k])dn(low[k],low[rs[k]]);
		size[k]=size[ls[k]]+size[rs[k]]+1;
	}
	void apply_add(int k,int v){add[k]+=v;val[k]+=v;low[k]+=v;}
	void maintain(int k){
		if(ls[k])apply_add(ls[k],add[k]);
		if(rs[k])apply_add(rs[k],add[k]);
		add[k]=0;
	}
	void pushup(int k){
		if(ls[k])pushup(ls[k]);
		if(rs[k])pushup(rs[k]);
		update(k);
	}
	int stack[maxn],top;
	void build(){
		rep(i,1,n){
			stack[top+1]=0;
			while(rnd[stack[top]]>rnd[i])--top;
			if(top)rs[stack[top]]=i;else root=i;
			ls[i]=stack[top+1];stack[++top]=i;
		}
		pushup(root);
	}
	int merge(int a,int b){
		if(!a||!b)return a+b;
		maintain(a);maintain(b);
		if(rnd[a]<rnd[b])return rs[a]=merge(rs[a],b),update(a),a;
		else return ls[b]=merge(a,ls[b]),update(b),b;
	}
	void split(int k,int p,int&l,int&r){
		maintain(k);
		if(!p)l=0,r=k;
		else if(size[ls[k]]==p)l=ls[k],ls[k]=0,update(k),r=k;
		else if(p<size[ls[k]])split(ls[k],p,l,ls[k]),update(k),r=k;
		else split(rs[k],p-size[ls[k]]-1,rs[k],r),update(k),l=k;
	}
	int neg(int k){
		maintain(k);
		if(low[ls[k]]<0)return neg(ls[k]);
		if(val[k]<0)return size[ls[k]]+1;
		return neg(rs[k])+size[ls[k]]+1;
	}
	bool work(){
		if(low[root]>=0)return 0;
		int k=neg(root);
		int l,r;split(root,k-1,l,r);split(r,1,k,r);
		apply_add(r,1);
		root=merge(l,r);
		return 1;
	}
}T;
int main(){
	srand(20000107);
	scanf("%d%d%d",&n,&m,&x);
	rep(i,1,n)scanf("%d",&w[i]);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)T.newnode((x-w[i])/a[i]+1-i);
	T.build();
	rep(i,1,m){
		while(T.work());
		ans+=T.size[T.root];
		T.apply_add(T.root,-T.size[T.root]);
	}
	printf("%d",ans);
	return 0;
}
