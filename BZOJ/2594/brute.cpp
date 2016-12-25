#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,M=1e6+10;
int n,m,q;
struct Edge{
	int u,v,t,bad;
	Edge(){}
	Edge(int u,int v,int t):u(u),v(v),t(t){bad=0;}
}e[M];
bool operator<(const Edge&a,const Edge&b){return a.t<b.t;}
map<int,int> eid[N];
struct UFS{
	int pa[N],rank[N];
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	void unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
	}
}S;
int MST(int a,int b){
	S.clear();
	if(a==b)return 0;
	rep(i,1,m)if(!e[i].bad){
		S.unio(e[i].u,e[i].v);
		if(S.find(a)==S.find(b))return e[i].t;
	}
	return -1;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,m){
		int u,v,t;scanf("%d%d%d",&u,&v,&t);
		if(u>v)swap(u,v);
		e[i]=Edge(u,v,t);
	}
	sort(e+1,e+1+m);
	rep(i,1,m)eid[e[i].u][e[i].v]=i;
	while(q--){
		int k,x,y;scanf("%d%d%d",&k,&x,&y);
		if(k==1){
			printf("%d\n",MST(x,y));
		}else{
			if(x>y)swap(x,y);
			e[eid[x][y]].bad=1;
		}
	}
	return 0;
}
