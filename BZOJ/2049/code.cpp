#include<iostream>
#include<cstdio>
#define maxn 10010
#define lson son[k][0]
#define rson son[k][1]
#define canrot(k) (pa[k]&&(son[pa[k]][0]==k||son[pa[k]][1]==k))
#define ws(k) (son[pa[k]][1]==k)

using namespace std;

int n,m;
struct LCT{
	int son[maxn][2],pa[maxn],rev[maxn];
	void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	void pushdown(int k){
		if(rev[k]){
			rev[k]=0;
			if(lson)rev[lson]^=1;
			if(rson)rev[rson]^=1;
			swap(lson,rson);
		}
	}
	void rot(int k){
		int f=pa[k],gf=pa[f],w=ws(k);
		if(son[gf][ws(f)]==f)set(k,gf,ws(f));else pa[k]=gf;
		set(son[k][!w],f,w);
		set(f,k,!w);
	}
	int stack[maxn],top;
	void splay(int k){
		int t=stack[top++]=k;
		while(canrot(t))t=pa[t],stack[top++]=t;
		while(top)pushdown(stack[--top]);
		while(canrot(k)){
			if(canrot(pa[k])&&ws(k)==ws(pa[k]))rot(pa[k]);rot(k);
		}
	}
	int access(int k){
		int v=0;
		while(k){
			splay(k);
			rson=v;
			v=k;
			k=pa[k];
		}
		return v;
	}
	void makeroot(int k){
		rev[access(k)]^=1;
		splay(k);
	}
	int getroot(int k){
		for(k=access(k);pushdown(k),lson;k=lson);
		return k;
	}
	void link(int x,int y){
		makeroot(x);
		pa[x]=y;
	}
	void cut(int x,int y){
		makeroot(x);
		access(y);
		splay(y);
		pa[son[y][0]]=0;
		son[y][0]=0;
	}
}T;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		char op[10];int u,v;
		scanf("\n%s%d%d",op,&u,&v);
		if(op[0]=='C'){
			T.link(u,v);
		}else if(op[0]=='D'){
			T.cut(u,v);
		}else{
			if(T.getroot(u)==T.getroot(v))printf("Yes\n");else printf("No\n");
		}
	}
	return 0;
}
