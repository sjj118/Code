#include<iostream>
#include<cstdio>
#define maxn 1005

using namespace std;

int n;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],c[maxn<<1],dir[maxn];
	void addedge(int a,int b,int C){
		to[++tot]=b;c[tot]=C;next[tot]=head[a];head[a]=tot;
	}
	void dfs(int k,int pre=0){
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dir[to[p]]=dir[k]^c[p],dfs(to[p],k);
	}
} G;

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int s,d,c;
		scanf("%d%d%d",&s,&d,&c);
		G.addedge(s,d,c);G.addedge(d,s,c);
	}
	G.dfs(1);
	printf("%d",G.dir[n]);
	return 0;
} 
