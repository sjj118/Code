#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=100+10,M=2000+10;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,song[N][2],ps,nid[N<<1],nps;
struct Graph{
	int tot,head[N<<1],to[M],next[M],dfn[N<<1],lowlink[N<<1],clo,insta[N<<1],sta[N<<1],top;
	void clear(){tot=0;cls(head);}
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void dfs(int k,int pre){
		dfn[k]=lowlink[k]=++clo;insta[k]=1;sta[++top]=k;
		for(int p=head[k];p;p=next[p]){
			if(!dfn[to[p]])dfs(to[p],k),dn(lowlink[k],lowlink[to[p]]);
			else if(insta[to[p]])dn(lowlink[k],dfn[to[p]]);
		}
		if(lowlink[k]==dfn[k]){
			++nps;
			while(sta[top]!=k){
				insta[sta[top]]=0;
				nid[sta[top--]]=nps;
			}nid[sta[top--]]=nps;
			insta[k]=0;
		}
	}
	bool check(){
		cls(dfn);
		rep(i,2,ps)if(!dfn[i])dfs(i,0);
		rep(i,1,n)if(nid[song[i][0]]==nid[song[i][1]])return 0;
		return 1;
	}
}G;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		ps=1;nps=0;
		G.clear();
		rep(i,1,n)song[i][0]=++ps,song[i][1]=++ps;
		rep(i,1,m){
			char c;
			int a,t;
			scanf("\n%c%d",&c,&a);
			if(c=='m')t=0;else t=1;
			int p1=song[a][t];
			scanf(" %c%d",&c,&a);
			if(c=='m')t=0;else t=1;
			int p2=song[a][t];
			G.ins(p1^1,p2);G.ins(p2^1,p1);
		}
		if(G.check())puts("GOOD");else puts("BAD");
	}
	return 0;
}
