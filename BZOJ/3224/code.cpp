#include<iostream>
#include<cstdio>
#include<cstdlib>
#define pii pair<int,int>
#define mp make_pair
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,inf=1e9;
int root;
struct Treap{
	int tot,ls[maxn],rs[maxn],rnd[maxn],key[maxn],size[maxn];
	int newnode(int v){int k=++tot;rnd[k]=rand();key[k]=v;size[k]=1;return k;}
	void update(int k){size[k]=size[ls[k]]+size[rs[k]]+1;}
	int merge(int a,int b){
		if(!a||!b)return a+b;
		if(rnd[a]<rnd[b])return rs[a]=merge(rs[a],b),update(a),a;
		else return ls[b]=merge(a,ls[b]),update(b),b;
	}
	void split(int k,int p,int&l,int&r){
		if(p==0)l=0,r=k;
		else if(size[ls[k]]==p)l=ls[k],ls[k]=0,update(k),r=k;
		else if(size[ls[k]]>p)split(ls[k],p,l,ls[k]),update(k),r=k;
		else split(rs[k],p-size[ls[k]]-1,rs[k],r),update(k),l=k;
	}
	int pth(int k,int p){
		if(size[k]<p||p<=0)return -1;
		if(size[ls[k]]>=p)return pth(ls[k],p);
		if(size[ls[k]]+1==p)return key[k];
		return pth(rs[k],p-size[ls[k]]-1);
	}
	int rank(int k,int x){
		if(!k)return 1;
		if(key[k]<x)return rank(rs[k],x)+size[ls[k]]+1;
		return rank(ls[k],x);
	}
	void del(int k,int x){
		int l,r,t;split(k,rank(k,x)-1,l,t);split(t,1,t,r);
		root=merge(l,r);
	}
	void insert(int k,int x){
		int l,r;split(k,rank(k,x)-1,l,r);
		root=merge(l,newnode(x));root=merge(root,r);
	}
	int pre(int k,int x){
		if(!k)return 0;
		if(key[k]<x)return max(pre(rs[k],x),key[k]);
		return pre(ls[k],x);
	}
	int suf(int k,int x){
		if(!k)return inf;
		if(key[k]>x)return min(suf(ls[k],x),key[k]);
		return suf(rs[k],x);
	}
}T;
int main(){
	int n;scanf("%d",&n);
	rep(i,1,n){
		int op,x;scanf("%d%d",&op,&x);
		if(op==1)T.insert(root,x);
		if(op==2)T.del(root,x);
		if(op==3)printf("%d\n",T.rank(root,x));
		if(op==4)printf("%d\n",T.pth(root,x));
		if(op==5)printf("%d\n",T.pre(root,x));
		if(op==6)printf("%d\n",T.suf(root,x));
	}
	return 0;
}
