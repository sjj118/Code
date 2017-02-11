#include<iostream>
#include<cstdio>
#include<cstring>
#include<assert.h>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::min;
const int N=200+10,M=N*N,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m;
struct Edge{
	int u,v;
}e[M];
namespace subtask1{
	struct Graph{
		int tot,head[N],to[M],next[M],c[M],dis[N],cur[N];
		int s,t;
		void ins(int a,int b,int f){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;}
		void addedge2(int a,int b,int f){ins(a,b,f);ins(b,a,f);}
		void clear(){tot=1;cls(head);}
		int q[N],ql,qr;
		bool bfs(){
			rep(i,1,n)dis[i]=0,cur[i]=head[i];
			ql=qr=0;
			q[qr++]=t;
			while(ql!=qr)for(int k=q[ql++],p=head[k];p;p=next[p])
				if(c[p^1]&&to[p]!=t&&!dis[to[p]])dis[q[qr++]=to[p]]=dis[k]+1;
			return dis[s];
		}
		int dfs(int k,int mf){
			if(k==t)return mf;
			int flow=0,tf;
			for(int&p=cur[k];p&&mf;p=next[p])
				if(c[p]&&dis[to[p]]+1==dis[k]&&(tf=dfs(to[p],min(mf,c[p]))))
					c[p]-=tf,c[p^1]+=tf,mf-=tf,flow+=tf;
			return flow;
		}
		int Dinic(int start,int end){
			s=start;t=end;
			int flow=0;
			while(bfs())flow+=dfs(s,inf);
			return flow;
		}
	}G;
	int solve(){
		G.clear();
		rep(i,1,m)G.addedge2(e[i].u,e[i].v,1);
		return m-G.Dinic(1,2);
	}
}
namespace subtask2{
	struct dp{
		bool val[N][2*N*N];
		bool&operator()(int x,int y){return val[x][y+N*N];}
		void clear(){cls(val);}
	}f;
	int deg[N];
	int solve(){
		f.clear();
		cls(deg);
		rep(i,1,m)++deg[e[i].u],++deg[e[i].v];
		f(2,deg[1]-deg[2])=1;
		int low=deg[1]-deg[2],high=deg[1]-deg[2];
		rep(i,3,n){
			rep(j,low,high)if(f(i-1,j))f(i,j+deg[i])=f(i,j-deg[i])=1,dn(low,j-deg[i]),up(high,j+deg[i]);
		}
		rep(i,0,n*n)if(f(n,i)||f(n,-i))return i/2;
		assert(0);
		return -1;
	}
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,m)scanf("%d%d",&e[i].u,&e[i].v);
		printf("%d %d\n",subtask1::solve(),subtask2::solve());
	}
	return 0;
}
