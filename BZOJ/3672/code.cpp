#include<iostream>
#include<cstdio>
#define lson son[k][0]
#define rson son[k][1]
#define maxn 200009
#define inf (1e9)

using namespace std;

int n,dp[maxn];
struct deque{
	int val[10000000],maxx[10000000],minn[10000000],son[10000000][2],root[maxn],head[maxn],tail[maxn],tot,now;
	void build(int k,int l,int r){
		if(l==r)return;
		int m=(l+r)>>1;
		build(son[k][0]=++tot,l,m);
		build(son[k][1]=++tot,m+1,r);
	}
	void pushup(int k){
		maxx[k]=minn[k]=val[k];
		if(lson)maxx[k]=max(maxx[k],maxx[lson]),minn[k]=min(minn[k],minn[lson]);
		if(rson)maxx[k]=max(maxx[k],maxx[rson]),minn[k]=min(minn[k],minn[rson]);
	}
	void nchange(int p,int v,int k,int l,int r){
		if(l==r)val[k]=v;
		else{
			int m=(l+r)>>1;
			if(p<=m)nchange(p,v,lson,l,m);
			else nchange(p,v,rson,m+1,r);
		}
		pushup(k);
	}
	int change(int p,int v,int k,int l,int r){
		int t=++tot;
		if(l==r)val[t]=v;
		else{
			int m=(l+r)>>1;
			if(p<=m)son[t][0]=change(p,v,lson,l,m),son[t][1]=rson;
			else son[t][1]=change(p,v,rson,m+1,r),son[t][0]=lson;
		}
		pushup(t);
		return t;
	}
	int Pth(int p,int k,int l,int r){
		if(l==r)return val[k];
		else{
			int m=(l+r)>>1;
			if(p<=m)return Pth(p,lson,l,m);
			else return Pth(p,rson,m+1,r);
		}
	}
	int find(int x){
		int k=root[now],l=1,r=n;
		while(k){
			if(lson&&minn[lson]<=x)k=lson,r=(l+r)>>1;
			else if(rson)k=rson,l=((l+r)>>1)+1;
			else return l-head[k]+1;
		}
	}
	int back(){
		return Pth(tail[now],root[now],1,n);
	}
	void pop_back(){
		nchange(tail[now],inf,root[now],1,n);
		--tail[now];
	}
	void push_back(int x){
		change(++tail[now],x,root[now],1,n);
	}
	int front(){
		return Pth(head[now],root[now],1,n);
	}
	void pop_front(){
		nchange(head[now],inf,root[now],1,n);
		++head[now];
	}
	void push_front(int x){
		change(--head[now],x,root[now],1,n);
	}
	void clone(int old,int x){
		now=x;
		root[now]=++tot;
		son[tot][0]=son[old][0];son[tot][1]=son[old][1];
		head[now]=head[old];tail[now]=tail[old];
	}
	bool empty(){
		return head[now]>tail[now];
	}
} Q,GG;
struct graph{
	int tot,pa[maxn],head[maxn],to[maxn<<1],next[maxn<<1],s[maxn],l[maxn],p[maxn],q[maxn],depth[maxn];
	double g(int i,int j){
		return double(dp[i]-dp[j])/(depth[j]-depth[i]);
	}
	void addson(int a,int b){
		to[++tot]=b;
		next[tot]=head[a];
		head[a]=tot;
		pa[b]=a;
	}
	void getDepth(int k,int pre=0){
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)depth[to[p]]=depth[k]+s[to[p]],getDepth(to[p],k);
	}
	int getans(int k,int i){
		return dp[i]+(depth[k]-depth[i])*p[k]+q[k];
	}
	void dfs(int k,int pre=0){
		Q.clone(pa[k],k);GG.clone(pa[k],k);
		if(pre){
			while((!GG.empty())&&(depth[k]-depth[Q.front()]>l[k])) Q.pop_front(),GG.pop_front();
			dp[k]=getans(k, Q.Pth(GG.find(-p[k]),Q.root[Q.now],1,n));
			while((!GG.empty())&&(GG.back()<=g(Q.back(),k))) Q.pop_back(),GG.pop_back();
			GG.push_back(g(Q.back(),k));Q.push_back(k);
		}
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			dfs(to[p],k);
		}
	}
} G;

int main(){
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout); 
	int t;
	scanf("%d%d",&n,&t);
	for(int i=2;i<=n;++i){
		int f,s,p,q,l;
		scanf("%d%d%d%d%d",&f,&s,&p,&q,&l);
		G.addson(f,i);
		G.p[i]=p;G.q[i]=q;G.l[i]=l;G.s[i]=s;
	}
	Q.build(Q.root[0]=++Q.tot,1,n);Q.head[0]=1;
	G.getDepth(1);
	Q.push_back(1);
	G.dfs(1);
	for(int i=2;i<=n;++i)printf("%d\n",dp[i]);
	return 0;
}
