#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 100005
#define ws(x) (son[pa[x]][1]==x)
#define lson(k) son[k][0]
#define rson(k) son[k][1]

using namespace std;

int n,m,q;
struct UFS{
	int pa[maxn];
	int find(int x){
		if(pa[x]==x)return x;
		return pa[x]=find(pa[x]);
	}
	UFS(){
		for(int i=1;i<maxn;++i)pa[i]=i;
	}
} S;
struct splay_tree{
	int pa[maxn],son[maxn][2],size[maxn],val[maxn],tot;
	void set(int a,int b,int c){
		pa[a]=b;
		son[b][c]=a;
	}
	void pushup(int k){
		size[k]=size[lson(k)]+size[rson(k)]+1;
	}
	void pushdown(int k){
		
	}
	void rot(int k){
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
			if(pa[pa[k]]!=fa&&ws(k)==ws(pa[k]))rot(pa[k]);
			rot(k);
		}
		pushup(k);
	}
	int newNode(int x){
		val[++tot]=x;
		size[tot]=1;
		return tot;
	}
	int Pth(int k,int p){
		splay(k);
		if(p>size[k])return -1;
		while(k){
			if(p<=size[lson(k)])k=lson(k);
			else if(p==size[lson(k)]+1)break;
			else p-=size[lson(k)]+1,k=rson(k);
		}
		return k;
	}
	void insert(int k,int x){
		while(k){
			if(val[x]<val[k]){
				if(lson(k))k=lson(k);
				else{
					set(x,k,0);
					break;
				}
			}else{
				if(rson(k))k=rson(k);
				else{
					set(x,k,1);
					break;
				}
			}
		}
		splay(x);
	}
	int last;
	void merge(int x,int y){
		if(S.find(x)==S.find(y))return;
		splay(x);splay(y);
		if(size[x]>size[y])swap(x,y);
		pa[x]=y;
		queue<int> q;
		q.push(x);
		last=y;
		while(!q.empty()){
			int k=q.front();
			q.pop();
			if(lson(k))q.push(lson(k));lson(k)=0;
			if(rson(k))q.push(rson(k));rson(k)=0;
			insert(last,k);
			last=k;
		}
		splay(x);
	}
} T;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		T.newNode(x);
	}
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		T.merge(a,b);
	}
	scanf("%d",&q);
	for(int i=0;i<q;++i){
		char op;
		int x,y;
		scanf("\n%c%d%d",&op,&x,&y);
		if(op=='B'){
			T.merge(x,y);
		}else{
			printf("%d\n",T.Pth(x,y));
		}
	}
	return 0;
}
