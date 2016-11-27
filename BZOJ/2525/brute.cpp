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
const int N=3e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,d[N],c[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],dep[N],vis[N],pa[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void build(int k,int pre){
		dep[k]=dep[pre]+1;pa[k]=pre;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)build(to[p],k);
	}
	void dfs(int k,int pre,int l){
		vis[k]=1;
		if(l==0)return;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k,l-1);
	}
	bool check(int l){
		int cnt=0;
		cls(vis);
		rep(i,1,n){
			int k=c[i];
			if(d[k]==0||vis[k])continue;
			rep(j,1,l)if(pa[k])k=pa[k];
			dfs(k,0,l);
			++cnt;
		}
		return cnt<=m;
	}
}G;
bool cmp(int a,int b){return G.dep[a]>G.dep[b];}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&d[i]);
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.build(1,0);
	rep(i,1,n)c[i]=i;
	sort(c+1,c+1+n,cmp);
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(G.check(mid))r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
