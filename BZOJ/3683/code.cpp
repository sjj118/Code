#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000+10,P=N*2,V=4*N*N;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
inline int readtime(){int a=read(),b=read();return a*60+b;}
inline void dn(int&x,int y){if(y<x)x=y;}
inline void outputime(int x){printf("%02d:%02d",x/60,x%60);}
int n,s[N],t[N],d[N],wed[N][2],ps=1,nps,nid[P];
struct Graph{
	int tot,head[P],to[V],next[V];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b^1,a^1);}
	int clo,dfn[P],lowlink[P],insta[P],sta[P],top;
	void dfs(int k){
		dfn[k]=lowlink[k]=++clo;
		insta[sta[++top]=k]=1;
		for(int p=head[k];p;p=next[p]){
			if(!dfn[to[p]])dfs(to[p]),dn(lowlink[k],lowlink[to[p]]);
			else if(insta[to[p]])dn(lowlink[k],dfn[to[p]]);
		}
		if(lowlink[k]==dfn[k]){
			nid[k]=++nps;
			while(sta[top]!=k){
				nid[sta[top]]=nps;
				insta[sta[top--]]=0;
			}insta[sta[top--]]=0;
		}
	}
	bool sat2(){
		rep(i,2,ps)if(!dfn[i])dfs(i);
		rep(i,2,ps)if(nid[i]==nid[i^1])return 0;
		return 1;
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		s[i]=readtime();
		t[i]=readtime();
		scanf("%d",&d[i]);
	}
	rep(i,1,n)wed[i][0]=++ps,wed[i][1]=++ps;
	rep(i,1,n)rep(j,i+1,n){
		if(s[i]+d[i]>s[j]&&s[j]+d[j]>s[i])G.addedge(wed[i][0],wed[j][1]);
		if(s[i]+d[i]>t[j]-d[j]&&t[j]>s[i])G.addedge(wed[i][0],wed[j][0]);
		if(t[i]>s[j]&&s[j]+d[j]>t[i]-d[i])G.addedge(wed[i][1],wed[j][1]);
		if(t[i]>t[j]-d[j]&&t[j]>t[i]-d[i])G.addedge(wed[i][1],wed[j][0]);
	}
	if(G.sat2()){
		puts("YES");
		rep(i,1,n)if(nid[wed[i][0]]<nid[wed[i][1]])outputime(s[i]),putchar(' '),outputime(s[i]+d[i]),puts("");
		else outputime(t[i]-d[i]),putchar(' '),outputime(t[i]),puts("");
	}else puts("NO");
	return 0;
}
