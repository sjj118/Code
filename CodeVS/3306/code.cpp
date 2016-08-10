#include<iostream>
#include<cstdio>
#define maxn 200010
#define LL long long
#define lson son[k][0]
#define rson son[k][1]
#define ws(k) (son[pa[k]][1]==k)
#define canrot(k) (pa[k]&&(son[pa[k]][0]==k||son[pa[k]][1]==k))
#define inf 1e9

using namespace std;

int n,m;
struct LCT{
	int pa[maxn],son[maxn][2],val[maxn],maxx[maxn],minn[maxn],maxl[maxn],maxr[maxn],rev[maxn];
	void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	void molify_rev(int k){
		rev[k]^=1;
		swap(maxl[k],maxr[k]);
		swap(lson,rson);
	}
	void pushdown(int k){
		if(rev[k]){
			rev[k]=0;molify_rev(lson);molify_rev(rson);
		}
	}
	void pushup(int k){
		maxx[0]=-inf;minn[0]=inf;maxl[0]=maxr[0]=-inf;
		maxx[k]=max(val[k],max(maxx[lson],maxx[rson]));
		minn[k]=min(val[k],min(minn[lson],minn[rson]));
		maxl[k]=max(max(maxl[lson],maxl[rson]),max(max(0,val[k]-minn[lson]),max(maxx[rson]-minn[lson],maxx[rson]-val[k])));
		maxr[k]=max(max(maxr[lson],maxr[rson]),max(max(0,val[k]-minn[rson]),max(maxx[lson]-minn[rson],maxx[lson]-val[k])));
	}
	void rot(int k){
		int f=pa[k],gf=pa[f],w=ws(k);
		if(canrot(f))set(k,gf,ws(f));else pa[k]=gf;
		set(son[k][!w],f,w);set(f,k,!w);
		pushup(f);
	}
	int stack[maxn],top;
	void splay(int k){
		int t=stack[top++]=k;
		while(canrot(t))stack[top++]=pa[t],t=pa[t];
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
			son[k][1]=v;
			pushup(v=k);
			k=pa[k];
		}
		return v;
	}
	void makeroot(int k){
		molify_rev(access(k));
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
		makeroot(x);access(y);splay(y);
		pa[son[y][0]]=0;
		son[y][0]=0;
		pushup(y);
	}
	void molify_val(int k,int c){
		val[k]=c;
		splay(k);
	}
	int getans(int x,int y){
		makeroot(x);access(y);splay(x);
		return maxl[x];
	}
	LCT(){
		for(int i=0;i<maxn;++i)maxx[i]=maxl[i]=maxr[i]=-inf,minn[i]=inf;
	}
}T;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x;scanf("%d",&x);
		T.molify_val(i,x);
	}
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		T.link(x,y);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if(op){
			printf("%d\n",T.getans(x,y));
		}else{
			T.molify_val(x,y);
		}
	}
	return 0;
}
