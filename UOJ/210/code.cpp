#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,P=8*N,V=14*N;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,ps=1,word[N][2],man[N][2],pref[N][2],suff[N][2];
struct Word{
	int x,y,t;
}w[N];
bool cmp(const Word&a,const Word&b){return a.x<b.x;}
struct Graph{
	int tot,head[P],to[V],next[V],mark[P],nid[P],nps;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b^1,a^1);}
	int insta[P],sta[P],top,dfn[P],clo,lowlink[P];
	void dfs(int k){
		dfn[k]=lowlink[k]=++clo;
		insta[sta[++top]=k]=1;
		for(int p=head[k];p;p=next[p]){
			if(!dfn[to[p]]){
				dfs(to[p]);dn(lowlink[k],lowlink[to[p]]);
			}else if(insta[to[p]])dn(lowlink[k],dfn[to[p]]);
		}
		if(lowlink[k]==dfn[k]){
			nid[k]=++nps;
			while(sta[top]!=k){
				nid[sta[top]]=nps;
				insta[sta[top--]]=0;
			}
			insta[sta[top--]]=0;
		}
	}
	int deg[P],q[P],ql,qr;
	bool sat2(){
		rep(i,2,ps)if(!dfn[i])dfs(i);
		rep(i,2,ps)if(nid[i]==nid[i^1])return 0;
		return 1;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)word[i][0]=++ps,word[i][1]=++ps;
	rep(i,1,n)man[i][0]=++ps,man[i][1]=++ps;
	rep(i,1,m)pref[i][0]=++ps,pref[i][1]=++ps;
	rep(i,1,m)suff[i][0]=++ps,suff[i][1]=++ps;
	rep(i,1,m)scanf("%d%d%d",&w[i].x,&w[i].y,&w[i].t);
	sort(w+1,w+1+m,cmp);
	rep(i,1,m)G.addedge(word[i][1],man[w[i].y][w[i].t]);
	rep(i,1,m){
		G.addedge(pref[i][1],word[i][1]);
		G.addedge(suff[i][1],word[i][1]);
		if(w[i-1].x==w[i].x){
			G.addedge(pref[i][1],pref[i-1][1]);
			G.addedge(word[i][0],pref[i-1][1]);
		}else G.addedge(man[w[i].x][1],suff[i][1]);
		if(w[i+1].x==w[i].x){
			G.addedge(suff[i][1],suff[i+1][1]);
			G.addedge(word[i][0],suff[i+1][1]);
		}
	}
	if(!G.sat2()){puts("Impossible");return 0;}
	int ans=0;
	rep(i,1,n)if(G.nid[man[i][1]]>G.nid[man[i][0]])++ans;
	printf("%d\n",ans);
	rep(i,1,n)if(G.nid[man[i][1]]>G.nid[man[i][0]])printf("%d ",i);
	return 0;
}
