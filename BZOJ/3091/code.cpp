#include<iostream>
#include<cstdio>
#define maxn 50010
#define lson son[k][0]
#define rson son[k][1]
#define inf 1e9
#define ws(k) (son[pa[k]][1]==k)
#define canrot(k) (pa[k]&&(son[pa[k]][0]==k||son[pa[k]][1]==k))
#define LL long long

using namespace std;

int n,m;
LL gcd(LL a,LL b){
	if(b==0)return a;
	return gcd(b,a%b);
}
struct LCT{
	int pa[maxn],son[maxn][2],rev[maxn];
	LL E[maxn],sum[maxn],rmul[maxn],lmul[maxn],add[maxn],smul[maxn],val[maxn],size[maxn];
	void pushup(int k){
		size[0]=sum[0]=E[0]=lmul[0]=rmul[0]=smul[0]=0;
		size[k]=size[lson]+size[rson]+1;
		sum[k]=sum[lson]+sum[rson]+val[k];
		lmul[k]=lmul[lson]+val[k]*(1+size[lson])+lmul[rson]+sum[rson]*(1+size[lson]);
		rmul[k]=rmul[rson]+val[k]*(1+size[rson])+rmul[lson]+sum[lson]*(1+size[rson]);
		smul[k]=smul[lson]+smul[rson]+(size[lson]*(size[lson]+1)/2)*(1+size[rson])+(size[rson]*(size[rson]+1)/2)*(1+size[lson])+(size[lson]+1)*(size[rson]+1);
		E[k]=E[lson]+E[rson]+lmul[lson]*(1+size[rson])+rmul[rson]*(1+size[lson])+val[k]*(1+size[lson])*(1+size[rson]);
	}
	void molify_rev(int k){
		rev[k]^=1;
		swap(lmul[k],rmul[k]);
		swap(lson,rson);
	}
	void molify_add(int k,LL x){
		add[k]+=x;
		val[k]+=x;
		sum[k]+=x*size[k];
		lmul[k]+=x*(size[k]*(1+size[k])/2);
		rmul[k]+=x*(size[k]*(1+size[k])/2);
		E[k]+=x*smul[k];
	}
	void pushdown(int k){
		if(rev[k])rev[k]=0,molify_rev(lson),molify_rev(rson);
		if(add[k])molify_add(lson,add[k]),molify_add(rson,add[k]),add[k]=0;
	}
	void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
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
	bool islink(int x,int y){
		return getroot(y)==getroot(x);
	}
	bool hasedge(int x,int y){
		if(!islink(x,y))return 0;
		makeroot(x);access(y);splay(y);
		return pa[x]==y&&son[x][1]==0;
	}
	void molify_val(int k,int x){
		val[k]=x;
		pushup(k);
	}
	LL getE(int u,int v){
		makeroot(u);access(v);splay(v);
		return E[v];
	}
}T;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		LL x;scanf("%lld",&x);
		T.molify_val(i,x);
	}
	for(int i=1;i<n;++i){
		int u,v;scanf("%d%d",&u,&v);
		T.link(u,v);
	}
	for(int i=1;i<=m;++i){
		int op;scanf("%d",&op);
		if(op==1){
			int u,v;scanf("%d%d",&u,&v);
			if(T.hasedge(u,v))T.cut(u,v);
		}else if(op==2){
			int u,v;scanf("%d%d",&u,&v);
			if(!T.islink(u,v))T.link(u,v);
		}else if(op==3){
			int u,v,d;scanf("%d%d%d",&u,&v,&d);
			if(T.islink(u,v)){
				T.makeroot(u);T.access(v);T.splay(v);
				T.molify_add(v,d);
			}
		}else{
			int u,v;scanf("%d%d",&u,&v);
			if(T.islink(u,v)){
				LL p=T.getE(u,v),q=T.size[v]*(T.size[v]+1)/2;
				LL d=gcd(p,q);
				p/=d;q/=d;
				printf("%lld/%lld\n",p,q);
			}else{
				printf("-1\n");
			}
		}
	}
	return 0;
}
