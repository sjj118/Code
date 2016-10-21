#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=15000+10,M=30000+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,k;
struct Edge{
	int x,y,d;
	Edge(){x=y=d=0;}
	Edge(int x,int y,int d){this->x=x;this->y=y;this->d=d;}
}e[M];
bool operator<(const Edge&a,const Edge&b){return a.d<b.d;}
struct UFS{
	int pa[N],rank[N];
	void clear(){rep(i,1,n)pa[i]=i;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	bool unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return 0;
		if(rank[a]<rank[b])swap(a,b);
		pa[b]=a;
		if(rank[a]==rank[b])++rank[a];
		return 1;
	}
}S;
struct Graph{
	int tot,head[N],to[M<<1],next[M<<1],len[M<<1],pa[N][14],dep[N],maxv[N][14];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	void dfs(int k,int pre){
		pa[k][0]=pre;dep[k]=dep[pre]+1;
		rep(i,1,13)pa[k][i]=pa[pa[k][i-1]][i-1],maxv[k][i]=max(maxv[k][i-1],maxv[pa[k][i-1]][i-1]);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)maxv[to[p]][0]=len[p],dfs(to[p],k);
	}
	int query_max(int a,int b){
		int ret=0;
		if(dep[a]>dep[b])swap(a,b);
		per(i,13,0)if(dep[pa[b][i]]>=dep[a])up(ret,maxv[b][i]),b=pa[b][i];
		if(a==b)return ret;
		per(i,13,0)if(pa[a][i]!=pa[b][i])up(ret,maxv[a][i]),a=pa[a][i],up(ret,maxv[b][i]),b=pa[b][i];
		up(ret,maxv[a][0]);up(ret,maxv[b][0]);
		return ret;
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){int x,y,d;scanf("%d%d%d",&x,&y,&d);e[i]=Edge(x,y,d);}
	sort(e+1,e+1+m);S.clear();
	rep(i,1,m)if(S.unio(e[i].x,e[i].y))
	G.addedge(e[i].x,e[i].y,e[i].d);
	G.dfs(1,0);
	while(k--){
		int a,b;scanf("%d%d",&a,&b);
		printf("%d\n",G.query_max(a,b));
	}
	return 0;
}
