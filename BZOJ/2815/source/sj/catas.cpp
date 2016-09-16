#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=7e4,maxm=2e6;
int n;
struct Tree{
	int pa[maxn][16],tot,head[maxn],to[maxm],next[maxm],dep[maxn],size[maxn];
	void ins(int a,int b){
		dep[a]=dep[b]+1;pa[a][0]=b;
		to[++tot]=a;next[tot]=head[b];head[b]=tot;
		rep(i,1,15)pa[a][i]=pa[pa[a][i-1]][i-1];
	}
	int lca(int a,int b){
		if(dep[a]>dep[b])swap(a,b);
		per(i,15,0)if(dep[pa[b][i]]>=dep[a])b=pa[b][i];
		if(a==b)return a;
		per(i,15,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	void dfs(int k){
		size[k]=1;
		for(int p=head[k];p;p=next[p])dfs(to[p]),size[k]+=size[to[p]];
	}
}T;
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],indegree[maxn],pa[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;++indegree[b];}
	int q[maxn],ql,qr;
	void topsort(){
		ql=1;qr=0;T.dep[n+1]=1;
		rep(i,1,n)if(indegree[i]==0)q[++qr]=i,pa[i]=n+1;
		while(ql<=qr){
			int k=q[ql++];T.ins(k,pa[k]);
			for(int p=head[k];p;p=next[p]){
				--indegree[to[p]];
				if(pa[to[p]]==0)pa[to[p]]=k;else pa[to[p]]=T.lca(pa[to[p]],k);
				if(indegree[to[p]]==0)q[++qr]=to[p];
			}
		}
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int x;while(scanf("%d",&x)&&x)G.ins(x,i);
	}
	G.topsort();
	T.dfs(n+1);
	rep(i,1,n)printf("%d\n",T.size[i]-1);
	return 0;
}
