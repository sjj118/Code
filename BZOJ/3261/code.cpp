#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=6e5+10,maxp=1e7;
int root[maxn],n,m;
struct Trie{
	int tot,son[maxp][2];
	int ins(int v,int&k,int l,int r){
		int t=++tot;
		if(l==r)return t;
		int m=(l+r)>>1;
		if(v<=m)son[t][0]=ins(v,son[k][0],l,m),son[t][1]=son[k][1];
		else son[t][0]=son[k][0],son[t][1]=ins(v,son[k][1],m+1,r);
		return t;
	}
}T;
int main(){
	scanf("%d%d",&n,&m);
	return 0;
}
