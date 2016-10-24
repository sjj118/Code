#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=300+10,P=N+10,V=N*N+2*N+10,inf=1e9;
int n,m;
struct Graph{
	int tot,head[P],to[V],next[V],c[V],dis[P],cur[P];
	int ps,s,t;
	void getp(int&x){if(!x)x=++ps;}
	void ins(int a,int b,int f){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;}
	void addedge(int&a,int&b,int f1,int f2=0){getp(a);getp(b);ins(a,b,f1);ins(b,a,f2);}
	Graph(){tot=1;}
	int q[P],ql,qr;
	bool bfs(){
		rep(i,1,ps)dis[i]=0,cur[i]=head[i];
		ql=qr=0;q[qr++]=t;
		while(ql!=qr)for(int k=q[ql++],p=head[k];p;p=next[p])
			if(c[p^1]&&!dis[to[p]]&&to[p]!=t)dis[q[qr++]=to[p]]=dis[k]+1;
		return dis[s];
	}
	int dfs(int k,int mf){
		if(k==t)return mf;
		int flow=0,tf;
		for(int&p=cur[k];p&&mf;p=next[p])if(c[p]&&dis[to[p]]+1==dis[k]&&(tf=dfs(to[p],min(c[p],mf))))
			c[p]-=tf,c[p^1]+=tf,mf-=tf,flow+=tf;
		return flow;
	}
	int dinic(int start,int end){
		s=start;t=end;
		int flow=0;
		while(bfs())flow+=dfs(s,inf);
		return flow;
	}
}G;
int start,end,stu[N];
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;scanf("%d",&x);if(x)G.addedge(start,stu[i],1);else G.addedge(stu[i],end,1);}
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		G.addedge(stu[x],stu[y],1,1);
	}
	printf("%d",G.dinic(start,end));
	return 0;
}
