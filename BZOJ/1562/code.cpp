#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e4+10;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,incir[maxn],T[maxn];
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],dfn[maxn],lowlink[maxn],clock;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int dfs1(int k,int pre){
		int ans=-2;lowlink[k]=dfn[k]=++clock;
		for(int p=head[k];p;p=next[p]){
			++ans;
			if((p-1)/2!=pre){
				if(!dfn[to[p]])ans+=dfs1(to[p],(p-1)/2),dn(lowlink[k],lowlink[to[p]]);
				else dn(lowlink[k],dfn[to[p]]);
				if(lowlink[to[p]]<=dfn[k])incir[(p-1)/2]=1;
			}
		}
		return ans;
	}
	void dfs2(int k,int pre){
		for(int p=head[k];p;p=next[p])if((p-1)/2!=pre&&T[(p-1)/2]==-1){
			T[(p-1)/2]=to[p];
			dfs2(to[p],(p-1)/2);
		}
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,0,n-1){
		int d;scanf("%d",&d);
		G.addedge((i+d)%n,(n+i-d)%n);
	}
	rep(i,0,n-1)if(!G.dfn[i])if(G.dfs1(i,-1)){printf("No Answer");return 0;}
	rep(i,0,n-1)T[i]=-1;
	rep(i,0,n-1)if(T[i]==-1&&incir[i]){
		int u=G.to[i*2+1],v=G.to[i*2+2];
		if(v<u)swap(u,v);
		T[i]=u;
		G.dfs2(u,i);
	}
	printf("%d",T[0]);rep(i,1,n-1)printf(" %d",T[i]);
	return 0;
}
