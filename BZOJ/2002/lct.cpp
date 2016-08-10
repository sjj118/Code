#include<iostream>
#include<cstdio>
#define maxn 200007
#define lson son[k][0]
#define rson son[k][1]

using namespace std;

int n,m;
struct LCT{
	int son[maxn][2],pa[maxn],size[maxn],papa[maxn],tot;
	int ws(int k){
		return son[pa[k]][1]==k;
	}
	void set(int a,int b,int c){
		pa[a]=b;
		son[b][c]=a;
	}
	void pushup(int k){
		size[k]=size[lson]+size[rson]+1;
		if(lson&&papa[lson])papa[k]=papa[lson];papa[lson]=0;
		if(rson&&papa[rson])papa[k]=papa[rson];papa[rson]=0;
	}
	void rot(int k){
		int w=ws(k),f=pa[k],gf=pa[f];
		set(k,gf,ws(f));
		set(son[k][!w],f,w);
		set(f,k,!w);
		pushup(f);
	}
	void splay(int k,int f=0){
		while(pa[k]!=f){
			if(pa[pa[k]]!=f&&ws(k)==ws(pa[k]))rot(pa[k]);
			rot(k);
		}
		pushup(k);
	} 
	void access(int k){
		int v=0;
		while(k){
			splay(k);
			pa[rson]=0;
			papa[rson]=k;
			set(v,k,1);
			papa[v]=0;
			pushup(k);
			v=k;
			k=papa[k];
		}
	}
	void cut(int k){
		access(k);
		splay(k);
		pa[lson]=0;
		lson=0;
		pushup(k);
		papa[k]=0;
	}
	void join(int k,int f){
		access(k);
		splay(k);
		papa[k]=f;
		access(k);
		splay(k);
	}
} T;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		x=min(i+x,n+1);
		T.join(i,x);
	}
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x;
			scanf("%d",&x);
			++x;
			T.access(x);
			T.splay(x);
			printf("%d\n",T.size[T.son[x][0]]);
		}else{
			int x,t;
			scanf("%d%d",&x,&t);
			++x;
			T.cut(x);
			t=min(x+t,n+1);
			T.join(x,t);
		}
	}
	return 0;
}
