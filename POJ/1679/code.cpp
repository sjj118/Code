#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=110,maxm=10000+10;
int n,m;
struct UFS{
	int rank[maxn],pa[maxn];
	void clear(){rep(i,1,n)rank[i]=0,pa[i]=i;}
	int find(int x){return x==pa[x]?x:pa[x]=find(pa[x]);}
	bool unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return 0;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
		return 1;
	}
}S;
struct Edge{
	int u,v,w,s;
}edge[maxm];
bool operator<(Edge a,Edge b){return a.w<b.w;}
struct Tree{
	int tot,head[maxn],next[maxm],to[maxm],len[maxm],pa[maxn][7],l[maxn][7],dep[maxn];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	void clear(){tot=0;cls(head);}
	void dfs(int k,int pre){
		dep[k]=dep[pre]+1;pa[k][0]=pre;
		rep(i,1,6)pa[k][i]=pa[pa[k][i-1]][i-1],l[k][i]=max(l[k][i-1],l[pa[k][i-1]][i-1]);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			l[to[p]][0]=len[p];dfs(to[p],k);
		}
	}
	int lcamax(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		int ans=0;
		per(i,6,0)if(dep[pa[a][i]]>=dep[b])ans=max(ans,l[a][i]),a=pa[a][i];
		if(a==b)return ans;
		per(i,6,0)if(pa[a][i]!=pa[b][i])ans=max(ans,l[a][i]),ans=max(ans,l[b][i]),a=pa[a][i],b=pa[b][i];
		ans=max(ans,l[a][0]);ans=max(ans,l[b][0]);
		return ans;
	}
}T;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		T.clear();S.clear();
		rep(i,1,m)scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		sort(edge+1,edge+1+m);
		int ans=0;
		rep(i,1,m)if(edge[i].s=S.unio(edge[i].u,edge[i].v))T.addedge(edge[i].u,edge[i].v,edge[i].w),ans+=edge[i].w;
		T.dfs(1,0);
		bool flag=0;
		rep(i,1,n)if(!edge[i].s&&T.lcamax(edge[i].u,edge[i].v)==edge[i].w)flag=1;
		if(flag)printf("Not Unique!\n");else printf("%d\n",ans);
	}
}
