#include<iostream>
#include<cstdio>
#define maxn 100010
#define maxk 32
#define lson son[k][0]
#define rson son[k][1]
#define ws(k) (son[pa[k]][1]==k)
#define canrot(k) (pa[k]&&(son[pa[k]][0]==k||son[pa[k]][1]==k))
#define U unsigned int

using namespace std;

const int nand[2][2]={{1,1},{1,0}};
int n,m,p;
struct LCT{
	int tot,pa[maxn],son[maxn][2],rev[maxn],val[maxn][maxk],ltran[maxn][maxk][2],rtran[maxn][maxk][2];
	void init(){
		for(int i=0;i<p;++i){
			ltran[0][i][0]=0;ltran[0][i][1]=1;
			rtran[0][i][0]=0;rtran[0][i][1]=1;
		}
	}
	void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	void pushup(int k){
		for(int i=0;i<p;++i){
			ltran[k][i][0]=ltran[rson][i][nand[ltran[lson][i][0]][val[k][i]]];
			ltran[k][i][1]=ltran[rson][i][nand[ltran[lson][i][1]][val[k][i]]];
			rtran[k][i][0]=rtran[lson][i][nand[rtran[rson][i][0]][val[k][i]]];
			rtran[k][i][1]=rtran[lson][i][nand[rtran[rson][i][1]][val[k][i]]];
		}
	}
	void molify_val(int k,int x){
		for(int i=0;i<p;++i,x>>=1)val[k][i]=x&1;
		splay(k);
	}
	void molify_rev(U k){
		rev[k]^=1;
		swap(lson,rson);
		swap(ltran[k],rtran[k]);
	}
	void pushdown(int k){
		if(rev[k])rev[k]=0,molify_rev(lson),molify_rev(rson);
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
		pa[x]=0;son[y][0]=0;
		pushup(y);
	}
	U query(int a,int b){
		makeroot(a);access(b);
		splay(b);
		U tmp=0;
		for(int i=p-1;i>=0;--i)tmp=(tmp<<1)+ltran[b][i][0];
		return tmp;
	}
}T;

int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	T.init();
	for(int i=1;i<=n;++i){
		U x;scanf("%u",&x);
		T.molify_val(i,x);
	}
	for(int i=1;i<n;++i){
		int a,b;scanf("%d%d",&a,&b);
		T.link(a,b);
	}
	for(int i=1;i<=m;++i){
		char op[10];U a,b;scanf("\n%s%u%u",op,&a,&b);
		if(op[0]=='R'){
			T.molify_val(a,b);
		}else{
			printf("%u\n",T.query(a,b));
		}
	}
	return 0;
}
