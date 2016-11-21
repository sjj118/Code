#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=1e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n;
struct Treap{
	int root,tot,son[N][2],mav[N],val[N],rnd[N],size[N];
	Treap(){root=tot=1;}
	int newNode(int x){rnd[++tot]=rand();val[tot]=mav[tot]=x;update(tot);return tot;}
	void update(int k){
		mav[k]=val[k];if(ls)up(mav[k],mav[ls]);if(rs)up(mav[k],mav[rs]);
		size[k]=size[ls]+size[rs]+1;
	}
	void splix(int k,int p,int&l,int&r){
		if(p==0){l=0;r=k;return;}
		if(p<=size[ls]){splix(ls,p,l,ls);return update(r=k);}
		splix(rs,p-size[ls]-1,rs,r);return update(l=k);
	}
	int merge(int a,int b){
		if(!a||!b)return a+b;
		if(rnd[a]>rnd[b]){son[a][1]=merge(son[a][1],b);update(a);return a;}
		else{son[b][0]=merge(a,son[b][0]);update(b);return b;}
	}
	void ins(int p,int x){
		int l,r;splix(root,p,l,r);
		root=merge(merge(l,newNode(x)),r);
	}
	int query_max(int k,int p){
		int l,r;splix(k,p,l,r);
		int ret=mav[l];
		root=merge(l,r);
		return ret;
	}
}T;
int main(){
	srand(20000107);
	scanf("%d",&n);
	int ans=0;
	rep(i,1,n){
		int x;scanf("%d",&x);
		int tmp=T.query_max(T.root,x+1)+1;
		T.ins(x+1,tmp);
		up(ans,tmp);
		printf("%d\n",ans);
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("treap.out","w",stdout);
	return sjj118::main();
}
