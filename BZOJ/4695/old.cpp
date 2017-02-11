
#include<iostream>
#include<cstdio>
#include<assert.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=5e5+10,P=N<<2,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m;
#define ls (k<<1)
#define rs (k<<1|1)
LL sum[P];
struct SGT{
	int val[P],add[P],min1[P],min2[P],max1[P],max2[P],numax[P],numin[P],lb[P],ub[P];
	void update(int k,int l,int r){
		sum[k]=sum[ls]+sum[rs];
		if(min1[ls]<min1[rs]){
			min1[k]=min1[ls];
			numin[k]=numin[ls];
			min2[k]=min(min2[ls],min1[rs]);
		}else if(min1[ls]==min1[rs]){
			min1[k]=min1[ls];
			numin[k]=numin[ls]+numin[rs];
			min2[k]=min(min2[ls],min2[rs]);
		}else{
			min1[k]=min1[rs];
			numin[k]=numin[rs];
			min2[k]=min(min2[rs],min1[ls]);
		}
		if(max1[ls]>max1[rs]){
			max1[k]=max1[ls];
			numax[k]=numax[ls];
			max2[k]=max(max2[ls],max1[rs]);
		}else if(max1[ls]==max1[rs]){
			max1[k]=max1[ls];
			numax[k]=numax[ls]+numax[rs];
			max2[k]=max(max2[ls],max2[rs]);
		}else{
			max1[k]=max1[rs];
			numax[k]=numax[rs];
			max2[k]=max(max2[rs],max1[ls]);
		}
	}
	void apply_add(int v,int k,int l,int r){
		val[k]+=v;
		sum[k]+=(LL)v*(r-l+1);
		add[k]+=v;
		min1[k]+=v;
		min2[k]+=v;
		max1[k]+=v;
		max2[k]+=v;
		lb[k]+=v;
		ub[k]+=v;
	}
	void apply_lb(int v,int k,int l,int r){
		if(min1[k]>=v)return;
		assert(v<min2[k]);
		sum[k]+=(LL)(v-min1[k])*numin[k];
		up(lb[k],v);
		up(ub[k],v);
		up(max1[k],v);
		if(max2[k]==min1[k])up(max2[k],v);
		up(min1[k],v);
	}
	void apply_ub(int v,int k,int l,int r){
		if(max1[k]<=v)return;
		assert(v>max2[k]);
		sum[k]-=(LL)(max1[k]-v)*numax[k];
		dn(ub[k],v);
		dn(lb[k],v);
		dn(min1[k],v);
		if(min2[k]==max1[k])dn(min2[k],v);
		dn(max1[k],v);
		/*if(v<=min1[k]){
			min1[k]=max1[k]=v;
			min2[k]=inf;max2[k]=-inf;
			numin[k]=numax[k]=r-l+1;
		}*/
	}
	void maintain(int k,int l,int r){
		int m=(l+r)>>1;
		if(add[k]){
			apply_add(add[k],ls,l,m);
			apply_add(add[k],rs,m+1,r);
			add[k]=0;
		}
		apply_lb(lb[k],ls,l,m);
		apply_lb(lb[k],rs,m+1,r);
		lb[k]=-inf;
		apply_ub(ub[k],ls,l,m);
		apply_ub(ub[k],rs,m+1,r);
		ub[k]=inf;
	}
	void build(int k,int l,int r){
		if(l==r){
			int v;scanf("%d",&v);
			val[k]=sum[k]=min1[k]=max1[k]=v;
			numax[k]=numin[k]=1;
			min2[k]=inf;max2[k]=-inf;
			return;
		}
		int m=(l+r)>>1;
		lb[k]=-inf;ub[k]=inf;add[k]=0;
		build(ls,l,m);build(rs,m+1,r);
		update(k,l,r);
	}
	void modify_add(int ll,int rr,int v,int k,int l,int r){
		if(ll<=l&&r<=rr)return apply_add(v,k,l,r);
		maintain(k,l,r);
		int m=(l+r)>>1;
		if(ll<=m)modify_add(ll,rr,v,ls,l,m);
		if(rr>m)modify_add(ll,rr,v,rs,m+1,r);
		update(k,l,r);
	}
	void modify_max(int ll,int rr,int v,int k,int l,int r){
		if(v<=min1[k])return;
		if(ll<=l&&r<=rr&&v<min2[k])return apply_lb(v,k,l,r);
		maintain(k,l,r);
		int m=(l+r)>>1;
		if(ll<=m)modify_max(ll,rr,v,ls,l,m);
		if(rr>m)modify_max(ll,rr,v,rs,m+1,r);
		update(k,l,r);
	}
	void modify_min(int ll,int rr,int v,int k,int l,int r){
		if(v>=max1[k])return;
		if(ll<=l&&r<=rr&&v>max2[k])return apply_ub(v,k,l,r);
		maintain(k,l,r);
		int m=(l+r)>>1;
		if(ll<=m)modify_min(ll,rr,v,ls,l,m);
		if(rr>m)modify_min(ll,rr,v,rs,m+1,r);
		update(k,l,r);
	}
	LL query_sum(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return sum[k];
		maintain(k,l,r);
		int m=(l+r)>>1;
		if(rr<=m)return query_sum(ll,rr,ls,l,m);
		if(ll>m)return query_sum(ll,rr,rs,m+1,r);
		return query_sum(ll,rr,ls,l,m)+query_sum(ll,rr,rs,m+1,r);
	}
	int query_max(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return max1[k];
		maintain(k,l,r);
		int m=(l+r)>>1;
		if(rr<=m)return query_max(ll,rr,ls,l,m);
		if(ll>m)return query_max(ll,rr,rs,m+1,r);
		return max(query_max(ll,rr,ls,l,m),query_max(ll,rr,rs,m+1,r));
	}
	int query_min(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return min1[k];
		maintain(k,l,r);
		int m=(l+r)>>1;
		if(rr<=m)return query_min(ll,rr,ls,l,m);
		if(ll>m)return query_min(ll,rr,rs,m+1,r);
		return min(query_min(ll,rr,ls,l,m),query_min(ll,rr,rs,m+1,r));
	}
}T;
int main(){
	scanf("%d",&n);
	T.build(1,1,n);
	scanf("%d",&m);
	rep(i,1,m){
		int op,l,r;scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			int x;scanf("%d",&x);
			T.modify_add(l,r,x,1,1,n);
		}else if(op==2){
			int x;scanf("%d",&x);
			T.modify_max(l,r,x,1,1,n);
		}else if(op==3){
			int x;scanf("%d",&x);
			T.modify_min(l,r,x,1,1,n);
		}else if(op==4){
			printf("%lld\n",T.query_sum(l,r,1,1,n));
		}else if(op==5){
			printf("%d\n",T.query_max(l,r,1,1,n));
		}else{
			printf("%d\n",T.query_min(l,r,1,1,n));
		}
	}
	return 0;
}
