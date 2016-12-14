#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=10000+10,M=1e6,inf=1e9;
int n,m;
struct Graph{
	int tot,head[N],to[M],next[M],c[M],dis[N],cur[N];
	int s,t;
	void ins(int a,int b,int f){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;}
	void addedge(int a,int b,int f){ins(a,b,f);ins(b,a,0);}
	int q[N],ql,qr;
	Graph(){tot=1;}
	bool bfs(){
		rep(i,1,n*2)dis[i]=0,cur[i]=head[i];
		ql=qr=0;q[qr++]=t;
		while(ql!=qr)for(int k=q[ql++],p=head[k];p;p=next[p])
			if(c[p^1]&&to[p]!=t&&!dis[to[p]])dis[q[qr++]=to[p]]=dis[k]+1;
		return dis[s];
	}
	int dfs(int k,int mf){
		if(k==t)return mf;
		int flow=0,tf;
		for(int&p=cur[k];p&&mf;p=next[p])
			if(c[p]&&dis[to[p]]+1==dis[k]&&(tf=dfs(to[p],min(c[p],mf))))
				c[p]-=tf,c[p^1]+=tf,flow+=tf,mf-=tf;
		return flow;
	}
	int Dinic(int start,int end){
		s=start;t=end;
		int flow=0;
		while(bfs())flow+=dfs(s,inf);
		return flow;
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n)G.addedge(i*2-1,i*2,1);
	rep(i,1,n-1){
		int k;scanf("%d",&k);
		while(k--){int x;scanf("%d",&x);G.addedge(i*2,x*2-1,1);}
	}
	printf("%d\n",G.Dinic(2,n*2-1));
	return 0;
}
