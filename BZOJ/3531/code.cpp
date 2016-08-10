#include<iostream>
#include<cstdio>
#define lson son[k][0]
#define rson son[k][1]
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int maxn=1e5+10,maxp=1e7,maxc=1e5;
using namespace std;
inline int read(){int tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,q,w[maxn],c[maxn];
struct SGT{
	int tot,son[maxp][2],val[maxp],sum[maxp],maxv[maxp];
	void modify(int p,int v,int&k,int l,int r){
		if(!k)k=++tot;
		if(l==r){val[k]=sum[k]=maxv[k]=v;return;}
		int m=(l+r)>>1;
		if(p<=m)modify(p,v,lson,l,m);
		else modify(p,v,rson,m+1,r);
		sum[k]=sum[lson]+sum[rson];
		maxv[k]=max(maxv[lson],maxv[rson]);
	}
	int getmax(int ll,int rr,int k,int l,int r){
		if(!k)return 0;
		if(ll<=l&&r<=rr)return maxv[k];
		int m=(l+r)>>1;
		if(rr<=m)return getmax(ll,rr,lson,l,m);
		if(ll>m)return getmax(ll,rr,rson,m+1,r);
		return max(getmax(ll,rr,lson,l,m),getmax(ll,rr,rson,m+1,r));
	}
	int getsum(int ll,int rr,int k,int l,int r){
		if(!k)return 0;
		if(ll<=l&&r<=rr)return sum[k];
		int m=(l+r)>>1;
		if(rr<=m)return getsum(ll,rr,lson,l,m);
		if(ll>m)return getsum(ll,rr,rson,m+1,r);
		return getsum(ll,rr,lson,l,m)+getsum(ll,rr,rson,m+1,r);
	}
}T;
int top[maxn],pos[maxn],cnt,root[maxn];
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],size[maxn],dep[maxn],pa[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int getsize(int k,int pre){
		size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dep[to[p]]=dep[k]+1,size[k]+=getsize(to[p],k),pa[to[p]]=k;
		return size[k];
	}
	void dfs(int k,int pre){
		int g=0;pos[k]=++cnt;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)if(g==0||size[to[p]]>size[g])g=to[p];
		if(!g)return;
		top[g]=top[k];dfs(g,k);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&to[p]!=g){
			top[to[p]]=to[p];
			dfs(to[p],k);
		}
	}
	int getsum(int u,int v,int c){
		int sum=0;
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]])swap(u,v);
			sum+=T.getsum(pos[top[u]],pos[u],root[c],1,n);
			u=pa[top[u]];
		}
		if(dep[u]<dep[v])swap(u,v);
		sum+=T.getsum(pos[v],pos[u],root[c],1,n);
		return sum;
	}
	int getmax(int u,int v,int c){
		int maxv=0;
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]])swap(u,v);
			maxv=max(maxv,T.getmax(pos[top[u]],pos[u],root[c],1,n));
			u=pa[top[u]];
		}
		if(dep[u]<dep[v])swap(u,v);
		maxv=max(maxv,T.getmax(pos[v],pos[u],root[c],1,n));
		return maxv;
	}
}G;

int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n)w[i]=read(),c[i]=read();
	rep(i,1,n-1){
		int x=read(),y=read();
		G.addedge(x,y);
	}
	G.dep[1]=1;G.getsize(1,0);
	top[1]=1;G.dfs(1,0);
	rep(i,1,n)T.modify(pos[i],w[i],root[c[i]],1,n);
	rep(i,1,q){
		char op=getchar();
		while(op<'A'||op>'Z')op=getchar();
		op=getchar();
		if(op=='C'){
			int x=read(),v=read();
			T.modify(pos[x],0,root[c[x]],1,n);
			T.modify(pos[x],w[x],root[v],1,n);
			c[x]=v;
		}else if(op=='W'){
			int x=read(),v=read();
			T.modify(pos[x],v,root[c[x]],1,n);
			w[x]=v;
		}else if(op=='S'){
			int x=read(),y=read();
			printf("%d\n",G.getsum(x,y,c[x]));
		}else{
			int x=read(),y=read();
			printf("%d\n",G.getmax(x,y,c[x]));
		}
	}
	return 0;
}
