#include<iostream>
#include<cstdio>
#define maxn 100010
#define lson son[k][0]
#define rson son[k][1]
#define LL long long

using namespace std;

int n,m,root[maxn];
LL l[maxn],ans;
struct Leftist{
	int key[maxn],son[maxn][2],dis[maxn];
	int merge(int k,int v){
		if(key[k]<key[v])swap(k,v);
		if(!v)return k;
		rson=merge(rson,v);
		if(dis[lson]<dis[rson])swap(lson,rson);
		dis[k]=dis[rson]+1;
		return k;
	}
	void pop(int&k){k=merge(lson,rson);}
	int top(int k){return key[k];}
	void init(){dis[0]=-1;}
}heap;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],cnt[maxn];
	LL sum[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k=1,int pre=0){
		root[k]=k;
		sum[k]=heap.key[k];cnt[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			dfs(to[p],k);sum[k]+=sum[to[p]];cnt[k]+=cnt[to[p]];
			root[k]=heap.merge(root[k],root[to[p]]);
		}
		while(sum[k]>m){
			--cnt[k];sum[k]-=heap.top(root[k]);heap.pop(root[k]);
		}
		ans=max(ans,l[k]*cnt[k]);
	}
}G;

int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d",&n,&m);
	heap.init();
	for(int i=1;i<=n;++i){
		int f;scanf("%d%d%lld",&f,&heap.key[i],&l[i]);
		if(f)G.addedge(f,i);
	}
	G.dfs();
	printf("%lld",ans);
	return 0;
}
