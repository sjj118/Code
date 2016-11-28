#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
const int N=3e5+10;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
inline void output(int x){
	int a[10],l=0;
	while(x)a[++l]=x%10,x/=10;
	if(l==0)putchar('0');
	per(i,l,1)putchar(a[i]+'0');putchar(' ');
}
int n,m,w[N],ans[N];
struct LinkMap{
	int tot,head[N],next[N<<1],d[N<<1],f[N<<1];
	void ins(int a,int _d,int _f){next[++tot]=head[a];head[a]=tot;d[tot]=_d;f[tot]=_f;}
}low,high;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],dep[N],pa[N][20],top[N],pos[N],size[N],dc;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int getsize(int k,int pre){
		dep[k]=dep[pre]+1;pa[k][0]=pre;size[k]=1;
		rep(i,1,19)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)size[k]+=getsize(to[p],k);
		return size[k];
	}
	void build(int k,int pre){
		pos[k]=++dc;
		int mx=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			if(mx==0||size[to[p]]>size[mx])mx=to[p];
		}
		if(mx==0)return;
		top[mx]=top[k];
		build(mx,k);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&to[p]!=mx)top[to[p]]=to[p],build(to[p],k);
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
	int sta[22][N<<1],tp,vis[22][N<<1],cnt[22];
	void dfs_low(int k,int pre){
		int mx=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			if(mx==0||size[to[p]]>size[mx])mx=to[p];
		}
		if(mx)dfs_low(mx,k);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&to[p]!=mx){
			++tp;dfs_low(to[p],k);
			rep(i,1,cnt[tp])sta[tp-1][vis[tp][i]]+=sta[tp][vis[tp][i]],sta[tp][vis[tp][i]]=0,vis[tp-1][++cnt[tp-1]]=vis[tp][i];
			cnt[tp]=0;--tp;
		}
		for(int p=low.head[k];p;p=low.next[p])sta[tp][low.d[p]]+=low.f[p],vis[tp][++cnt[tp]]=low.d[p];
		if(w[k]+dep[k]<N)ans[k]+=sta[tp][w[k]+dep[k]];
	}
	void dfs_high(int k,int pre){
		int mx=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			if(mx==0||size[to[p]]>size[mx])mx=to[p];
		}
		if(mx)dfs_high(mx,k);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&to[p]!=mx){
			++tp;dfs_high(to[p],k);
			rep(i,1,cnt[tp])sta[tp-1][vis[tp][i]]+=sta[tp][vis[tp][i]],sta[tp][vis[tp][i]]=0,vis[tp-1][++cnt[tp-1]]=vis[tp][i];
			cnt[tp]=0;--tp;
		}
		for(int p=high.head[k];p;p=high.next[p])sta[tp][high.d[p]+N]+=high.f[p],vis[tp][++cnt[tp]]=high.d[p]+N;
		if(w[k]+dep[k]<(N<<1))ans[k]+=sta[tp][dep[k]-w[k]+N];
	}
}G;
int main(){
	n=read();m=read();
	rep(i,1,n-1){int u=read(),v=read();G.addedge(u,v);}
	G.getsize(1,0);
	//G.build(1,0);
	rep(i,1,n)w[i]=read();
	rep(i,1,m){
		int s=read(),t=read();
		int f=G.lca(s,t);
		low.ins(s,G.dep[s],1);low.ins(f,G.dep[s],-1);
		high.ins(t,G.dep[f]-G.dep[s]+G.dep[f],1);high.ins(G.pa[f][0],G.dep[f]-G.dep[s]+G.dep[f],-1);
	}
	G.cnt[G.tp=0]=0;G.dfs_low(1,0);
	G.cnt[G.tp=0]=0;G.dfs_high(1,0);
	rep(i,1,n)output(ans[i]);
	return 0;
}
}
int main(){
	freopen("running.in","r",stdin);freopen("running.out","w",stdout);
	return sjj118::main();
}
