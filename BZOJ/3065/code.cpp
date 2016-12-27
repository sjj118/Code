#include<iostream>
#include<cstdio>
#include<cstdlib>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=70000+10;
int n,q,a[N],b[N],c[N];
#define ls son[k][0]
#define rs son[k][1]
const int P=3e7;
struct SGT{
	int tot1,tot2,ba[P];
	int son[P][2],val[P];
	void delnode(int k){
		ba[++tot2]=k;
		val[k]=son[k][0]=son[k][1]=0;
	}
	int newnode(){
		int t;
		if(tot2)t=ba[tot2--];
		else t=++tot1;
		return t;
	}
	void update(int k){
		val[k]=val[ls]+val[rs];
	}
	void modify(int p,int v,int&k,int l,int r){
		if(!k)k=newnode();
		if(l==r){val[k]+=v;return;}
		int m=(l+r)>>1;
		if(p<=m)modify(p,v,ls,l,m);
		else modify(p,v,rs,m+1,r);
		update(k);
	}
	void clear(int k){
		if(!k)return;
		if(ls)clear(ls);
		if(rs)clear(rs);
		delnode(k);
	}
	int copy(int k1,int k2){
		int k=newnode();
		val[k]=val[k1]+val[k2];
		if(son[k1][0]||son[k2][0])ls=copy(son[k1][0],son[k2][0]);
		if(son[k1][1]||son[k2][1])rs=copy(son[k1][1],son[k2][1]);
		return k;
	}
}sgt;
struct Treap{
	int rt,son[N][2],root[N],rnd[N],size[N];
	void update(int k){
		size[k]=size[ls]+size[rs]+1;
		root[k]=sgt.copy(root[ls],root[rs]);
		sgt.modify(a[k],1,root[k],0,N);
	}
	int sta[N],top;
	int build(int*b,int n){
		rep(i,1,n)sgt.clear(root[b[i]]);
		top=0;sta[1]=0;
		rep(i,1,n){
			while(top&&rnd[b[i]]>rnd[sta[top]])update(sta[top--]);
			son[b[i]][0]=sta[top+1];
			if(top)son[sta[top]][1]=b[i];
			son[b[i]][1]=0;
			sta[++top]=b[i];
			sta[top+1]=0;
		}
		while(top)update(sta[top--]);
		return sta[1];
	}
	void search(int k,int p,int t,int&m){
		if(!k)return;
		if(ls)search(ls,p,t,m);
		if(m==p)b[++m]=t;
		b[++m]=k;
		if(rs)search(rs,p,t,m);
	}
	void insert(int&k,int p,int t){
		if(rnd[t]<rnd[k]){
			if(size[ls]>=p)insert(ls,p,t);
			else insert(rs,p-size[ls]-1,t);
			++size[k];
			sgt.modify(a[t],1,root[k],0,N);
		}else{
			int m=0;
			search(k,p,t,m);
			if(p==m)b[++m]=t;
			k=build(b,m);
		}
	}
	void modify(int k,int p,int&x,int y){
		if(size[ls]>=p)modify(ls,p,x,y);
		else if(size[ls]+1<p)modify(rs,p-size[ls]-1,x,y);
		else x=a[k],a[k]=y;
		sgt.modify(x,-1,root[k],0,N);
		sgt.modify(y,1,root[k],0,N);
	}
	void get(int ll,int rr,int k,int l,int r,int&t,int&t2){
		if(ll<=l&&r<=rr){b[++t]=root[k];return;}
		int m=l+size[ls];
		if(ll<=m&&m<=rr)c[++t2]=a[k];
		if(ll<m)get(ll,rr,ls,l,m-1,t,t2);
		if(rr>m)get(ll,rr,rs,m+1,r,t,t2);
	}
	int query(int l,int r,int p){
		int t=0,t2=0;
		get(l,r,rt,1,size[rt],t,t2);
		l=0;r=N;
		while(l<r){
			int m=(l+r)>>1;
			int cnt=0;
			rep(i,1,t)cnt+=sgt.val[sgt.son[b[i]][0]];
			rep(i,1,t2)cnt+=l<=c[i]&&c[i]<=m;
			if(cnt>=p){
				rep(i,1,t)b[i]=sgt.son[b[i]][0];
				r=m;
			}else{
				p-=cnt;
				rep(i,1,t)b[i]=sgt.son[b[i]][1];
				l=m+1;
			}
		}
		return l;
	}
}T;
int main(){
	//freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	srand(20000107);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	scanf("%d",&q);
	rep(i,1,n)b[i]=i;
	rep(i,1,n)T.rnd[i]=rand();
	T.rt=T.build(b,n);
	int ans=0;
	while(q--){
		char op;scanf("\n%c",&op);
		if(op=='Q'){
			int x,y,k;scanf("%d%d%d",&x,&y,&k);
			x^=ans;y^=ans;k^=ans;
			printf("%d\n",ans=T.query(x,y,k));
		}else if(op=='M'){
			int x,y;scanf("%d%d",&x,&y);
			x^=ans;y^=ans;
			int tmp=0;
			T.modify(T.rt,x,tmp,y);
		}else{
			int x,y;scanf("%d%d",&x,&y);
			x^=ans;y^=ans;
			a[++n]=y;T.rnd[n]=rand();
			T.insert(T.rt,x-1,n);
		}
	}
	return 0;
}
