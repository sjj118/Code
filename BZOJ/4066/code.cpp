#include<iostream>
#include<cstdio>
#include<algorithm>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10,inf=1e9;
const double alpha=0.65;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,ans;
struct Point{
	int c[2];
	Point(){}
	Point(int x,int y){c[0]=x;c[1]=y;}
	int operator[](int a)const{return c[a];}
	int&operator[](int a){return c[a];}
};
inline void up(Point&a,const Point&b){rep(i,0,1)up(a[i],b[i]);}
inline void dn(Point&a,const Point&b){rep(i,0,1)dn(a[i],b[i]);}
bool operator<=(const Point&a,const Point&b){rep(i,0,1)if(a[i]>b[i])return 0;return 1;}
bool operator>=(const Point&a,const Point&b){rep(i,0,1)if(a[i]<b[i])return 0;return 1;}
#define ls son[0]
#define rs son[1]
struct Node{
	Node*son[2];
	int val,sum,size;
	Point p,l,r;
	void update(){
		size=ls->size+rs->size+1;
		sum=val+ls->sum+rs->sum;
		l=r=p;
		dn(l,ls->l);dn(l,rs->l);
		up(r,ls->r);up(r,rs->r);
	}
	bool notbalance(){return ls->size>size*alpha||rs->size>size*alpha;}
};
struct cmp{
	int d;
	cmp(int d):d(d){}
	bool operator()(const Node*a,const Node*b){return a->p[d]<b->p[d];}
};
struct KDT{
	Node mem_pool[N];
	Node *tail,*null,*root;
	KDT(){
		tail=mem_pool;
		null=tail++;
		null->ls=null->rs=null;
		null->val=null->sum=null->size=0;
		null->l=Point(inf,inf);null->r=Point(-inf,-inf);
		root=null;
	}
	Node*newnode(const Point&p,int v){
		Node*k=tail++;
		k->ls=k->rs=null;
		k->val=v;
		k->p=p;
		k->update();
		return k;
	}
	void build(Node**l,Node**r,Node*&k,int d){
		if(l==r)return;
		Node**m=l+(r-l)/2;
		nth_element(l,m,r,cmp(d));
		k=*m;
		if(l!=m)build(l,m,k->ls,d^1);
		if(m+1!=r)build(m+1,r,k->rs,d^1);
		k->update();
	}
	void del(Node**&ed,Node*k){
		if(k==null)return;
		*(ed++)=k;
		del(ed,k->ls);del(ed,k->rs);
		k->ls=null;k->rs=null;
	}
	void rebuild(Node*&k,int d){
		static Node*st[N],**ed;
		ed=st;
		del(ed,k);
		build(st,ed,k,d);
	}
	pair<Node**,int> insert(const Point&p,int v,Node*&k,int d){
		if(k==null){k=newnode(p,v);return mp(&null,0);}
		pair<Node**,int> ret;
		if(p[d]<=k->p[d])ret=insert(p,v,k->ls,d^1);
		else ret=insert(p,v,k->rs,d^1);
		k->update();
		if(k->notbalance())ret=mp(&k,d);
		return ret;
	}
	int cnt;
	void insert(const Point&p,int v){
		pair<Node**,int>t=insert(p,v,root,0);
		rebuild(*t.fi,t.se);
	}
	int query(const Point&ll,const Point&rr,Node*k){
		if(ll<=k->l&&k->r<=rr)return k->sum;
		int ret=0;
		if(ll<=k->p&&k->p<=rr)ret+=k->val;
		if(k->ls->r>=ll&&k->ls->l<=rr)ret+=query(ll,rr,k->ls);
		if(k->rs->r>=ll&&k->rs->l<=rr)ret+=query(ll,rr,k->rs);
		return ret;
	}
	int query(const Point&ll,const Point&rr){
		return query(ll,rr,root);
	}
}T;
int i;
int main(){
	scanf("%d",&n);
	int op;
	while((op=read())!=3){
		++i;
		if(op==1){
			int x=read()^ans,y=read()^ans,a=read()^ans;
			T.insert(Point(x,y),a);
		}else{
			int x1=read()^ans,y1=read()^ans,x2=read()^ans,y2=read()^ans;
			printf("%d\n",T.query(Point(x1,y1),Point(x2,y2)));
		}
	}
	return 0;
}
