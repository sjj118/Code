#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=3e5+10;
typedef long long LL;
int n,q;
struct Graph{
	int tot,head[maxn],next[maxn<<1],to[maxn<<1],size[maxn],dep[maxn],pa[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		size[k]=0;dep[k]=dep[pre]+1;pa[k]=pre;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k),size[k]+=size[to[p]]+1;
	}
	LL count(int k,int pre,int h,int maxh){
		if(h>maxh)return 0;
		LL tmp=size[k];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)tmp+=count(to[p],k,h+1,maxh);
		return tmp;
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d%d",&n,&q);
	rep(i,1,n-1){
		int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);
	}
	G.dfs(1,0);
	rep(i,1,q){
		int p,k;scanf("%d%d",&p,&k);
		LL ans=min(k,G.dep[p]-1)*(G.size[p]);
		ans+=G.count(p,G.pa[p],0,k)-G.size[p];
		printf("%lld\n",ans);
	}
	return 0;
}
