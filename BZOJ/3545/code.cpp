#include<iostream>
#include<cstdio>
#include<algorithm>
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxq=5e5+10;
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
struct SplayTree{
	int son[maxn][2],size[maxn],val[maxn],pa[maxn];
	inline int ws(int k){return son[pa[k]][1]==k;}
	inline void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	inline void update(int k){size[k]=size[ls]+size[rs]+1;}
	inline void rot(int k){
		int f=pa[k],gf=pa[f],w=ws(k);
		set(k,gf,ws(f));set(son[k][!w],f,w);set(f,k,!w);
		update(f);
	}
	inline void splay(int k,int f=0){
		while(pa[k]!=f){
			if(pa[pa[k]]!=f&&ws(k)==ws(pa[k]))rot(pa[k]);rot(k);
		}
		update(k);
	}
	int insert(int p,int k){
		son[pa[p]][ws(p)]=0;pa[p]=0;
		while(k){
			int t=val[k]>val[p]?0:1;
			if(son[k][t])k=son[k][t];
			else{set(p,k,t);break;}
		}
		splay(p);
		return p;
	}
	void search(int k,int&p){
		if(ls)search(ls,p);
		if(rs)search(rs,p);
		p=insert(k,p);
//		int t1=ls,t2=rs;
//		p=insert(k,p);
//		if(t1)search(t1,p);
//		if(t2)search(t2,p);
	}
	void merge(int a,int b){
		splay(a);splay(b);
		if(a==b)return;
		if(pa[a])return;
		if(size[b]>size[a])swap(a,b);
		search(b,a);
	}
	int pth(int k,int p){
		splay(k);
		if(size[k]<p)return -1;
		p=size[k]-p+1;
		while(1){
			if(size[ls]>=p)k=ls;
			else if(size[ls]+1==p){return val[k];}
			else p-=size[ls]+1,k=rs;
		}
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
#include<ctime>
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n)T.val[i]=read();
	rep(i,1,m)e[i].a=read(),e[i].b=read(),e[i].c=read();
	rep(i,1,q)qu[i].v=read(),qu[i].x=read(),qu[i].k=read(),qu[i].pos=i;
	sort(qu+1,qu+1+q);sort(e+1,e+1+m);
	cerr<<clock()<<endl;
	for(int i=1,j=1;i<=q;++i){
		while(j<=m&&e[j].c<=qu[i].x)T.merge(e[j].a,e[j].b),++j;
		qu[i].ans=T.pth(qu[i].v,qu[i].k);
	}
	rep(i,1,q)ans[qu[i].pos]=qu[i].ans;
	rep(i,1,q)write(ans[i]);
	cerr<<clock()<<endl;
	return 0;
}
