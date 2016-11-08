#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=2e4+10,M=2e5+10,inf=1e9,P=N,V=M<<1;
int n,m,u,v,l,ans;
struct Edge{
	int u,v,w;
}e[M];
bool operator<(const Edge&a,const Edge&b){return a.w<b.w;}
struct Graph{
	int tot,head[P],next[V],to[V],c[V],dis[P],cur[P];
	int s,t;
	void ins(int a,int b,int f){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;}
	void addedge(int a,int b,int f,int _f){ins(a,b,f);ins(b,a,_f);}
	int q[P],ql,qr;
	bool bfs(){
		rep(i,1,n)dis[i]=0,cur[i]=head[i];
		ql=qr=0;q[qr++]=t;
		while(ql!=qr)
			for(int k=q[ql++],p=head[k];p;p=next[p])
			if(c[p^1]&&!dis[to[p]]&&to[p]!=t)dis[q[qr++]=to[p]]=dis[k]+1;
		return dis[s];
	}
	int dfs(int k,int mf){
		if(k==t)return mf;
		int flow=0,tf;
		for(int p=head[k];p&&mf;p=next[p])
			if(c[p]&&dis[to[p]]+1==dis[k]&&(tf=dfs(to[p],min(c[p],mf))))
			c[p]-=tf,c[p^1]+=tf,mf-=tf,flow+=tf;
		return flow;
	}
	int Dinic(int start,int end){
		s=start;t=end;
		int flow=0;
		while(bfs())flow+=dfs(s,inf);
		return flow;
	}
	void clear(){tot=1;cls(head);}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	scanf("%d%d%d",&u,&v,&l);
	G.clear();
	rep(i,1,m)if(e[i].w<l)G.addedge(e[i].u,e[i].v,1,1);
	ans+=G.Dinic(u,v);
	G.clear();
	rep(i,1,m)if(e[i].w>l)G.addedge(e[i].u,e[i].v,1,1);
	ans+=G.Dinic(u,v);
	printf("%d",ans);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
