#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10;
namespace  Treap{
#define ls son[k][0]
#define rs son[k][1]
	int root;
	int son[N][2],rnd[N],val[N],len[N],size[N];
	int pool[N],tot1,tot2;
	int newNode(int v,int l){
		int k;
		if(tot2)k=pool[tot2--];else k=++tot1;
		ls=rs=0;
		val[k]=v;size[k]=len[k]=l;
		rnd[k]=rand();
		return k;
	}
	void delNode(int k){
		pool[++tot2]=k;
	}
	void update(int k){
		size[k]=size[ls]+size[rs]+len[k];
	}
	int merge(int a,int b){
		if(!a||!b)return a+b;
		if(rnd[a]>rnd[b])return son[a][1]=merge(son[a][1],b),update(a),a;
		else return son[b][0]=merge(a,son[b][0]),update(b),b;
	}
	void partNode(int k,int n,int&l,int&r){
		l=k;r=newNode(val[l]+n,len[l]-n);len[l]=n;
		r=merge(r,son[l][1]);son[l][1]=0;
		update(l);update(r);
	}
	void split(int k,int n,int&l,int&r){
		if(n==0)return l=0,r=k,update(k);
		if(n<=size[ls])return split(ls,n,l,ls),r=k,update(k);
		if(n>=size[ls]+len[k])return split(rs,n-size[ls]-len[k],rs,r),l=k,update(k);
		partNode(k,n-size[ls],l,r);
	}
	void Insert(int p,int a,int b){
		int l,r;split(root,p,l,r);
		int k=newNode(a,b-a+1);
		root=merge(l,k);root=merge(root,r);
	}
	void del(int k){
		if(!k)return;
		del(ls);del(rs);
		delNode(k);
	}
	void Delete(int a,int b){
		int l,d,r;
		split(root,a-1,l,d);
		split(d,b-a+1,d,r);
		del(d);
		root=merge(l,r);
	}
	int Query(int p){
		int l,k,r;
		split(root,p-1,l,k);
		split(k,1,k,r);
		int ret=val[k];
		root=merge(l,k);
		root=merge(root,r);
		return ret;
	}
};
int n,m;
int main(){
	srand(20000107);
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;scanf("%d",&x);Treap::Insert(i-1,x,x);}
	rep(i,1,m){
		int op;scanf("%d",&op);
		if(op==0){
			int p,a,b;scanf("%d%d%d",&p,&a,&b);
			Treap::Insert(p,a,b);
		}else if(op==1){
			int a,b;scanf("%d%d",&a,&b);
			Treap::Delete(a,b);
		}else{
			int p;scanf("%d",&p);
			printf("%d\n",Treap::Query(p));
		}
	}
	return 0;
}
