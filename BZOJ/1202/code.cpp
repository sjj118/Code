#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=100+10,M=1000+10;
int n,m;
struct UFS{
	int pa[N],rank[N],mark[N];
	void clear(){rep(i,0,n)pa[i]=i,rank[i]=0,mark[i]=0;}
	int find(int k,int&v){
		if(k==pa[k])return k;
		pa[k]=find(pa[k],mark[k]);
		v+=mark[k];
		return pa[k];
	}
	bool unio(int a,int b,int va,int vb){
		a=find(a,va);b=find(b,vb);
		if(a==b&&va!=vb)return 0;
		if(rank[a]>rank[b])swap(a,b),swap(va,vb);
		pa[a]=b;mark[a]=vb-va;
		if(rank[a]==rank[b])++rank[b];
		return 1;
	}
}S;
int main(){
	int cas;scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&n,&m);
		S.clear();
		bool flag=1;
		rep(i,1,m){
			int s,t,v;scanf("%d%d%d",&s,&t,&v);
			if(!S.unio(s-1,t,v,0))flag=0;
		}
		if(flag)puts("true");else puts("false");
	}
	return 0;
}
