#include<iostream>
#include<cstdio>
#define maxn 500010
#define maxp 10000000
#define lson son[k][0]
#define rson son[k][1]

using namespace std;

int n,m;
struct CHT{
	int son[maxp][2],sum[maxp],tot,root[maxn];
	void pushup(int k){
		if(lson||rson)sum[k]=sum[lson]+sum[rson];
	}
	void clone(int old,int t){
		root[t]=++tot;
		son[tot][0]=son[old][0];son[tot][1]=son[old][1];
		pushup(tot);
	}
	void molify(int p,int&k,int l,int r){
		if(!k)k=++tot;
		if(l==r)++sum[k];
		else{
			int m=(l+r)>>1;
			if(p<=m)molify(p,lson,l,m);
			else molify(p,rson,m+1,r);
			pushup(k);
		}
	}
	int query(){
		
	}
}T;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		T.clone(i-1,i);
		int tmp;scanf("%d",&tmp);
		T.molify(tmp,T.root[i],1,n);
	}
	
	return 0;
}
