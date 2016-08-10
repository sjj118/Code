#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 40005

using namespace std;

int t,n;

struct Graph{
	int head[maxn],to[maxn],next[maxn],size[maxn],heavest[maxn],tot;
	void addedge(int a,int b){
		to[++tot]=b;
		next[tot]=head[a];
		head[a]=tot;
	}
	void clear(){
		tot=0;
		memset(head,0,sizeof(head));
		memset(to,0,sizeof(to));
		memset(next,0,sizeof(next));
		memset(vis,0,sizeof(vis));
		memset(heavest,0,sizeof(heavest));
	}
	bool vis[maxn];
	void dfs(int k){
		size[k]=1;
		vis[k]=1;
		for(int p=head[k];p;p=next[p])if(!vis[to[p]]){
			dfs(to[p]);
			size[k]+=size[to[p]];
			heavest[k]=max(heavest[k],size[to[p]]);
		}
		heavest[k]=max(heavest[k],n-size[k]);
	}
} G;

int main(){
	scanf("%d",&t);
	for(int test=0;test<t;++test){
		G.clear();
		scanf("%d",&n);
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			G.addedge(a,b);
			G.addedge(b,a);
		}
		G.dfs(1);
		int ans=1;
		for(int i=1;i<=n;++i)if(G.heavest[i]*2<=n){
			ans=i;
			break;
		}
		printf("%d %d\n",ans,G.heavest[ans]);
	}
	return 0;
} 
