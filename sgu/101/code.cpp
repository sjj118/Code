#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=7,maxm=200+10;
int n,top,path[maxm],vis[maxm];
struct Graph{
	int tot,head[maxn],next[maxm],to[maxm],du[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);++du[a];++du[b];}
	Graph(){tot=1;}
	void dfs(int k){
		for(int&p=head[k];p;p=next[p])if(!vis[p]){
			vis[p]=vis[p^1]=1;int tmp=p;
			dfs(to[p]);
			path[top--]=tmp;
		}
	}
}G;
int main(){
	scanf("%d",&n);top=n;
	rep(i,1,n){
		int u,v;scanf("%d%d",&u,&v);
		G.addedge(u,v);
	}
	int s=G.to[2];int cnt=0;
	rep(i,0,6)if(G.du[i]&1)++cnt,s=i;
	if(cnt>2){printf("No solution");return 0;}
	G.dfs(s);
	if(top){printf("No solution");return 0;}
	rep(i,1,n)printf("%d %c\n",path[i]/2,(path[i]&1)?'-':'+');
	return 0;
}
