#include<iostream>
#include<cstdio>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;

namespace sjj118{
	
typedef long long LL;
const int N=1e5+10,P=30*N*2,inf=1e7;
int m,n,root[N];
struct SGT{
#define ls son[k][0]
#define rs son[k][1]
	int tot,son[P][2];
	LL val[P],sum[P];
	void update(int k,int l,int r){
		if(l==r){sum[k]=l*val[k];return;}
		val[k]=val[ls]+val[rs];
		sum[k]=sum[ls]+sum[rs];
	}
	int modify_val(int p,int v,int k,int l,int r){
		int t=++tot;
		if(l==r){val[t]=val[k]+v;update(t,l,r);return t;}
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=modify_val(p,v,ls,l,m),son[t][1]=rs;
		else son[t][0]=ls,son[t][1]=modify_val(p,v,rs,m+1,r);
		update(t,l,r);
		return t;
	}
	LL query(int p,int k,int l,int r){
		if(p>=val[k])return sum[k];
		if(l==r)return (LL)l*p;
		int m=(l+r)>>1;
		LL ret=query(p,ls,l,m);
		if(p>val[ls])ret+=query(p-val[ls],rs,m+1,r);
		return ret;
	}
}T;
struct LinkMap{
	int tot,head[N],next[N<<1],val[N<<1],dta[N<<1];
	void ins(int t,int v,int d){val[++tot]=v;dta[tot]=d;next[tot]=head[t];head[t]=tot;}
	void work(int k){
		for(int p=head[k];p;p=next[p])root[k]=T.modify_val(val[p],dta[p],root[k],1,inf);
	}
}lp;
LL ans=1;
int main(){
	scanf("%d%d",&m,&n);
	rep(i,1,m){
		int s,e,p;scanf("%d%d%d",&s,&e,&p);
		lp.ins(s,p,1);lp.ins(e+1,p,-1);
	}
	rep(i,1,n){
		root[i]=root[i-1];
		lp.work(i);
	}
	rep(i,1,n){
		int x,k,a,b,c;scanf("%d%d%d%d",&x,&a,&b,&c);
		k=1+((LL)a*ans+b)%c;
		ans=T.query(k,root[x],1,inf);
		printf("%lld\n",ans);
	}
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
