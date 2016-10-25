#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;

namespace sjj118{
const int N=50+5,inf=1e9,P=N,M=6*N;
int n,m,s;
struct Graph{
	int tot,head[P],next[M],to[M],c[M],w[M],dis[P],dclock,vis[P];
	int ps,s,t,cost;
	void getp(int&x){if(!x)x=++ps;}
	void ins(int a,int b,int f,int p){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;w[tot]=p;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	int q[P],inq[P],ql,qr;
	bool spfa(){
		rep(i,1,ps)dis[i]=inf;dis[t]=0;++dclock;
		ql=qr=0;inq[q[qr++]=t]=1;
		while(ql!=qr){
			int k=q[ql++];if(ql==P)ql=0;inq[k]=0;
			for(int p=head[k];p;p=next[p])if(c[p^1]&&dis[to[p]]>dis[k]+w[p^1]){
				dis[to[p]]=dis[k]+w[p^1];
				if(!inq[to[p]]){
					if(dis[to[p]]<dis[q[ql]]){
						if(ql==0)ql=P;
						q[--ql]=to[p];
					}else{
						q[qr++]=to[p];
						if(qr==P)qr=0;
					}
					inq[to[p]]=1;
				}
			}
		}
		return dis[s]<inf;
	}
	Graph(){tot=1;}
	int dfs(int k,int mf){
		if(k==t)return cost+=dis[s]*mf,mf;
		vis[k]=dclock;
		int flow=0,tf;
		for(int p=head[k];p&&mf;p=next[p])
			if(c[p]&&dis[to[p]]+w[p]==dis[k]&&vis[to[p]]!=dclock&&(tf=dfs(to[p],min(c[p],mf))))
			c[p]-=tf,c[p^1]+=tf,mf-=tf,flow+=tf;
		return flow;
	}
	int zkwflow(int start,int end,int&c){
		s=start;t=end;
		int flow=0,tf;
		while(spfa())while(tf=dfs(s,inf))++dclock,flow+=tf;
		return c=cost,flow;
	}
}G;
int mon[N],start,end;
int main(){
	scanf("%d%d%d",&n,&m,&s);
	rep(i,1,n-1)G.addedge(mon[i],mon[i+1],s,m);
	rep(i,1,n){int x;scanf("%d",&x);G.addedge(mon[i],end,x,0);}
	rep(i,1,n){int x;scanf("%d",&x);G.addedge(start,mon[i],inf,x);}
	int ans;
	G.zkwflow(start,end,ans);
	printf("%d",ans);
	return 0;
}

}
int main(){
//	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
