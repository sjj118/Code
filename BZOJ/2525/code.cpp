#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=3e5+10;
int n,m,d[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],dep[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		dep[k]=dep[pre]+1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&d[i]);
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.dfs(1,0);
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1;

	}
	return 0;
}
