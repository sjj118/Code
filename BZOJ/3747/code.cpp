#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::max;
typedef long long LL;
const int N=1e6+10,P=N<<2;
inline void up(LL&x,LL y){if(y>x)x=y;}
int n,m,w[N],f[N],nxt[N],st[N];
#define ls (k<<1)
#define rs (k<<1|1)
LL add[P],vmax[P];
struct SGT{
	int son[P][2];
	void update(int k){
		vmax[k]=max(vmax[ls],vmax[rs]);
	}
	void maintain_add(int k,LL v){
		add[k]+=v;
		vmax[k]+=v;
	}
	void maintain(int k){
		if(add[k]){
			maintain_add(ls,add[k]);
			maintain_add(rs,add[k]);
			add[k]=0;
		}
	}
	void modify_add(int ll,int rr,LL v,int k,int l,int r){
		if(ll>rr)return;
		if(ll<=l&&r<=rr)return maintain_add(k,v);
		maintain(k);
		int m=(l+r)>>1;
		if(ll<=m)modify_add(ll,rr,v,ls,l,m);
		if(rr>m)modify_add(ll,rr,v,rs,m+1,r);
		update(k);
	}
}T;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&f[i]);
	rep(i,1,m)scanf("%d",&w[i]);
	rep(i,1,m)st[i]=n+1;
	nxt[n+1]=n+1;
	per(i,n,1){
		nxt[i]=st[f[i]];
		st[f[i]]=i;
	}
	LL ans=0;
	per(i,n,1){
		T.modify_add(i,nxt[i]-1,w[f[i]],1,1,n);
		T.modify_add(nxt[i],nxt[nxt[i]]-1,-w[f[i]],1,1,n);
		up(ans,vmax[1]);
	}
	printf("%lld",ans);
	return 0;
}
