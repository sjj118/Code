#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10;
int n,m;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],len[maxn<<1],dep[maxn];
	bool vis[maxn];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	double dfs2(int k,int pre,int wall){
		double ans=0;int degree=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&to[p]!=wall)++degree;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&to[p]!=wall)ans+=1.0/degree*(dfs2(to[p],k,wall)+len[p]);
		return ans;
	}
	double dfs(int k,int pre){
		vis[k]=1;double ans=0;dep[k]=dep[pre]+1;int degree=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&(!vis[to[p]]||dep[to[p]]>dep[k]))++degree;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&(!vis[to[p]]||dep[to[p]]>dep[k])){
			if(vis[to[p]])ans+=1.0/degree*(dfs2(to[p],k,k)+len[p]);
			else ans+=1.0/degree*(dfs(to[p],k)+len[p]);
		}
		return ans;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y,w;scanf("%d%d%d",&x,&y,&w);G.addedge(x,y,w);}
	printf("%.5lf",G.dfs(1,0));
	return 0;
}
