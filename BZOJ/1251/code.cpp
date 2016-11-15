#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=5e4+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,m;
struct Treap{
	int tot,root,son[N][2],rnd[N],val[N],add[N],maxv[N],rev[N],size[N];
	int newNode(int x){rnd[++tot]=rand();size[tot]=1;val[tot]=maxv[tot]=x;return tot;}
	void update(int k){
		maxv[k]=val[k];if(ls)up(maxv[k],maxv[ls]);if(rs)up(maxv[k],maxv[rs]);
		size[k]=size[ls]+size[rs]+1;
	}
	void maintain_rev(int k){
		rev[k]^=1;swap(ls,rs);
	}
	void maintain_add(int k,int v){
		add[k]+=v; val[k]+=v; maxv[k]+=v;
	}
	void maintain(int k){
		if(rev[k])maintain_rev(ls),maintain_rev(rs),rev[k]=0;
		if(add[k])maintain_add(ls,add[k]),maintain_add(rs,add[k]),add[k]=0;
	}
	int sta[N],top;
	void build(){
		rep(i,1,n)newNode(0);
		sta[++top]=1;
		rep(k,2,n){
			while(top&&rnd[sta[top]]<rnd[k])update(sta[top--]);
			if(top)son[sta[top]][1]=k;
			ls=sta[top+1];sta[++top]=k;
			sta[top+1]=0;update(k);
		}
		while(top)update(sta[top--]);
		root=sta[1];
	}
	int merge(int a,int b){
		if(!a||!b)return a+b;
		if(rnd[a]>rnd[b]){maintain(a);son[a][1]=merge(son[a][1],b);update(a);return a;}
		maintain(b);son[b][0]=merge(a,son[b][0]);update(b);return b;
	}
	void split(int k,int p,int&l,int&r){
		if(!p){l=0;r=k;return;}
		if(p<=size[ls]){maintain(k);split(ls,p,l,ls);update(r=k);return;}
		maintain(k);split(rs,p-size[ls]-1,rs,r);update(l=k);
	}
	void modify_add(int l,int r,int v){
		int p1,p2,p3;
		split(root,l-1,p1,p2);split(p2,r-l+1,p2,p3);
		maintain_add(p2,v);
		root=merge(merge(p1,p2),p3);
	}
	void modify_rev(int l,int r){
		int p1,p2,p3;
		split(root,l-1,p1,p2);split(p2,r-l+1,p2,p3);
		maintain_rev(p2);
		root=merge(merge(p1,p2),p3);
	}
	int query_max(int l,int r){
		int p1,p2,p3;
		split(root,l-1,p1,p2);split(p2,r-l+1,p2,p3);
		int ret=maxv[p2];
		root=merge(merge(p1,p2),p3);
		return ret;
	}
}T;
int main(){
	srand(20000107);
	scanf("%d%d",&n,&m);
	T.build();
	while(m--){
		int op;scanf("%d",&op);
		if(op==1){
			int l,r,v;scanf("%d%d%d",&l,&r,&v);
			T.modify_add(l,r,v);
		}else if(op==2){
			int l,r;scanf("%d%d",&l,&r);
			T.modify_rev(l,r);
		}else{
			int l,r;scanf("%d%d",&l,&r);
			printf("%d\n",T.query_max(l,r));
		}
	}
	return 0;
}
