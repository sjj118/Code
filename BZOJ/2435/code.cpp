#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxn 2000005
#define ll long long

using namespace std;

ll ans,n;
struct Graph{
	int head[maxn],next[maxn*2],to[maxn*2],size[maxn],tot;
	ll len[maxn];
	void addedge(int a,int b,int l){
		to[++tot]=b;
		next[tot]=head[a];
		len[tot]=l;
		head[a]=tot;
	}
	bool vis[maxn];
	void dfs(int k){
		vis[k]=1;
		size[k]=1;
		for(int p=head[k];p;p=next[p])if(!vis[to[p]]){
			dfs(to[p]);
			size[k]+=size[to[p]];
			ans+=len[p]*abs(2*size[to[p]]-n);
		}
	}
} G;

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		G.addedge(a,b,c);
		G.addedge(b,a,c);
	}
	G.dfs(1);
	printf("%lld\n",ans);
	return 0;
} 
