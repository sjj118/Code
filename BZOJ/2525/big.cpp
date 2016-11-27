#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define fi first
#define se second
#define mp make_pair
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef pair<int,int> pii;
const int N=3e6+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,d[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],dep[N],l;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void build(int k,int pre){
		dep[k]=dep[pre]+1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)build(to[p],k);
	}
	pii dfs(int k,int pre){
		pii ret=mp(0,0);int maxd=0;
		if(d[k]==0)ret.se=-inf;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			pii tmp=dfs(to[p],k);
			ret.fi+=tmp.fi;
			if(tmp.se==-inf)continue;
			++tmp.se;
			if(tmp.se>=0)up(ret.se,tmp.se);
			else up(maxd,-tmp.se);
		}
		if(maxd-1>=ret.se)ret.se=-maxd;
		if(ret.se==l)++ret.fi,ret.se=-l-1;
		return ret;
	}
	bool check(int x){
		l=x;
		pii a=dfs(1,0);
		int tmp=a.fi;
		if(a.se>=0)++tmp;
		return tmp<=m;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&d[i]);
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.build(1,0);
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(G.check(mid))r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
