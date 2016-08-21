#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double LB;
typedef long long LL;
const int maxn=1e5+10,maxm=1e6+10;
int n,m;
struct UFS{
	int rank[maxn],pa[maxn];
	void clear(){rep(i,1,n)rank[i]=0,pa[i]=i;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	bool unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return 0;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;if(rank[a]==rank[b])++rank[b];
		return 1;
	}
}set;
struct Edge{
	int a,b,w;
}edge[maxm];
bool operator<(Edge a,Edge b){return a.w<b.w;}
struct Graph{
	int tot,head[maxn],next[maxm<<1],to[maxm<<1],len[maxm<<1],size[maxn];
	LB sum[maxn];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	void clear(){tot=0;cls(head);}
	LB dfs(int k,int pre){
		size[k]=1;sum[k]=0;LB ans=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			ans+=dfs(to[p],k);size[k]+=size[to[p]];sum[k]+=sum[to[p]]+(LL)size[to[p]]*len[p];
		}
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			ans+=(sum[to[p]]+(LL)size[to[p]]*len[p])*(LL)(size[k]-size[to[p]]);
		}
		return ans;
	}
}G;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		G.clear();set.clear();
		rep(i,1,m)scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].w);
		sort(edge+1,edge+1+m);LL ans=0;
		rep(i,1,m)if(set.unio(edge[i].a,edge[i].b))G.addedge(edge[i].a,edge[i].b,edge[i].w),ans+=edge[i].w;
		printf("%lld %.2lf\n",ans,(double)(1.0*G.dfs(1,0)/((LL)n*(n-1)/2)));
	}
}
