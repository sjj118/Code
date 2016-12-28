#include<iostream>
#include<cstdio>
#include<assert.h>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=500+10,M=20000+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m;
struct Graph{
	int tot,head[N],to[M],next[M],len[M],tail[N];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;if(!tail[a])tail[a]=tot;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	void merge(int a,int b){
		if(tail[a])next[tail[a]]=head[b];
		else head[a]=head[b];
		tail[a]=tail[b];
	}
	int find(int);
}G;
struct UFS{
	int pa[N],rank[N];
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	int unio(int a,int b){
		a=find(a);b=find(b);
		assert(a!=b);
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
		G.merge(b,a);
		return b;
	}
}S;
int Graph::find(int ps){
	int d[N],v[N];
	cls(d);cls(v);
	int g=S.find(1);
	for(int p=head[g];p;p=next[p])if(S.find(to[p])!=g)d[S.find(to[p])]+=len[p];
	v[g]=1;
	rep(i,1,ps){
		int k=0;
		rep(j,1,n)if(!v[j]&&S.find(j)==j&&(k==0||d[j]>d[k]))k=j;
		v[k]=1;
		for(int p=head[k];p;p=next[p])if(!v[S.find(to[p])])d[S.find(to[p])]+=len[p];
		if(i==ps)return S.unio(k,g),d[k];
		g=k;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int a,b,c;scanf("%d%d%d",&a,&b,&c);G.addedge(a,b,c);}
	int ans=inf;
	S.clear();
	rep(i,1,n-1){
		dn(ans,G.find(n-i));
	}
	printf("%d",ans);
	return 0;
}
