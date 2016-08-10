#include<iostream>
#include<cstdio>
#define inf 1e9
#define maxn 100000
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1

using namespace std;

struct segtree{
    int maxi[maxn],sum[maxn];
    void pushup(int n){
        sum[n]=sum[n<<1]+sum[n<<1|1];
        maxi[n]=max(maxi[n<<1],maxi[n<<1|1]);
    }
    void update(int nn,int x,int l,int r,int n){
        if(l==r){
            maxi[n]=sum[n]=x;
            return;
        }
        int m=(l+r)>>1;
        if(nn<=m)update(nn,x,lson);
        else update(nn,x,rson);
        pushup(n);
    }
    int query_max(int ll,int rr,int l,int r,int n){
        if(ll==l&&rr==r)return maxi[n];
        int m=(l+r)>>1;
        if(rr<=m)return query_max(ll,rr,lson);
        else if(ll>m)return query_max(ll,rr,rson);
        else return max(query_max(ll,m,lson),query_max(m+1,rr,rson));
    }
    int query_sum(int ll,int rr,int l,int r,int n){
        if(ll==l&&rr==r)return sum[n];
        int m=(l+r)>>1;
        if(rr<=m)return query_sum(ll,rr,lson);
        else if(ll>m)return query_sum(ll,rr,rson);
        else return query_sum(ll,m,lson)+query_sum(m+1,rr,rson);
    }
};
struct graph{
	int head[maxn],next[maxn],to[maxn];
	void addedge(int k,int a,int b){
		next[k]=head[a];
		head[a]=k;
		to[k]=b;
	};
};
int n,q,w[maxn],depth[maxn],size[maxn],pa[maxn],top[maxn],pos[maxn],cnt;
segtree T;
graph G;

void dfs1(int k){
	size[k]=1;
	for(int p=G.head[k];p;p=G.next[p]){
		if(G.to[p]==pa[k])continue;
		depth[G.to[p]]=depth[k]+1;
		pa[G.to[p]]=k;
		dfs1(G.to[p]);
		size[k]+=size[G.to[p]];
	}
}

void dfs2(int k){
	int ms=0;
	for(int p=G.head[k];p;p=G.next[p]){
		if(G.to[p]==pa[k])continue;
		if(ms==0||size[G.to[p]]>size[G.to[ms]])ms=p;
	}
	if(ms==0)return;
	top[G.to[ms]]=top[k];
	T.update(pos[G.to[ms]]=++cnt,w[G.to[ms]],1,n,1);
	dfs2(G.to[ms]);
	for(int p=G.head[k];p;p=G.next[p]){
		if(G.to[p]==pa[k])continue;
		if(p!=ms){
			top[G.to[p]]=G.to[p];
			T.update(pos[G.to[p]]=++cnt,w[G.to[p]],1,n,1);
			dfs2(G.to[p]);
		}
	}
}

void change(int a,int b){
	T.update(pos[a],b,1,n,1);
}

int getsum(int u,int v){
	int tu=top[u],tv=top[v],ans=0;
	while(tu!=tv){
		if(depth[tu]>depth[tv]){
			ans+=T.query_sum(pos[tu],pos[u],1,n,1);
			u=pa[tu];
		}else{
			ans+=T.query_sum(pos[tv],pos[v],1,n,1);
			v=pa[tv];
		}
		tu=top[u],tv=top[v];
	}
	if(depth[u]>depth[v])ans+=T.query_sum(pos[v],pos[u],1,n,1);
	else ans+=T.query_sum(pos[u],pos[v],1,n,1);
	return ans;
}

int getmax(int u,int v){
	int tu=top[u],tv=top[v],ans=-inf;
	while(tu!=tv){
		if(depth[tu]>depth[tv]){
			ans=max(ans,T.query_max(pos[tu],pos[u],1,n,1));
			u=pa[tu];
		}else{
			ans=max(ans,T.query_max(pos[tv],pos[v],1,n,1));
			v=pa[tv];
		}
		tu=top[u],tv=top[v];
	}
	if(depth[u]>depth[v])ans=max(ans,T.query_max(pos[v],pos[u],1,n,1));
	else ans=max(ans,T.query_max(pos[u],pos[v],1,n,1));
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		G.addedge(i*2-1,a,b);
		G.addedge(i*2,b,a);
	}
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	dfs1(1);
	top[1]=1;
	T.update(pos[1]=++cnt,w[1],1,n,1);
	dfs2(1);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		char s[100];
		int u,v;
		scanf("%s %d %d",s,&u,&v);
		if(s[1]=='H'){
			change(u,v);
		}else if(s[1]=='S'){
			printf("%d\n",getsum(u,v));
		}else if(s[1]=='M'){
			printf("%d\n",getmax(u,v));
		}else return 1;
	}
	return 0;
}
