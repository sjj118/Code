#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::swap;
typedef long long LL;
const int N=3e5+10,P=2e7;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
inline void write(LL x){
	int a[20],l=0;
	while(x)a[++l]=x%10,x/=10;
	if(l==0)putchar('0');
	per(i,l,1)putchar(a[i]+'0');
	putchar('\n');
}
int n,m,type,a[N],rfh[N];
struct Node{
	LL v;
	Node*ls,*rs;
	void update(){
		v=ls->v+rs->v;
	}
};
struct SGT{
private:
	Node mem_pool[P],*null,*tail,*root[N];
	Node*NewNode(LL v,Node*ls,Node*rs){
		Node*k=tail++;
		k->ls=ls;
		k->rs=rs;
		k->v=v;
		return k;
	}
	Node*CloneNode(Node*k){
		return NewNode(k->v,k->ls,k->rs);
	}
	Node*Insert(int p,LL v,Node*k,int l,int r){
		Node*t=CloneNode(k);
		if(l==r){t->v+=v;return t;}
		int m=(l+r)>>1;
		if(p<=m)t->ls=Insert(p,v,k->ls,l,m);
		else t->rs=Insert(p,v,k->rs,m+1,r);
		t->update();
		return t;
	}
	LL Query(int ll,int rr,Node*k,int l,int r){
		if(k==null)return 0;
		if(ll<=l&&r<=rr)return k->v;
		int m=(l+r)>>1;
		if(rr<=m)return Query(ll,rr,k->ls,l,m);
		if(ll>m)return Query(ll,rr,k->rs,m+1,r);
		return Query(ll,rr,k->ls,l,m)+Query(ll,rr,k->rs,m+1,r);
	}
public:
	SGT(){
		tail=mem_pool;
		null=NewNode(0,null,null);
		null->ls=null;null->rs=null;
		root[0]=NewNode(0,null,null);
	}
	void CloneRoot(int k,int p){
		root[k]=root[p];
	}
	void Insert(int k,int p,int v){
		root[k]=Insert(p,v,root[k],1,n);
	}
	LL Query(int k,int l,int r){
		return Query(l,r,root[k],1,n);
	}
}T;
LL Query(int l,int r){
	return T.Query(r,l,r)-T.Query(l-1,l,r);
}
int main(){
	scanf("%d%d%d",&n,&m,&type);
	rep(i,1,n)a[i]=read();
	per(i,n,1){
		rfh[i]=i+1;
		while(rfh[i]<=n&&a[rfh[i]]<=a[i])rfh[i]=rfh[rfh[i]];
	}
	rep(i,1,n){
		int p=i+1;
		T.CloneRoot(i,i-1);
		while(p<=n){
			T.Insert(i,p,1);
			if(a[p]>=a[i])break;
			p=rfh[p];
		}
	}
	LL ans=0;
	while(m--){
		int l=read(),r=read();
		if(type)l=(l+ans-1)%n+1,r=(r+ans-1)%n+1;
		if(l>r)swap(l,r);
		write(ans=Query(l,r));
	}
	return 0;
}
