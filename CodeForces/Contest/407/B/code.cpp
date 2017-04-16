#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const int N=1e6+10;
int n,m;
LL deg[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	bool vis[N];
	int dfs(int k){
		int ret=0;
		vis[k]=1;
		for(int p=head[k];p;p=next[p]){
			++ret;
			if(!vis[to[p]])ret+=dfs(to[p]);
		}
		return ret;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	int cir=0;
	rep(i,1,m){
		int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);
		if(u==v)++cir;
		else ++deg[u],++deg[v];
	}
	if(G.dfs(G.to[1])<m*2)return puts("0"),0;
	LL ans=0;
	rep(i,1,n)ans+=(LL)deg[i]*(deg[i]-1)/2;
	ans+=(LL)cir*(cir-1)/2;
	ans+=(LL)cir*(m-cir);
	std::cout<<ans;
	return 0;
}
