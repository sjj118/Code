#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::reverse;
using std::min;
const int N=1e6+10,M=N<<1,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,ps,ans;
struct Tree{
	int tot,head[M],to[M<<1],next[M<<1],lon[M],len[M];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	int a[M],q[M],ql,qr,cnt;
	int f(int x){return lon[a[x]]-x;}
	void push(int i){
		while(ql!=qr&&f(i)>=f(q[qr-1]))--qr;
		q[qr++]=i;
	}
	void pop(int i){
		while(ql!=qr&&q[ql]<=i)++ql;
	}
	int top(){
		if(ql!=qr)return f(q[ql]);
		return -inf;
	}
	void calc(){
		ql=qr=0;
		rep(i,1,2*cnt){
			pop(i-cnt/2-1);
			up(ans,lon[a[i]]+i+top());
			push(i);
		}
	}
	void dfs(int k,int pre){
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
		if(k<=n){
			int fir=0,sec=0;
			for(int p=head[k];p;p=next[p])if(to[p]!=pre){if(lon[to[p]]+len[p]>=fir)sec=fir,fir=lon[to[p]]+len[p];else if(lon[to[p]]+len[p]>sec)sec=lon[to[p]]+len[p];}
			up(ans,fir+sec);
			lon[k]=fir;
		}else{
			cnt=0;
			for(int p=head[k];p;p=next[p])a[++cnt]=to[p];
			rep(i,1,cnt)a[i+cnt]=a[i];
			calc();
			reverse(a+1,a+1+2*cnt);
			calc();
			rep(i,1,cnt)up(lon[k],lon[a[i]]+min(i-1,cnt+1-i));
		}
	}
}T;
struct Graph{
	int tot,head[N],to[M<<1],next[M<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int dfn[N],lowlink[N],clo,sta[N],top;
	void build(int k,int pre){
		dfn[k]=lowlink[k]=++clo;sta[++top]=k;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			if(dfn[to[p]])dn(lowlink[k],dfn[to[p]]);
			else{
				build(to[p],k);
				dn(lowlink[k],lowlink[to[p]]);
				if(lowlink[to[p]]>dfn[k])T.addedge(k,to[p],1),--top;
				if(lowlink[to[p]]==dfn[k]){
					T.addedge(k,++ps,0);
					while(top){
						T.addedge(ps,sta[top],0);
						if(sta[top--]==to[p])break;
					}
				}
			}
		}
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int k;scanf("%d",&k);
		int last;scanf("%d",&last);
		rep(i,2,k){int u;scanf("%d",&u);G.addedge(last,u);last=u;}
	}
	ps=n;
	G.build(1,0);
	T.dfs(1,0);
	printf("%d",ans);
	return 0;
}
