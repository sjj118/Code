#include<iostream>
#include<cmath>
#include<cstdio>
#define maxn 100005
#define lson son[k][0]
#define rson son[k][1]

using namespace std;

int n,m;
struct splay_tree{
	int root,pa[maxn],son[maxn][2],value[maxn],tot;
	int size[maxn],sum[maxn],minl[maxn],maxl[maxn];
	bool rev[maxn],inv[maxn],same[maxn];
	int ws(int k){
		return son[pa[k]][1]==k;
	}
	void set(int a,int b,int c){
		pa[a]=b;
		son[b][c]=a;
	}
	int newNode(int x){
		int k=++tot;
		value[k]=x;
		size[k]=1;
		return k;
	}
	void pushup(int k){
		size[k]=size[lson]+size[rson]+1;
		sum[k]=sum[lson]+sum[rson]+value[k];
		minl[k]=min(minl[lson],minl[rson]+sum[lson]+value[k]);
		maxl[k]=max(maxl[lson],maxl[rson]+sum[lson]+value[k]);
	}
	void pushdown(int k){
		if(same[k]){
			if(lson){
				value[lson]=value[k];
				same[lson]=1;
				sum[lson]=value[lson]*size[lson];
				minl[lson]=min(0,sum[lson]);
				maxl[lson]=max(0,sum[lson]);
			}
			if(rson){
				value[rson]=value[k];
				same[rson]=1;
				sum[rson]=value[lson]*size[rson];
				minl[rson]=min(0,sum[rson]);
				maxl[rson]=max(0,sum[rson]);
			}
			same[k]=0;
		}
		if(rev[k]){
			if(lson){
				rev[lson]^=1;
				int t=maxl[lson];
				maxl[lson]=sum[lson]-minl[lson];
				minl[lson]=sum[lson]-t;
				swap(son[lson][0],son[lson][1]);
			}
			if(rson){
				rev[rson]^=1;
				int t=maxl[rson];
				maxl[rson]=sum[rson]-minl[rson];
				minl[rson]=sum[rson]-t;
				swap(son[rson][0],son[rson][1]);
			}
			rev[k]=0;
		}
		if(inv[k]){
			if(lson){
				inv[lson]^=1;
				swap(minl[lson],maxl[lson]);
				value[lson]=-value[lson];
				sum[lson]=-sum[lson];
			}
			if(rson){
				inv[rson]^=1;
				swap(minl[rson],maxl[rson]);
				value[rson]=-value[rson];
				sum[rson]=-sum[rson];
			}
			inv[k]=0;
		}
	}
	void rotate(int k){
		int f=pa[k],gf=pa[f],w=ws(k);
		pushdown(f);
		pushdown(k);
		set(k,gf,ws(f));
		set(son[k][!w],f,w);
		set(f,k,!w);
		pushup(f);
	}
	void splay(int k,int fa=0){
		while(pa[k]!=fa){
			if(pa[pa[k]]!=fa&&ws(k)==ws(pa[k]))rotate(pa[k]);
			rotate(k);
		}
		pushup(k);
		if(!fa)root=k;
	}
	int Pth(int p){
		++p;
		int k=root;
		while(k){
			pushdown(k);
			if(size[lson]>=p)k=lson;
			else if(size[lson]+1==p)return k;
			else{
				p-=size[lson]+1;
				k=rson;
			}
		}
	}
	void Replace(int l,int r,int x){
		splay(Pth(l-1));
		splay(Pth(r+1),root);
		int k=son[son[root][1]][0];
		value[k]=x;
		same[k]=1;
		sum[k]=value[k]*size[k];
		minl[k]=min(0,sum[k]);
		maxl[k]=max(0,sum[k]);
		splay(k);
	}
	void Swap(int l,int r){
		splay(Pth(l-1));
		splay(Pth(r+1),root);
		int k=son[son[root][1]][0];
		rev[k]^=1;
		int t=maxl[k];
		maxl[k]=sum[k]-minl[k];
		minl[k]=sum[k]-t;
		swap(lson,rson);
		splay(k);
	}
	void Invert(int l,int r){
		splay(Pth(l-1));
		splay(Pth(r+1),root);
		int k=son[son[root][1]][0];
		inv[k]^=1;
		swap(minl[k],maxl[k]);
		value[k]=-value[k];
		sum[k]=-sum[k];
		splay(k);
	}
	int Query(int l,int r){
		splay(Pth(l-1));
		splay(Pth(r+1),root);
		int k=son[son[root][1]][0];
		int t=(1-minl[k])/2;
		return t+(abs(sum[k]+t*2)/2);
	}
	void insert(int l,int r,int k){
		splay(Pth(l-1));
		splay(Pth(r+1),root);
		set(k,son[root][1],0);
		splay(k);
	}
	int a[maxn];
	int buil(int l,int r){
		if(l>r)return 0;
		int m=(l+r)>>1;
		int k=newNode(a[m]);
		set(buil(l,m-1),k,0);
		set(buil(m+1,r),k,1);
		pushup(k);
		return k;
	}
	int build(int t){
		for(int i=0;i<t;++i){
			a[i]=getchar()=='('?1:-1;
		}
		return buil(0,t-1);
	}
	splay_tree(){
		root=newNode(0);
		set(newNode(0),root,1);
		splay(tot);
	}
} T;

int main(){
	scanf("%d%d\n",&n,&m);
	T.insert(1,0,T.build(n));
	for(int i=0;i<m;++i){
		char op[10];
		int l,r;
		scanf("\n%s %d %d",op,&l,&r);
		if(op[0]=='R'){
			char c;
			scanf(" %c",&c);
			T.Replace(l,r,c=='('?1:-1);
		}else if(op[0]=='S'){
			T.Swap(l,r);
		}else if(op[0]=='I'){
			T.Invert(l,r);
		}else{
			printf("%d\n",T.Query(l,r));
		}
	}
	return 0;
}
