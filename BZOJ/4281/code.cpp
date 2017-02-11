#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e6+10;
int n,m,k;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int dep[N],pa[N][20];
	void dfs(int k,int pre){
		dep[k]=dep[pre]+1;
		pa[k][0]=pre;
		rep(i,1,19)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	int jump(int k,int d){
		for(int i=0;i<=19;++i,d>>=1)if(d&1)k=pa[k][i];
		return k;
	}
}G;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.dfs(1,0);
	while(k--){
		int d,t;scanf("%d%d",&d,&t);
		int f=G.lca(m,d);
		if(t<G.dep[m]-G.dep[f]){
			printf("%d ",m=G.jump(m,t));
		}else if(t<G.dep[m]+G.dep[d]-2*G.dep[f]){
			printf("%d ",m=G.jump(d,G.dep[m]+G.dep[d]-2*G.dep[f]-t));
		}else printf("%d ",m=d);
	}
	return 0;
}
