#include<iostream>
#include<cstdio>
#define ls (k<<1)
#define rs (k<<1|1)
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=1e5+10,P=4*N;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
int n,m;
LL lr1[N];
struct Data{
	LL l,v,s,sl,sr,slr;
	Data&operator+=(LL x){
		v+=x;
		s+=x*l;
		sl+=x*(l+1)*l/2;
		sr+=x*(l+1)*l/2;
		slr+=x*lr1[l];
		return *this;
	}
};
Data operator+(const Data&a,const Data&b){
	Data ret;
	ret.l=a.l+b.l;
	ret.v=0;
	ret.s=a.s+b.s;
	ret.sl=a.sl+b.sl+b.s*a.l;
	ret.sr=b.sr+a.sr+a.s*b.l;
	ret.slr=a.slr+a.sl*b.l+b.slr+b.sr*a.l;
	return ret;
}
struct SGT{
	Data data[P];
	void build(int k,int l,int r){
		if(l==r){data[k].l=1;return;}
		int m=(l+r)>>1;
		build(ls,l,m);build(rs,m+1,r);
		update(k);
	}
	void update(int k){data[k]=data[ls]+data[rs];}
	void maintain(int k){
		if(data[k].v)data[ls]+=data[k].v,data[rs]+=data[k].v,data[k].v=0;
	}
	void modify(int ll,int rr,int v,int k,int l,int r){
		if(ll<=l&&r<=rr){data[k]+=v;return;}
		maintain(k);
		int m=(l+r)>>1;
		if(ll<=m)modify(ll,rr,v,ls,l,m);
		if(rr>m)modify(ll,rr,v,rs,m+1,r);
		update(k);
	}
	Data query(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return data[k];
		maintain(k);
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,ls,l,m);
		if(ll>m)return query(ll,rr,rs,m+1,r);
		return query(ll,rr,ls,l,m)+query(ll,rr,rs,m+1,r);
	}
}T;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)lr1[i]=lr1[i-1]+i+1ll*i*(i-1)/2;
	T.build(1,1,n-1);
	rep(i,1,m){
		char c;scanf("\n%c",&c);
		if(c=='C'){
			int l,r,v;scanf("%d%d%d",&l,&r,&v);
			T.modify(l,r-1,v,1,1,n-1);
		}else{
			int l,r;scanf("%d%d",&l,&r);
			LL p=T.query(l,r-1,1,1,n-1).slr;
			LL q=(LL)(r-l+1)*(r-l)/2;
			LL d=gcd(p,q);
			p/=d;q/=d;
			printf("%lld/%lld\n",p,q);
		}
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
