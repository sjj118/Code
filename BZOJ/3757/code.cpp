#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define maxn 50010
using namespace std;

int readint(){
	int tmp=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}
int n,m,col[maxn],B,u,v,sum,num[maxn],ans[maxn];
struct Query{
	int u,v,a,b,pos,ans;
}q[maxn];
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],dep[maxn],pa[maxn][20];
	void addedge(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void dfs(int k,int pre=0){
		for(int i=1;i<20;++i)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			pa[to[p]][0]=k;
			dep[to[p]]=dep[k]+1;
			dfs(to[p],k);
		}
	}
	int LCA(int a,int b){
		if(dep[a]>dep[b])swap(a,b);
		for(int i=19;i>=0;--i)if(dep[pa[b][i]]>=dep[a])b=pa[b][i];
		if(a==b)return a;
		for(int i=19;i>=0;--i)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
}G;
bool comp(Query a,Query b){
	
}

int main(){
	n=readint();m=readint();
	B=floor(sqrt(n));
	for(int i=1;i<=n;++i)col[i]=readint();
	for(int i=1;i<=n;++i){
		int x=readint(),y=readint();
		G.addedge(x,y);G.addedge(y,x);
	}
	G.dfs(0);
	for(int i=0;i<m;++i){
		q[i].u=readint(),q[i].v=readint(),q[i].a=readint(),q[i].b=readint(),q[i].pos=i;
	}
	sort(q,q+m,comp);
	u=1;v=0;
	for(int i=0;i<m;++i){
//		transform(u,q[i].u);
	}
	for(int i=0;i<m;++i)ans[q[i].pos]=q[i].ans;
	for(int i=0;i<m;++i)printf("%d\n",ans[i]);
	return 0;
}
