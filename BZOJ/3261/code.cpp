#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=6e5+10,maxp=3e7;
int root[maxn],n,m,xn;
struct Trie{
	int tot,son[maxp][2],val[maxp];
	int modify(int v,int&k,int d){
		int t=++tot;val[t]=val[k]+1;
		if(d==-1)return t;
		if((v>>d)&1)son[t][0]=son[k][0],son[t][1]=modify(v,son[k][1],d-1);
		else son[t][0]=modify(v,son[k][0],d-1),son[t][1]=son[k][1];
		return t;
	}
	int query(int v,int&l,int&r,int d){
		if(d==-1)return 0;
		int t=!((v>>d)&1);
		if(val[son[r][t]]-val[son[l][t]])return query(v,son[l][t],son[r][t],d-1)+(1<<d);
		else return query(v,son[l][!t],son[r][!t],d-1);
	}
}T;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;scanf("%d",&x);root[i]=T.modify(xn,root[i-1],30);xn^=x;}
	rep(i,1,m){
		char op;scanf("\n%c",&op);
		if(op=='A'){
			int x;scanf("%d",&x);
			++n;root[n]=T.modify(xn,root[n-1],30);xn^=x;
		}else{
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",T.query(x^xn,root[l-1],root[r],30));
		}
	}
	return 0;
}
