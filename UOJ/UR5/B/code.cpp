#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=3e5+10;
using namespace std;
inline int read(){int tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,m,p;
struct UFS{
	int pa[maxn],rank[maxn];
	void init(){rep(i,1,n)pa[i]=i;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	void unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return;
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
	}
}S;
struct LinkMap{
	int tot,head[maxn],next[maxn],a[maxn],b[maxn];
	void ins(int i,int _a,int _b){a[++tot]=_a;b[tot]=_b;next[tot]=head[a];head[a]=tot;}
}lp;
struct Linker{
	int head
}lr;
struct Day{
	int u,v,w,p;
}d[maxn];
bool operator<(Day a,Day b){return a.w<b.w;}
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],dep[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		dep[k]=dep[pre]+1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
	}
	void work(int a){
		int u=d[a].u,v=d[a].v;cnt=0;
		p[++cnt]=u=S.find(u);p[++cnt]=v=S.find(v);
		while(u!=v){
			if(dep[u]>dep[v])swap(u,v);
			p[++cnt]=v=S.find(pa[v]);
		}

	}
}G;
int main(){
	scanf("%d%d%d",&n,&m,&p);
	rep(i,2,n){int u=read();G.addedge(i,u);}
	S.init();
	rep(i,1,m)d[i].u=read(),d[i].v=read(),d[i].w=read(),d[i].p=i;
	rep(i,1,p){int t=read(),a=read(),b=read();lp.ins(t,a,b);}
	sort(d+1,d+1+m);
	G.dfs(1,0);
	rep(i,1,m){
		G.work(i);
	}
	return 0;
}
