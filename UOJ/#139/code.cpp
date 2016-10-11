#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n;
struct Graph{
	int tot,head[maxn],next[maxn<<1],to[maxn<<1],ds[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void getds(int k,int pre){
		ds[k]=inf;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)getds(to[p],k),dn(ds[k],ds[to[p]]+1);
		if(ds[k]==inf)ds[k]=1;
	}
	int dfs(int k,int l,int pre){
		int ans=0;
		if(ds[k]==l)--l,++ans;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)ans+=dfs(to[p],l,k);
		return ans;
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.getds(1,0);
	printf("%d",G.dfs(1,G.ds[1],0));
	return 0;
}
