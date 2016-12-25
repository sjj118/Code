#include<bits/stdc++.h>
#define cls(a) memset(a,0,sizeof(a))
#define rg 
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
int n,m,arr[N];
#define ls son[k][0]
#define rs son[k][1]
const int P=N<<5;
struct SGT{
	int tot,son[P][2],val[P],rt;
	void update(int k,int(*f)(int,int)){
		val[k]=f(val[ls],val[rs]);
	}
	void modify(int p,int v,int&k,int l,int r,int(*f)(int,int)){
		if(!k)k=++tot,val[k]=-f(inf,-inf);
		if(l==r){val[k]=f(val[k],v);return;}
		int m=(l+r)>>1;
		if(p<=m)modify(p,v,ls,l,m,f);
		else modify(p,v,rs,m+1,r,f);
		update(k,f);
	}
	int query(int ll,int rr,int k,int l,int r,int(*f)(int,int)){
		if(!k)return -f(inf,-inf);
		if(ll<=l&&r<=rr)return val[k];
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,ls,l,m,f);
		if(ll>m)return query(ll,rr,rs,m+1,r,f);
		return f(query(ll,rr,ls,l,m,f),query(ll,rr,rs,m+1,r,f));
	}
	void clear(){rep(i,1,tot)son[i][0]=son[i][1]=val[i]=0;tot=rt=1;}
}T;
#undef ls
#undef rs
#define ls (k<<1)
#define rs (k<<1|1)
const int P2=N<<2;
struct SGT2{
	int val[P2],mark[P2];
	void maintain_mark(int k,int v){
		val[k]+=v;mark[k]+=v;
	}
	void maintain(int k){
		if(mark[k])maintain_mark(ls,mark[k]),maintain_mark(rs,mark[k]),mark[k]=0;
	}
	void update(int k){
		val[k]=min(val[ls],val[rs]);
	}
	void modify(int ll,int rr,int v,int k,int l,int r){
		if(ll<=l&&r<=rr){maintain_mark(k,v);return;}
		int m=(l+r)>>1;
		if(ll<=m)modify(ll,rr,v,ls,l,m);
		if(rr>m)modify(ll,rr,v,rs,m+1,r);
		update(k);
	}
	int query(int k){
		if(val[k])return 0;
		int t=query(rs);
		if(t)return t;
		return query(ls);
	}
	void clear(){cls(val);cls(mark);}
}Y;
struct LinkMap{
	int tot,head[N],next[N],to[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void clear(){cls(head);tot=0;}
}lp;
int lf[N],rf[N];
bool check(int x){
	T.clear();
	rep(i,1,n){
		lf[i]=T.query(arr[i]-x,arr[i]+x,T.rt,0,inf,max);
		T.modify(arr[i],i,T.rt,0,inf,max);
	}
	T.clear();
	per(i,n,1){
		rf[i]=T.query(arr[i]-x,arr[i]+x,T.rt,0,inf,min);
		T.modify(arr[i],i,T.rt,0,inf,min);
	}
	Y.clear();lp.clear();
	rep(i,1,n)if(lf[i]<=0)Y.modify(i+1,rf[i],1,1,1,n);else lp.ins(lf[i],i);
	rep(i,1,n){
		if(Y.query(1)-i+1>=m)return 1;
		for(int p=lp.head[i];p;p=lp.next[p])Y.modify(lp.to[p]+1,rf[lp.to[p]+1],1,1,1,n);
		Y.modify(i+1,rf[i],-1,1,1,n);
	}
	return 0;
}
class FindingFriends{
public:
	int shortestDistance(int n,vector<int> init,int a,int b,int c,int d,int m){
		rep(i,1,n){
			if(i<=init.size())arr[i]=init[i-1];
			else arr[i]=(1ll*arr[i-1]*a+1ll*b*(i-1)+c)%d;
		}
		int l=0,r=d;
		::n=n;::m=m;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid;else l=mid+1;
		}
		return l;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
