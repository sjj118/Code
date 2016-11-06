#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,K,ans=inf;
struct Graph{
	int tot,head[N],next[N<<1],to[N<<1],len[N<<1];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	void dfs(int k,int pre,int dis,int dep){
		if(dis==K)dn(ans,dep);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k,dis+len[p],dep+1);
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d%d",&n,&K);
	rep(i,1,n-1){int a,b,c;scanf("%d%d%d",&a,&b,&c);G.addedge(a,b,c);}
	rep(i,1,n)G.dfs(i,0,0,0);
	if(ans==inf)puts("-1");else printf("%d",ans);
	return 0;
}
