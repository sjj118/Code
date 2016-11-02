#include<iostream>
#include<cstdio>
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=4e5+10,P=1e7;
int n;
struct SGT{
	int tot,son[P][2],val[P];
	void update(int k){val[k]=val[ls]+val[rs];}
	void merge(int&k,int p){
		if(p==0)return;
		if(k==0){k=p;return;}
		val[k]+=val[p];
		merge(ls,son[p][0]);
		merge(rs,son[p][1]);
	}
	int query(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return val[k];
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,ls,l,m);
		if(ll>m)return query(ll,rr,rs,m+1,r);
		return query(ll,rr,ls,l,m)+query(ll,rr,rs,m+1,r);
	}
	void modify(int p,int v,int&k,int l,int r){
		if(!k)k=++tot;
		if(l==r){val[k]+=v;return;}
		int m=(l+r)>>1;
		if(p<=m)modify(p,v,ls,l,m);
		else modify(p,v,rs,m+1,r);
		update(k);
	}
}T;
struct Tree{
	int root[N],tot,son[N][2],val[N],size[N];
	void input(int&k){
		if(!k)k=++tot;
		scanf("%d",&val[k]);
		if(!val[k])input(ls),input(rs);
	}
	LL foreach(int k,int rt){
		if(val[k])return T.query(1,val[k],rt,1,n);
		return foreach(ls,rt)+foreach(rs,rt);
	}
	LL dfs(int k){
		if(val[k]){size[k]=1;return 0;}
		LL ret=dfs(ls)+dfs(rs);
		size[k]=size[ls]+size[rs];
		if(size[ls]<size[rs])swap(ls,rs);
		LL t=foreach(rs,root[ls]);
		ret+=min(t,1ll*size[ls]*size[rs]-t);
		root[k]=root[ls];T.merge(root[k],root[rs]);
		return ret;
	}
	void init(int k){
		if(val[k])T.modify(val[k],1,root[k],1,n);
		else init(ls),init(rs);
	}
}G;
int main(){
	scanf("%d",&n);
	int rt=0;
	G.input(rt);
	G.init(rt);
	printf("%lld",G.dfs(rt));
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
