#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=3e5+10,L=1e4+10,P=1e7;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,m,lim,root[N];
#define ls son[k][0]
#define rs son[k][1]
struct SGT{
	int tot,son[P][2],val[P];
	void update(int k){
		val[k]=val[ls]+val[rs];
	}
	int modify(int p,int v,int k,int l,int r){
		int t=++tot;
		val[t]=val[k];
		if(l==r){val[t]+=v;return t;}
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=modify(p,v,ls,l,m),son[t][1]=rs;
		else son[t][0]=ls,son[t][1]=modify(p,v,rs,m+1,r);
		update(t);
		return t;
	}
	int query(int v,int k1,int k2,int l,int r){
		if(l==r)return val[k2]-val[k1]>v?l:-1;
		int m=(l+r)>>1;
		if(val[son[k2][0]]-val[son[k1][0]]>val[son[k2][1]]-val[son[k1][1]])
			return query(v,son[k1][0],son[k2][0],l,m);
		else return query(v,son[k1][1],son[k2][1],m+1,r);
	}
}T;
int main(){
	scanf("%d%d",&n,&lim);
	rep(i,1,n)root[i]=T.modify(read(),1,root[i-1],1,lim);
	int m;scanf("%d",&m);
	while(m--){
		int l,r;scanf("%d%d",&l,&r);
		int t=T.query((r-l+1)/2,root[l-1],root[r],1,lim);
		if(t==-1)puts("no");
		else printf("yes %d\n",t);
	}
	return 0;
}
