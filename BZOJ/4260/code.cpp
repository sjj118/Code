#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=4e5+10,P=2e7;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,a[N],s[N],al[N],ar[N],rt;
struct Trie{
	int tot,son[P][2];
	void clear(){rep(i,1,tot)son[i][0]=son[i][1]=0;tot=0;}
	void ins(int v,int&k,int d){
		if(!k)k=++tot;
		if(d==-1)return;
		ins(v,son[k][v>>d&1],d-1);
	}
	int query(int v,int k,int d){
		if(k==0)return 0;
		if(d==-1)return 0;
		int t=v>>d&1;
		if(son[k][!t])return query(v,son[k][!t],d-1)+(1<<d);
		return query(v,son[k][t],d-1);
	}
}T;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)s[i]=s[i-1]^a[i];
	rep(i,0,n){
		al[i]=T.query(s[i],rt,30);
		T.ins(s[i],rt,30);
	}
	T.clear();
	per(i,n,1)s[i]=s[i+1]^a[i];
	rt=0;
	per(i,n+1,1){
		ar[i]=T.query(s[i],rt,30);
		T.ins(s[i],rt,30);
	}
	rep(i,1,n)up(al[i],al[i-1]);
	per(i,n,1)up(ar[i],ar[i+1]);
	int ans=0;
	rep(i,1,n-1)up(ans,al[i]+ar[i+1]);
	printf("%d",ans);
	return 0;
}
