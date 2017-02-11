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
#define ls son[k][0]
#define rs son[k][1]
int root[N];
struct SGT{
	int tot,son[P][2];
	LL val[P];
	void update(int k){
		val[k]=val[ls]+val[rs];
	}
	int insert(int p,int v,int k,int l,int r){
		int t=++tot;
		if(l==r){val[t]=val[k]+v;return t;}
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=insert(p,v,ls,l,m),son[t][1]=rs;
		else son[t][0]=ls,son[t][1]=insert(p,v,rs,m+1,r);
		update(t);
		return t;
	}
	LL query(int ll,int rr,int k,int l,int r){
		if(k==0)return 0;
		if(ll<=l&&r<=rr)return val[k];
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,ls,l,m);
		if(ll>m)return query(ll,rr,rs,m+1,r);
		return query(ll,rr,ls,l,m)+query(ll,rr,rs,m+1,r);
	}
}T;
LL Query(int l,int r){
	return T.query(l,r,root[r],1,n)-T.query(l,r,root[l-1],1,n);
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
		root[i]=root[i-1];
		while(p<=n){
			root[i]=T.insert(p,1,root[i],1,n);
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
