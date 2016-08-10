#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int inf=1e9,maxn=2016,maxm=50,maxp=100000,maxv=400000;
const double eps=1e-8;
using namespace std;
inline char gc(){char c=getchar();while(!(c=='-'||c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0,f=1;char c=gc();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp*f;}
inline LL ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;return x;}
inline LL ad(LL&x,LL y,LL p){return ck(x+=y,p);}
inline void up(LL&x,LL y){if(y>x)x=y;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
inline LL gcd(LL a,LL b){if(!b)return a;return gcd(b,a%b);}
inline LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
inline LL sqr(LL x){return x*x;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;x=x*x%p,y>>=1)if(y&1)a=a*x%p;return a;}
inline LL exgcd(LL a,LL b,LL&x,LL&y){if(!b)return x=1,y=0,a;LL d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
inline LL inv(LL n,LL p){LL x,y;if(exgcd(n,p,x,y)>1)cerr<<"NO_REV"<<endl;return ck(x,p);}
int n,m;
struct Graph{
	int tot,head[maxp],next[maxv],to[maxv],c[maxv],dis[maxp],cur[maxp];
	int pointsize,s,t;
	void ins(int a,int b,int f){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;}
	void getp(int&x){if(!x)x=++pointsize;}
	void addedge(int&a,int&b,int f){getp(a);getp(b);ins(a,b,f);ins(b,a,0);}
	int q[maxp],ql,qr;
	bool bfs(){
		rep(i,1,pointsize)dis[i]=0,cur[i]=head[i];
		ql=1;qr=0;q[++qr]=t;
		while(ql<=qr)
			for(int k=q[ql++],p=head[k];p;p=next[p])
			if(c[p^1]&&to[p]!=t&&!dis[to[p]])dis[q[++qr]=to[p]]=dis[k]+1;
		return dis[s];
	}
	int dfs(int k,int maxflow){
		if(k==t)return maxflow;
		int flow=0,tflow;
		for(int&p=cur[k];p&&maxflow;p=next[p])
			if(c[p]&&dis[to[p]]+1==dis[k]&&(tflow=dfs(to[p],min(c[p],maxflow))))
			c[p]-=tflow,c[p^1]+=tflow,maxflow-=tflow,flow+=tflow;
		return flow;
	}
	int Dinic(int start,int end){
		s=start;t=end;int flow=0;
		while(bfs())flow+=dfs(s,inf);
		return flow;
	}
	void clear(){tot=1;pointsize=0;cls(head);}
}G;
int mid;
int ca[maxn];
int cave[maxm][maxn],node[maxn],start,end;
struct Tree{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int start,int k,int len,int pre){
		if(len>mid)return;
		G.addedge(node[k],cave[start][len],1);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(start,to[p],len+1,k);
	}
}T;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n-1){
		int u=read(),v=read();
		T.addedge(u,v);
	}
	rep(i,1,m)ca[i]=read();
	int l=1,r=n;
	while(l<r){
		G.clear();mid=(l+r)>>1;start=end=0;cls(node);cls(cave);
		rep(i,1,m)T.dfs(i,ca[i],0,0);
		rep(i,1,n)G.addedge(start,node[i],1);
		rep(i,1,m)rep(j,0,mid)G.addedge(cave[i][j],end,1);
		rep(i,1,m)rep(j,1,mid)G.addedge(cave[i][j-1],cave[i][j],inf);
		if(G.Dinic(start,end)==n)r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}

