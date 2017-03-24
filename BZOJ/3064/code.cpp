#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::max;
inline void up(int&x,int y){if(y>x)x=y;}
const int N=1e5+10,P=N<<2,_inf=-2147483648;
int n,m;
struct SGT{
#define ls (k<<1)
#define rs (k<<1|1)
	int tot,son[P][2];
	int val[P],add[P],his[P],pre[P],maxsame[P],same[P];
	bool isame[P];
	void update(int k){
		val[k]=max(val[ls],val[rs]);
		his[k]=max(his[ls],his[rs]);
	}
	void maintain_same(int k,int v,int p){
		up(maxsame[k],p);
		isame[k]=1;
		same[k]=v;
		val[k]=v;
		add[k]=0;
		up(his[k],p);
	}
	void maintain_add(int k,int v,int p){
		if(isame[k])return maintain_same(k,val[k]+v,val[k]-add[k]+p);
		up(pre[k],add[k]+p);
		val[k]+=v;add[k]+=v;
		up(his[k],val[k]-add[k]+pre[k]);
	}
	void maintain(int k){
		maintain_add(ls,add[k],pre[k]);
		maintain_add(rs,add[k],pre[k]);
		add[k]=0;pre[k]=0;
		if(isame[k]){
			maintain_same(ls,same[k],maxsame[k]);
			maintain_same(rs,same[k],maxsame[k]);
			isame[k]=0;
		}
	}
	void build(int k,int l,int r){
		maxsame[k]=_inf;
		if(l==r){scanf("%d",&val[k]);his[k]=val[k];return;}
		int m=(l+r)>>1;
		build(ls,l,m);build(rs,m+1,r);
		update(k);
	}
	int query_val(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return val[k];
		maintain(k);
		int m=(l+r)>>1;
		if(rr<=m)return query_val(ll,rr,ls,l,m);
		if(ll>m)return query_val(ll,rr,rs,m+1,r);
		return max(query_val(ll,rr,ls,l,m),query_val(ll,rr,rs,m+1,r));
	}
	int query_his(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return his[k];
		maintain(k);
		int m=(l+r)>>1;
		if(rr<=m)return query_his(ll,rr,ls,l,m);
		if(ll>m)return query_his(ll,rr,rs,m+1,r);
		return max(query_his(ll,rr,ls,l,m),query_his(ll,rr,rs,m+1,r));
	}
	void modify_add(int ll,int rr,int v,int k,int l,int r){
		if(ll<=l&&r<=rr)return maintain_add(k,v,v);
		maintain(k);
		int m=(l+r)>>1;
		if(ll<=m)modify_add(ll,rr,v,ls,l,m);
		if(rr>m)modify_add(ll,rr,v,rs,m+1,r);
		update(k);
	}
	void modify_same(int ll,int rr,int v,int k,int l,int r){
		if(ll<=l&&r<=rr)return maintain_same(k,v,v);
		maintain(k);
		int m=(l+r)>>1;
		if(ll<=m)modify_same(ll,rr,v,ls,l,m);
		if(rr>m)modify_same(ll,rr,v,rs,m+1,r);
		update(k);
	}
}T;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d",&n);
	T.build(1,1,n);
	scanf("%d",&m);
	while(m--){
		char op;scanf("\n%c",&op);
		if(op=='Q'){
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",T.query_val(x,y,1,1,n));
		}else if(op=='A'){
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",T.query_his(x,y,1,1,n));
		}else if(op=='P'){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			T.modify_add(x,y,z,1,1,n);
		}else{
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			T.modify_same(x,y,z,1,1,n);
		}
	}
	return 0;
}
