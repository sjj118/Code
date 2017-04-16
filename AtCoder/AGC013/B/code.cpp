#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10,M=2e5+10;
int n,m,cnt,path[N];
struct Graph{
	int tot,head[N],to[M],next[M],vis[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k){
		path[++cnt]=k;
		vis[k]=1;
		for(int p=head[k];p;p=next[p])if(!vis[to[p]]){dfs(to[p]);break;}
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	G.vis[G.to[1]]=G.vis[G.to[2]]=1;
	G.dfs(G.to[1]);
	std::reverse(path+1,path+1+cnt);
	G.dfs(G.to[2]);
	printf("%d\n",cnt);
	rep(i,1,cnt)printf("%d ",path[i]);
	return 0;
}
