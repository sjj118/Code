#include<iostream>
#include<cstdio>
#include<algorithm>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxq=5e5+10,inf=1e9;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
inline void write(int x){
	if(x<0){x=-x;putchar('-');}
	int a[11],l=0;
	while(x)a[++l]=x%10,x/=10;
	while(l)putchar(a[l--]+'0');puts("");
}
int n,m,q;
struct Treap{
	int tot,pa[maxn],ls[maxn],rs[maxn],rnd[maxn],size[maxn],key[maxn];
	void clear(){rep(i,1,n)pa[i]=i;}
	int getroot(int k){return pa[k]==k?k:pa[k]=getroot(pa[k]);}
	int newnode(int x){int k=++tot;rnd[k]=rand();key[k]=x;size[k]=1;return k;}
	void update(int k){size[k]=size[ls[k]]+size[rs[k]]+1;}
	int merge(int a,int b){
		if(!a||!b)return a+b;
		if(rnd[a]<rnd[b])return rs[a]=merge(rs[a],b),update(a),a;
		else return ls[b]=merge(a,ls[b]),update(b),b;
	}
	void split(int k,int p,int&l,int&r){
		if(p==0)l=0,r=k;
		else if(size[ls[k]]==p)l=ls[k],ls[k]=0,update(k),r=k;
		else if(size[ls[k]]>p)split(ls[k],p,l,ls[k]),update(k),r=k;
		else split(rs[k],p-size[ls[k]]-1,rs[k],r),update(k),l=k;
	}
	int pth(int k,int p){
		if(size[k]<p||p<=0)return -1;
		if(size[ls[k]]>=p)return pth(ls[k],p);
		if(size[ls[k]]+1==p)return key[k];
		return pth(rs[k],p-size[ls[k]]-1);
	}
	int rank(int k,int x){
		if(!k)return 1;
		if(key[k]<x)return rank(rs[k],x)+size[ls[k]]+1;
		return rank(ls[k],x);
	}
	void insert(int k,int p){
		int l,r;split(k,rank(k,key[p])-1,l,r);
		int root=merge(l,p);root=merge(root,r);
		pa[p]=pa[k]=pa[root]=root;
	}
	void search(int k,int p){
		if(k==0)return;
		search(ls[k],p);search(rs[k],p);
		ls[k]=rs[k]=0;size[k]=1;insert(getroot(p),k);
	}
	void unio(int a,int b){
		a=getroot(a);b=getroot(b);
		if(a==b)return;
		if(size[a]>size[b])swap(a,b);
		search(a,b);
	}
}T;
struct Edge{
	int a,b,c;
}e[maxq];
bool operator<(Edge a,Edge b){return a.c<b.c;}
struct Query{
	int v,x,k,pos,ans;
}qu[maxq];
bool operator<(Query a,Query b){return a.x<b.x;}
int ans[maxq];
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	T.clear();
	rep(i,1,n)T.newnode(read());
	rep(i,1,m)e[i].a=read(),e[i].b=read(),e[i].c=read();
	rep(i,1,q)qu[i].v=read(),qu[i].x=read(),qu[i].k=read(),qu[i].pos=i;
	sort(qu+1,qu+1+q);sort(e+1,e+1+m);
	for(int i=1,j=1;i<=q;++i){
		while(j<=m&&e[j].c<=qu[i].x){
			T.unio(e[j].a,e[j].b);++j;
		}
		qu[i].ans=T.pth(T.getroot(qu[i].v),T.size[T.getroot(qu[i].v)]+1-qu[i].k);
	}
	rep(i,1,q)ans[qu[i].pos]=qu[i].ans;
	rep(i,1,q)write(ans[i]);
	return 0;
}
