#include<iostream>
#include<cstdio>
using namespace std;
namespace Task{

#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
const int N=3e4+10,M=1e5+10,P=8*N;
int n,m,a[N];
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
struct Query{
	int k,a,b;
	Query(){k=a=b=0;}
	Query(int _k,int _a,int _b){k=_k;a=_a;b=_b;}
}Q[M];
int dclock,in[N],out[N],vis[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],pa[N][15],dep[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		in[k]=++dclock;vis[k]=1;dep[k]=dep[pre]+1;pa[k][0]=pre;
		rep(i,1,14)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
		out[k]=++dclock;
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,14,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,14,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
}G;
struct SGT{
#define ls (k<<1)
#define rs (k<<1|1)
	int val[P],c[P],sum[P];
	void update(int k,int l,int r){
		if(l==r){sum[k]=val[k]*c[k];return;}
		sum[k]=sum[ls]+sum[rs];
	}
	void modify_c(int p,int v,int k,int l,int r){
		if(l==r){c[k]=v;return;}
		int m=(l+r)>>1;
		if(p<=m)modify_c(p,v,ls,l,m);
		else modify_c(p,v,rs,m+1,r);
	}
	void modify_val(int p,int v,int k,int l,int r){
		if(l==r){val[k]=v;update(k,l,r);return;}
		int m=(l+r)>>1;
		if(p<=m)modify_val(p,v,ls,l,m);
		else modify_val(p,v,rs,m+1,r);
		update(k,l,r);
	}
	int query(int ll,int rr,int k,int l,int r){
		if(ll>rr)return 0;
		if(ll<=l&&r<=rr)return sum[k];
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,ls,l,m);
		if(ll>m)return query(ll,rr,rs,m+1,r);
		return query(ll,rr,ls,l,m)+query(ll,rr,rs,m+1,r);
	}
}T;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	scanf("%d",&m);
	rep(i,1,m){
		char op[20];int k,a,b;scanf("\n%s%d%d",op,&a,&b);
		if(op[0]=='b')k=1;
		else if(op[0]=='p')k=2;
		else k=3;
		Q[i]=Query(k,a,b);
	}
	S.clear();
	rep(i,1,m)if(Q[i].k==1&&S.unio(Q[i].a,Q[i].b))G.addedge(Q[i].a,Q[i].b);
	rep(i,1,n)if(!vis[i])G.dfs(i,0);
	rep(i,1,n)T.modify_c(in[i],1,1,1,dclock),T.modify_c(out[i],-1,1,1,dclock);
	rep(i,1,n)T.modify_val(in[i],a[i],1,1,dclock),T.modify_val(out[i],a[i],1,1,dclock);
	S.clear();
	rep(i,1,m){
		int k=Q[i].k,a=Q[i].a,b=Q[i].b;
		if(k==1){
			if(S.unio(a,b))puts("yes");else puts("no");
		}
		if(k==2){
			T.modify_val(in[a],b,1,1,dclock);
			T.modify_val(out[a],b,1,1,dclock);
		}
		if(k==3){
			if(S.find(a)==S.find(b)){
				int lca=G.lca(a,b),f=G.pa[lca][0];
				printf("%d\n",T.query(1,in[a],1,1,dclock)+T.query(1,in[b],1,1,dclock)-T.query(1,in[lca],1,1,dclock)-T.query(1,in[f],1,1,dclock));
			}else puts("impossible");
		}
	}
	return 0;
}

}
int main(){
	//freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return Task::main();
}
