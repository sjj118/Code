#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
#define ls (k<<1)
#define rs (k<<1|1)
using namespace std;
const int maxn=2e4+10,maxp=8e4+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,pos[maxn],dclock,top[maxn];
struct SGT{
	int val[maxp],sum[maxp],maxv[maxp],minv[maxp],rev[maxp];
	void update(int k,int l,int r){
		if(l==r){sum[k]=maxv[k]=minv[k]=val[k];return;}
		sum[k]=sum[ls]+sum[rs];
		maxv[k]=max(maxv[ls],maxv[rs]);
		minv[k]=min(minv[ls],minv[rs]);
	}
	void maintain_rev(int k){
		rev[k]^=1;
		val[k]=-val[k];
		sum[k]=-sum[k];
		swap(minv[k],maxv[k]);
		minv[k]=-minv[k];
		maxv[k]=-maxv[k];
	}
	void maintain_val(int k,int c){
		val[k]=sum[k]=maxv[k]=minv[k]=c;
	}
	void maintain(int k,int l,int r){
		if(l==r)return;
		if(rev[k])rev[k]=0,maintain_rev(ls),maintain_rev(rs);
	}
	void modify_val(int p,int v,int k,int l,int r){
		maintain(k,l,r);
		if(l==r)return maintain_val(k,v);
		int m=(l+r)>>1;
		if(p<=m)modify_val(p,v,ls,l,m);
		else modify_val(p,v,rs,m+1,r);
		update(k,l,r);
	}
	void modify_rev(int ll,int rr,int k,int l,int r){
		if(ll>rr)return;
		maintain(k,l,r);
		if(ll<=l&&r<=rr)return maintain_rev(k);
		int m=(l+r)>>1;
		if(ll<=m)modify_rev(ll,rr,ls,l,m);
		if(rr>m)modify_rev(ll,rr,rs,m+1,r);
		update(k,l,r);
	}
	int query_sum(int ll,int rr,int k,int l,int r){
		if(ll>rr)return 0;
		maintain(k,l,r);
		if(ll<=l&&r<=rr)return sum[k];
		int m=(l+r)>>1;
		if(rr<=m)return query_sum(ll,rr,ls,l,m);
		if(ll>m)return query_sum(ll,rr,rs,m+1,r);
		return query_sum(ll,rr,ls,l,m)+query_sum(ll,rr,rs,m+1,r);
	}
	int query_max(int ll,int rr,int k,int l,int r){
		if(ll>rr)return -inf;
		maintain(k,l,r);
		if(ll<=l&&r<=rr)return maxv[k];
		int m=(l+r)>>1;
		if(rr<=m)return query_max(ll,rr,ls,l,m);
		if(ll>m)return query_max(ll,rr,rs,m+1,r);
		return max(query_max(ll,rr,ls,l,m),query_max(ll,rr,rs,m+1,r));
	}
	int query_min(int ll,int rr,int k,int l,int r){
		if(ll>rr)return inf;
		maintain(k,l,r);
		if(ll<=l&&r<=rr)return minv[k];
		int m=(l+r)>>1;
		if(rr<=m)return query_min(ll,rr,ls,l,m);
		if(ll>m)return query_min(ll,rr,rs,m+1,r);
		return min(query_min(ll,rr,ls,l,m),query_min(ll,rr,rs,m+1,r));
	}
}T;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],w[maxn<<1],lenpa[maxn],whopa[maxn<<1],size[maxn],dep[maxn],pa[maxn];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;w[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	Graph(){tot=1;}
	int getsize(int k,int pre){
		size[k]=1;dep[k]=dep[pre]+1;pa[k]=pre;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)lenpa[to[p]]=w[p],whopa[p]=whopa[p^1]=to[p],size[k]+=getsize(to[p],k);
		return size[k];
	}
	void dfs(int k,int pre){
		pos[k]=++dclock;
		int m=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)if(m==0||size[to[p]]>size[to[m]])m=p;
		if(m==0)return;
		top[to[m]]=top[k];dfs(to[m],k);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&p!=m)top[to[p]]=to[p],dfs(to[p],k);
	}
	void modify_val(int k,int w){
		T.modify_val(pos[whopa[k<<1]],w,1,1,n);
	}
	void modify_rev(int u,int v){
		while(top[u]!=top[v]){
			if(dep[top[u]]>dep[top[v]])swap(u,v);
			T.modify_rev(pos[top[v]],pos[v],1,1,n);
			v=pa[top[v]];
		}
		if(dep[u]<dep[v])swap(u,v);
		T.modify_rev(pos[v]+1,pos[u],1,1,n);
	}
	int query_sum(int u,int v){
		int ret=0;
		while(top[u]!=top[v]){
			if(dep[top[u]]>dep[top[v]])swap(u,v);
			ret+=T.query_sum(pos[top[v]],pos[v],1,1,n);
			v=pa[top[v]];
		}
		if(dep[u]<dep[v])swap(u,v);
		ret+=T.query_sum(pos[v]+1,pos[u],1,1,n);
		return ret;
	}
	int query_max(int u,int v){
		int ret=-inf;
		while(top[u]!=top[v]){
			if(dep[top[u]]>dep[top[v]])swap(u,v);
			up(ret,T.query_max(pos[top[v]],pos[v],1,1,n));
			v=pa[top[v]];
		}
		if(dep[u]<dep[v])swap(u,v);
		up(ret,T.query_max(pos[v]+1,pos[u],1,1,n));
		return ret;
	}
	int query_min(int u,int v){
		int ret=inf;
		while(top[u]!=top[v]){
			if(dep[top[u]]>dep[top[v]])swap(u,v);
			dn(ret,T.query_min(pos[top[v]],pos[v],1,1,n));
			v=pa[top[v]];
		}
		if(dep[u]<dep[v])swap(u,v);
		dn(ret,T.query_min(pos[v]+1,pos[u],1,1,n));
		return ret;
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n-1){int u,v,w;scanf("%d%d%d",&u,&v,&w);G.addedge(u+1,v+1,w);}
	G.getsize(1,0);top[1]=1;G.dfs(1,0);
	rep(i,1,n)T.modify_val(pos[i],G.lenpa[i],1,1,n);
	scanf("%d",&m);
	while(m--){
		char op[10];scanf("\n%s",op);
		int u,v;scanf("%d%d",&u,&v);
		if(op[0]=='C')G.modify_val(u,v);
		else if(op[0]=='N')G.modify_rev(u+1,v+1);
		else if(op[0]=='S')printf("%d\n",G.query_sum(u+1,v+1));
		else if(op[1]=='A')printf("%d\n",G.query_max(u+1,v+1));
		else printf("%d\n",G.query_min(u+1,v+1));
	}
	return 0;
}
