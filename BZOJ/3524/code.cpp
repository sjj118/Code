#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=5e5+10,maxp=1e7;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,m;
struct SGT{
	int tot,son[maxp][2],val[maxp],root[maxp];
	int modify(int p,int v,int k,int l,int r){
		int t=++tot;
		if(l==r){val[t]=val[k]+v;return t;}
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=modify(p,v,son[k][0],l,m),son[t][1]=son[k][1];
		else son[t][0]=son[k][0],son[t][1]=modify(p,v,son[k][1],m+1,r);
		val[t]=val[son[t][0]]+val[son[t][1]];
		return t;
	}
	int query(int v,int k1,int k2,int l,int r){
		if(l==r)return l;
		int m=(l+r)>>1;
		if(val[son[k1][0]]-val[son[k2][0]]>=v)return query(v,son[k1][0],son[k2][0],l,m);
		if(val[son[k1][1]]-val[son[k2][1]]>=v)return query(v,son[k1][1],son[k2][1],m+1,r);
		return 0;
	}
}T;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)T.root[i]=T.modify(read(),1,T.root[i-1],1,n);
	while(m--){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",T.query(((r-l+1)>>1)+1,T.root[r],T.root[l-1],1,n));
	}
	return 0;
}
