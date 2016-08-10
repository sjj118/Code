#include<iostream>
#include<cstdio>
#define maxn 100009
#define lson son[k][0]
#define rson son[k][1]
#define LL long long

using namespace std;

int n,P,m;
struct segtree{
	int son[maxn<<1][2],tot;
	LL mul[maxn<<1],add[maxn<<1],sum[maxn<<1];
	void pushup(int k){
		if(lson)sum[k]=(sum[lson]+sum[rson])%P;
	}
	void pushdown(int k,int l,int r){
		if(lson){
			int m=(l+r)>>1;
			sum[lson]=(sum[lson]*mul[k]+add[k]*(m-l+1))%P;
			sum[rson]=(sum[rson]*mul[k]+add[k]*(r-m))%P;
			mul[lson]=mul[lson]*mul[k]%P;
			mul[rson]=mul[rson]*mul[k]%P;
			add[lson]=(add[lson]*mul[k]+add[k])%P;
			add[rson]=(add[rson]*mul[k]+add[k])%P;
		}
		mul[k]=1;add[k]=0;
	}
	void build(int k,int l,int r){
		pushdown(k,l,r);
		if(l==r)scanf("%lld",&sum[k]),sum[k]%=P;
		else{
			int m=(l+r)>>1;
			build(lson=++tot,l,m);
			build(rson=++tot,m+1,r);
		}
		pushup(k);
	}
	void cheng(int ll,int rr,int v,int k,int l,int r){
		pushdown(k,l,r);
		if(l>=ll&&r<=rr){
			sum[k]=sum[k]*v%P;
			mul[k]=mul[k]*v%P;
			add[k]=add[k]*v%P;
		}else{
			int m=(l+r)>>1;
			if(ll<=m)cheng(ll,rr,v,lson,l,m);
			if(rr>m)cheng(ll,rr,v,rson,m+1,r);
			pushup(k);
		}
	}
	void jia(int ll,int rr,int v,int k,int l,int r){
		pushdown(k,l,r);
		if(l>=ll&&r<=rr){
			sum[k]=(sum[k]+v*(r-l+1))%P;
			add[k]=(add[k]+v)%P;
		}else{
			int m=(l+r)>>1;
			if(ll<=m)jia(ll,rr,v,lson,l,m);
			if(rr>m)jia(ll,rr,v,rson,m+1,r);
			pushup(k);
		}
	}
	int query(int ll,int rr,int k,int l,int r){
		pushdown(k,l,r);
		if(l>=ll&&r<=rr)return sum[k];
		else{
			int m=(l+r)>>1;
			if(ll>m)return query(ll,rr,rson,m+1,r);
			else if(rr<=m)return query(ll,rr,lson,l,m);
			else return (query(ll,rr,lson,l,m)+query(ll,rr,rson,m+1,r))%P;
		}
	}
} T;

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&P);
	T.build(++T.tot,1,n);
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		int op;
		scanf("%d",&op);
		if(op==1){
			int t,g,c;
			scanf("%d%d%d",&t,&g,&c);
			T.cheng(t,g,c,1,1,n);
		}else if(op==2){
			int t,g,c;
			scanf("%d%d%d",&t,&g,&c);
			T.jia(t,g,c,1,1,n);
		}else{
			int t,g;
			scanf("%d%d",&t,&g);
			printf("%d\n",T.query(t,g,1,1,n));
		}
	}
	return 0;
}
