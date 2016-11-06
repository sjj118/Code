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
const int N=4e5+10,P=4e6;
int n;
struct SGT{
	int tot,son[P][2],val[P];
	void update(int k){val[k]=val[ls]+val[rs];}
	int merge(int a,int b,LL&x1,LL&x2){
		if(!a||!b)return a+b;
		x1+=(LL)val[son[a][0]]*val[son[b][1]];
		x2+=(LL)val[son[a][1]]*val[son[b][0]];
		val[a]+=val[b];
		son[a][0]=merge(son[a][0],son[b][0],x1,x2);
		son[a][1]=merge(son[a][1],son[b][1],x1,x2);
		return a;
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
	int root[N],tot,son[N][2],val[N];
	void input(int&k){
		if(!k)k=++tot;
		scanf("%d",&val[k]);
		if(!val[k])input(ls),input(rs);
	}
	LL dfs(int k){
		if(val[k])return 0;
		LL ret=dfs(ls)+dfs(rs);
		LL cnt1=0,cnt2=0;
		root[k]=T.merge(root[ls],root[rs],cnt1,cnt2);
		ret+=min(cnt1,cnt2);
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
//	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
