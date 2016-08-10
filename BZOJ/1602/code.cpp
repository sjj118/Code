#include<iostream>
#include<cstdio>
#define maxn 1005
#define maxv 3000

using namespace std;

int n,q;
int tot,head[maxn],to[maxv],next[maxv],len[maxv],dep[maxn],dis[maxn],pa[maxn][11];
void addedge(int a,int b,int c){
	to[++tot]=b;len[tot]=c;next[tot]=head[a];head[a]=tot;
}
void dfs(int k,int pre=0){
	for(int i=1;i<10;++i)pa[k][i]=pa[pa[k][i-1]][i-1];
	for(int p=head[k];p;p=next[p])if(to[p]!=pre){
		dep[to[p]]=dep[k]+1;
		dis[to[p]]=dis[k]+len[p];
		pa[to[p]][0]=k;
		dfs(to[p],k);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=9;i>=0;--i)if(pa[x][i]&&dep[pa[x][i]]>=dep[y])x=pa[x][i];
	if(x==y)return x;
	for(int i=9;i>=0;--i)if(pa[x][i]!=pa[y][i])x=pa[x][i],y=pa[y][i];
	return pa[x][0];
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;++i){
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		addedge(a,b,l);addedge(b,a,l);
	}
	dfs(1);
	for(int i=1;i<=q;++i){
		int p1,p2;
		scanf("%d%d",&p1,&p2);
		printf("%d\n",dis[p1]+dis[p2]-2*dis[lca(p1,p2)]);
	}
	return 0;
} 
