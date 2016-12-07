#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=100+10,M=1000+10,P=2*N,V=2*M;
inline bool vaild(char c){return c>='0'&&c<='9'||c=='m'||c=='h';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,ps,nps,nid[P];
struct Graph{
	int tot,head[P],next[V],to[V];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	int dfn[P],lowlink[P],clo,insta[P],sta[P],top;
	void dfs(int k){
		dfn[k]=lowlink[k]=++clo;
		insta[sta[++top]=k]=1;
		for(int p=head[k];p;p=next[p]){
			if(!dfn[to[p]])dfs(to[p]),dn(lowlink[k],lowlink[to[p]]);
			else if(insta[to[p]])dn(lowlink[k],dfn[to[p]]);
		}
		if(dfn[k]==lowlink[k]){
			nid[k]=++nps;
			while(sta[top]!=k){
				nid[sta[top]]=nps;
				insta[sta[top--]]=0;
			}insta[sta[top--]]=0;
		}
	}
	bool sat2(){
		cls(dfn);cls(lowlink);clo=0;
		rep(i,2,ps)if(!dfn[i])dfs(i);
		rep(i,2,ps)if(nid[i]==nid[i^1])return 0;
		return 1;
	}
	void clear(){tot=0;cls(head);}
}G;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		G.clear();ps=2*n+1;nps=0;
		rep(i,1,m){
			int a,b,t=gc()=='m'?0:1;
			scanf("%d",&a);
			a=a*2+t;
			t=gc()=='m'?0:1;
			scanf("%d",&b);
			b=b*2+t;
			G.ins(a^1,b);G.ins(b^1,a);
		}
		if(G.sat2())puts("GOOD");else puts("BAD");
	}
	return 0;
}
