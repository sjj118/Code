#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=2000+10,P=N<<1,M=10000+10,V=(M+P)<<1,inf=1e9+7;
int nl,nr,m,boy[N],girl[N],start,end,wife[N];
struct Graph{
	int tot,head[P],next[V],to[V],c[V],w[V],dis[P],vis[P],clock;
	int s,t,ps;
	LL cost;
	Graph(){tot=1;}
	void getp(int&x){if(!x)x=++ps;}
	void ins(int a,int b,int f,int p){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;w[tot]=p;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	int q[P],ql,qr,inq[P];
	bool spfa(){
		rep(i,1,ps)dis[i]=inf;dis[t]=0;++clock;
		inq[t]=1;ql=qr=0;q[qr++]=t;
		while(ql!=qr){
			int k=q[ql++];if(ql==P)ql=0;inq[k]=0;
			for(int p=head[k];p;p=next[p])if(c[p^1]&&dis[to[p]]>dis[k]+w[p^1]){
				dis[to[p]]=dis[k]+w[p^1];
				if(inq[to[p]])continue;
				inq[to[p]]=1;
				if(dis[to[p]]<dis[q[ql]]){
					if(ql==0)ql=P;
					q[--ql]=to[p];
				}else{
					q[qr++]=to[p];
					if(qr==P)qr=0;
				}
			}
		}
		return dis[s]<0;
	}
	int dfs(int k,int mf){
		if(k==t)return cost+=(LL)dis[s]*mf,mf;
		vis[k]=clock;
		int flow=0,tf;
		for(int p=head[k];p&&mf;p=next[p])
			if(c[p]&&vis[to[p]]!=clock&&dis[to[p]]+w[p]==dis[k]&&(tf=dfs(to[p],min(c[p],mf))))
				c[p]-=tf,c[p^1]+=tf,flow+=tf,mf-=tf;
		return flow;
	}
	int zkwflow(int start,int end,LL&c){
		s=start;t=end;
		int flow=0,tf;
		while(spfa())while(tf=dfs(s,inf))++clock,flow+=tf;
		return c=cost,flow;
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d%d",&nl,&nr,&m);
	G.getp(start);
	rep(i,1,nl)G.addedge(start,boy[i],1,0);
	G.getp(end);
	rep(i,1,nr)G.addedge(girl[i],end,1,0);
	rep(i,1,m){int a,b,c;scanf("%d%d%d",&a,&b,&c);G.addedge(boy[a],girl[b],1,-c);}
	LL ans;G.zkwflow(start,end,ans);
	printf("%lld\n",-ans);
	rep(i,1,nl){
		for(int p=G.head[boy[i]];p;p=G.next[p])if(G.to[p]!=start&&G.c[p]==0)wife[i]=G.to[p]-nl-2;
	}
	rep(i,1,nl)printf("%d ",wife[i]);
	return 0;
}
