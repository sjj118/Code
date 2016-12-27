#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,m,val[N],size[N];
const int P=5e6;
#define ls son[k][0]
#define rs son[k][1]
struct SGT{
	int tot,son[P][2],val[P];
	inline void update(int k){
		val[k]=val[ls]+val[rs];
	}
	inline void modify(int p,int v,int&k,int l,int r){
		if(!k)k=++tot;
		if(l==r){val[k]+=v;return;}
		int m=(l+r)>>1;
		if(p<=m)modify(p,v,ls,l,m);
		else modify(p,v,rs,m+1,r);
		update(k);
	}
	inline int query(int ll,int rr,int k,int l,int r){
		if(!k)return 0;
		if(ll<=l&&r<=rr)return val[k];
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,ls,l,m);
		if(ll>m)return query(ll,rr,rs,m+1,r);
		return query(ll,rr,ls,l,m)+query(ll,rr,rs,m+1,r);
	}
}T,T2;
int root[N],root2[N];
struct DivideTree{
	int tot,head[N],to[N<<1],next[N<<1],pa[N];
	inline void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;pa[b]=a;}
}DT;
struct LinkMap{
	int tot,head[N],next[P],to[P];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
}lp;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],mark[N],weight[N],dep[N],pa[N][20];
	inline void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	inline void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		dep[k]=dep[pre]+1;pa[k][0]=pre;
		rep(i,1,19)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
	}
	inline int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	inline int dis(int a,int b){
		return dep[a]+dep[b]-2*dep[lca(a,b)];
	}
	int getsize(int k,int pre,int l){
		size[k]=1;
		lp.ins(k,l);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]])size[k]+=getsize(to[p],k,l+1);
		return size[k];
	}
	int getcore(int k,int pre,int s){
		int ret=k;weight[k]=s-size[k];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]])up(weight[k],size[to[p]]);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]]){
			int t=getcore(to[p],k,s);
			if(weight[t]<weight[ret])ret=t;
		}
		return ret;
	}
	void build(int k,int pre,int g,int t,int l){
		T.modify(l,val[k],root[t],0,size[t]-1);
		T2.modify(l,val[k],root2[g],1,size[g]);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]])build(to[p],k,g,t,l+1);
	}
	void divide(int k){
		mark[k]=1;
		getsize(k,0,0);
		T.modify(0,val[k],root[k],0,size[k]-1);
		for(int p=head[k];p;p=next[p])if(!mark[to[p]]){
			int g=getcore(to[p],k,size[to[p]]);
			DT.ins(k,g);
			divide(g);
			build(to[p],k,g,k,1);
		}
		mark[k]=0;
	}
}G;
void modify(int k,int t,int v,int p){
	T.modify(lp.to[p],v,root[k],0,size[k]-1);
	if(DT.pa[k]){
		T2.modify(lp.to[lp.next[p]],v,root2[k],1,size[k]);
		modify(DT.pa[k],t,v,lp.next[p]);
	}
}
int query(int k,int t,int l,int p){
	int ret=T.query(0,l-lp.to[p],root[k],0,size[k]-1);
	if(DT.pa[k]){
		ret-=T2.query(0,l-lp.to[lp.next[p]],root2[k],1,size[k]);
		ret+=query(DT.pa[k],t,l,lp.next[p]);
	}
	return ret;
}
int main(){
	//freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	n=read();m=read();
	rep(i,1,n)val[i]=read();
	rep(i,1,n-1){G.addedge(read(),read());}
	G.dfs(1,0);
	G.divide(1);
	int ans=0;
	while(m--){
		int op=read(),x=read(),y=read();
		x^=ans;y^=ans;
		if(op){
			modify(x,x,y-val[x],lp.head[x]);
			val[x]=y;
		}else{
			printf("%d\n",ans=query(x,x,y,lp.head[x]));
		}
	}
	return 0;
}
