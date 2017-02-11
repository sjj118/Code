#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=3e5+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
bool cmp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[N],ml,rl[N];
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,cmp);
		for(int i=1,lst=0;i<=tot;++i){
			if(*val[i]>lst)lst=rl[++ml]=*val[i];
			*val[i]=ml;
		}
	}
}li;
int n,q,w[N],mindis[N];
struct Graph{
	int pa[N][20],dep[N],head[N],to[N<<1],next[N<<1],tot,mw[N][20];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	int getmaxw(int a,int b){
		int ret=0;
		b=pa[b][0];
		per(i,19,0)if(dep[pa[b][i]]>=dep[a])up(ret,mw[b][i]),b=pa[b][i];
		return ret;
	}
	void search(int k,int l){
		if(l)dn(mindis[w[k]],l);
		for(int p=head[k];p;p=next[p])search(to[p],l+1);
	}
}G;
LL sans[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&w[i]),li.ins(w[i]);
	li.work();
	G.dep[1]=1;
	rep(i,2,n){
		scanf("%d",&G.pa[i][0]);
		G.ins(G.pa[i][0],i);
		G.dep[i]=G.dep[G.pa[i][0]]+1;
		G.mw[i][0]=w[i];
		rep(j,1,19)G.pa[i][j]=G.pa[G.pa[i][j-1]][j-1];
		rep(j,1,19)G.mw[i][j]=max(G.mw[i][j-1],G.mw[G.pa[i][j-1]][j-1]);
	}
	scanf("%d",&q);
	if(n<=5000&&q<=5000){
		while(q--){
			int s,t;scanf("%d%d",&s,&t);
			int f=G.lca(s,t);
			int maxw=0;
			int p=G.pa[t][0];while(G.dep[p]>=G.dep[f]){
				if(p!=s)up(maxw,w[p]);
				p=G.pa[p][0];
			}
			rep(i,1,li.ml)mindis[i]=inf;
			G.search(s,0);
			per(i,li.ml-1,1)dn(mindis[i],mindis[i+1]);
			LL ans=G.dep[s]+G.dep[t]-G.dep[f]*2;
			rep(i,1,maxw)ans+=(LL)(li.rl[i]-li.rl[i-1])*mindis[i];
			printf("%lld\n",ans);
		}
	}else{
		bool flag=1;
		rep(i,2,n)if(G.pa[i][0]!=i-1)flag=0;
		if(flag){

		}else{
			rep(i,1,li.ml)mindis[i]=inf;
			G.search(1,0);
			per(i,li.ml-1,1)dn(mindis[i],mindis[i+1]);
			rep(i,1,li.ml)sans[i]=sans[i-1]+(LL)(li.rl[i]-li.rl[i-1])*mindis[i];
			while(q--){
				int s,t;scanf("%d%d",&s,&t);
				int f=G.lca(s,t);
				int maxw=G.getmaxw(s,t);
				LL ans=G.dep[s]+G.dep[t]-G.dep[f]*2+sans[maxw];
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
