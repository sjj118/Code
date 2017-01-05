#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int n,m,ans[N];
bool cmp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[N],ml,rl[N];
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,cmp);
		for(int i=1,last=0;i<=tot;++i){
			if(*val[i]>last)rl[++ml]=last=*val[i];
			*val[i]=ml;
		}
	}
}lisan;
int val[N];
#define ls (k<<1)
#define rs (k<<1|1)
struct SGT{
	int tot,mav[N<<2];
	void update(int k){
		if(val[mav[ls]]>=val[mav[rs]])mav[k]=mav[ls];else mav[k]=mav[rs];
	}
	void modify(int p,int v,int k,int l,int r){
		if(l==r){val[l]+=v;if(val[l])mav[k]=l;else mav[k]=0;return;}
		int m=(l+r)>>1;
		if(p<=m)modify(p,v,ls,l,m);
		else modify(p,v,rs,m+1,r);
		update(k);
	}
}T;
struct LinkMap{
	int tot,head[N],to[N<<2],next[N<<2],size[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;++size[a];}
	void work(int k,int f=1){
		for(int p=head[k];p;p=next[p])if(to[p]*f>0)T.modify(f*to[p],1,1,1,n);else T.modify(-f*to[p],-1,1,1,n);
	}
}lp;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],size[N],in[N],out[N],clo,pa[N][20],dep[N],ver[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void build(int k,int pre){
		pa[k][0]=pre;dep[k]=dep[pre]+1;
		rep(i,1,19)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)build(to[p],k);
	}
	int getsize(int k,int pre){
		size[k]=lp.size[k]+1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)size[k]+=getsize(to[p],k);
		return size[k];
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	void dfs(int k,int pre,bool keep){
		ver[in[k]=++clo]=k;
		int mx=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&size[to[p]]>size[mx])mx=to[p];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&to[p]!=mx)dfs(to[p],k,0);
		if(mx)dfs(mx,k,1);
		lp.work(k);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&to[p]!=mx)rep(i,in[to[p]],out[to[p]])lp.work(ver[i]);
		ans[k]=T.mav[1];
		out[k]=clo;
		if(!keep)rep(i,in[k],out[k])lp.work(ver[i],-1);
	}
}G;
struct fafang{
	int x,y,z;
}f[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n-1){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	rep(i,1,m)scanf("%d%d%d",&f[i].x,&f[i].y,&f[i].z),lisan.ins(f[i].z);
	G.build(1,0);
	lisan.work();
	rep(i,1,m){
		lp.ins(f[i].x,f[i].z);
		lp.ins(f[i].y,f[i].z);
		int p=G.lca(f[i].x,f[i].y);
		lp.ins(p,-f[i].z);
		lp.ins(G.pa[p][0],-f[i].z);
	}
	G.getsize(1,0);
	G.dfs(1,0,1);
	rep(i,1,n)printf("%d\n",lisan.rl[ans[i]]);
	return 0;
}
