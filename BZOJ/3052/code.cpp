#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10,S1=1300,S2=2000;//tree[S1,3*S1],time=S2
int n,m,q;
int v[N],w[N],c[N],dfn[N],clo;
int in[N],apt[N],lca;
LL ans;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],dep[N],pa[N][20],size[N],belong[N],treeB;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int sta[N],top;
	void dfs(int k,int pre){
		dfn[k]=++clo;dep[k]=dep[pre]+1;pa[k][0]=pre;
		sta[++top]=k;
		rep(i,1,19)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			dfs(to[p],k);
			size[k]+=size[to[p]];
			if(size[k]>=S1){
				++treeB;
				while(sta[top]!=k)belong[sta[top--]]=treeB;
				size[k]=0;
			}
		}
		++size[k];
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	void trans(int a,int b){
		while(a!=b){
			if(dep[a]<dep[b])swap(a,b);
			if(in[a])ans-=(LL)w[apt[c[a]]--]*v[c[a]];
			else ans+=(LL)w[++apt[c[a]]]*v[c[a]];
			in[a]^=1;
			a=pa[a][0];
		}
	}
}G;
int iqu,imo;
struct Query{
	int x,y,pos,time;
	Query(){}
	Query(int x,int y,int pos,int time):x(x),y(y),pos(pos),time(time){}
}qu[N];
LL ret[N],tmp[N];
bool operator<(const Query&a,const Query&b){
	if(a.time/S2==b.time/S2){
		if(G.belong[a.y]==G.belong[b.y]){
			return dfn[a.x]<dfn[b.x];
		}else return G.belong[a.y]<G.belong[b.y];
	}else return a.time/S2<b.time/S2;
}
struct Modification{
	int x,y;
	Modification(){}
	Modification(int x,int y):x(x),y(y){}
	void Apply(){
		if(in[x]){
			ans+=(LL)w[++apt[y]]*v[y]-(LL)w[apt[c[x]]--]*v[c[x]];
		}
		swap(c[x],y);
	}
}mo[N];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,m)scanf("%d",&v[i]);
	rep(i,1,n)scanf("%d",&w[i]);
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	rep(i,1,n)scanf("%d",&c[i]);
	rep(i,1,q){
		int t;scanf("%d",&t);
		if(t){
			int x,y;scanf("%d%d",&x,&y);
			++iqu;qu[iqu]=Query(x,y,iqu,imo);
		}else{
			int x,y;scanf("%d%d",&x,&y);
			mo[++imo]=Modification(x,y);
		}
	}
	G.dfs(1,0);
	while(G.top)G.belong[G.sta[G.top--]]=G.treeB;
	sort(qu+1,qu+1+iqu);
	int x=1,y=1,t=0;
	rep(i,1,iqu){
		while(t<qu[i].time)mo[++t].Apply();
		while(t>qu[i].time)mo[t--].Apply();
		G.trans(y,qu[i].y);
		G.trans(x,qu[i].x);
		x=qu[i].x;y=qu[i].y;
		int f=G.lca(x,y);
		ret[i]=ans+(LL)w[apt[c[f]]+1]*v[c[f]];
	}
	rep(i,1,iqu)tmp[qu[i].pos]=ret[i];
	rep(i,1,iqu)printf("%lld\n",tmp[i]);
}
