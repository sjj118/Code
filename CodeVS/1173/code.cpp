#include<iostream>
#include<cstdio>
#include<algorithm>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
const int maxn=1e5+10,maxm=1e6+10;
int n,m,a[maxn];
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],reachable[maxn],d[maxn],cnt;
	pii city[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void reach(int k){
		reachable[k]=1;
		for(int p=head[k];p;p=next[p])if(!reachable[to[p]])reach(to[p]);
	}
	void dfsup(int k,int v){
		up(d[k],v);
		for(int p=head[k];p;p=next[p])if(d[to[p]]<v)dfsup(to[p],v);
	}
	void dfsdn(int k,int v){
		dn(d[k],v);
		for(int p=head[k];p;p=next[p])if(d[to[p]]>v)dfsdn(to[p],v);
	}
}G,F;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		G.ins(x,y);F.ins(y,x);
		if(z-1)G.ins(y,x),F.ins(x,y);
	}
	rep(i,1,n)G.d[i]=a[i],F.d[i]=a[i];
	G.reach(1);F.reach(n);
	rep(i,1,n)if(G.reachable[i])G.city[++G.cnt]=mp(a[i],i);
	rep(i,1,n)if(F.reachable[i])F.city[++F.cnt]=mp(a[i],i);
	sort(G.city+1,G.city+1+G.cnt);sort(F.city+1,F.city+1+F.cnt);
	rep(i,1,G.cnt)G.dfsdn(G.city[i].se,G.city[i].fi);
	per(i,F.cnt,1)F.dfsup(F.city[i].se,F.city[i].fi);
	int ans=0;
	rep(i,1,n)if(G.reachable[i]&&F.reachable[i])up(ans,F.d[i]-G.d[i]);
	printf("%d",ans);
	return 0;
}
