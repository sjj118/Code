#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const LL inf=1e18;
const int N=1000+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
int n;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],size[N],dis[N],len[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void build(int k,int pre){
		size[k]=1;dis[k]=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			len[to[p]]=len[k]+1;
			build(to[p],k);
			size[k]+=size[to[p]];
			up(dis[k],dis[to[p]]+1);
		}
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n-1){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	rep(i,1,n){
		LL ans=inf;
		if(n==1)ans=0;
		G.len[i]=0;G.build(i,0);
		int maxsize=0,maxdis=0,othdis=0;
		for(int p=G.head[i];p;p=G.next[p])if(G.size[G.to[p]]>maxsize)maxsize=G.size[G.to[p]],up(othdis,maxdis),maxdis=G.dis[G.to[p]]+1;
		else up(othdis,G.dis[G.to[p]]+1);
		int othsize=n-1-maxsize;
		LL sumdis=0;
		rep(i,1,n)sumdis+=G.len[i];
		if(maxsize-1<=othsize)dn(ans,sumdis*2-maxdis);
		if(maxsize<=othsize-1)dn(ans,sumdis*2-othdis);
		printf("%lld\n",ans==inf?-1:ans);
	}
	return 0;
}
