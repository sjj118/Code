#include<iostream>
#include<cstdio>
#define maxn 300010
#define lson son[k][0]
#define rson son[k][1]
#define ws(k) (son[pa[k]][1]==k)
#define canrot(k) (pa[k]&&(son[pa[k]][0]==k||son[pa[k]][1]==k))

using namespace std;

int n,m;
struct LCT{
	int son[maxn][2],pa[maxn],rev[maxn],sumx[maxn],val[maxn];
	void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	void modify_rev(int k){
		rev[k]^=1;
		swap(lson,rson);
	}
	void modify_val(int k,int c){
		val[k]=c;
		pushup(k);
	}
	void pushdown(int k){
		if(rev[k])rev[k]=0,modify_rev(lson),modify_rev(rson);
	}
	void pushup(int k){
		sumx[0]=val[0]=rev[0]=0;
		sumx[k]=sumx[lson]^val[k]^sumx[rson];
	}
	void rot(int k){
		int w=ws(k),f=pa[k],gf=pa[f];
		if(canrot(f))set(k,gf,ws(f));else pa[k]=gf;
		set(son[k][!w],f,w);set(f,k,!w);
		pushup(f);
	}
	int stack[maxn],top;
	void splay(int k){
		int t=stack[top++]=k;
		while(canrot(t))t=pa[t],stack[top++]=t;
		while(top)pushdown(stack[--top]);
		while(canrot(k)){
			if(canrot(pa[k])&&ws(k)==ws(pa[k]))rot(pa[k]);rot(k);
		}
		pushup(k);
	}
	int access(int k){
		int v=0;
		while(k){
			splay(k);
			rson=v;
			pushup(v=k);
			k=pa[k];
		}
		return v;
	}
	void makeroot(int k){
		modify_rev(access(k));
		splay(k);
	}
	int findroot(int k){
		for(k=access(k);pushdown(k),lson;k=lson);
		return k;
	}
	void link(int x,int y){
		makeroot(x);
		if(findroot(y)!=x)pa[x]=y;
	}
	void cut(int x,int y){
		makeroot(x);access(y);splay(y);
		if(pa[x]==y&&son[x][1]==0)pa[x]=0,son[y][0]=0,pushup(y);
	}
}T;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&T.val[i]);
	for(int i=1;i<=m;++i){
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if(op==0){
			T.makeroot(x);
			T.access(y);
			T.splay(y);
			printf("%d\n",T.sumx[y]);
		}else if(op==1){
			T.link(x,y);
		}else if(op==2){
			T.cut(x,y);
		}else{
			T.modify_val(x,y);
			T.splay(x);
		}
	}
	return 0;
}
