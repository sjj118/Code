#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,P=4*N,M=1.1e7,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
int n,s,m,a[P],ps,rt,low[P];
bool len[M];
struct Grpah{
	int tot,head[P],to[M],next[M];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	int q[P],deg[P];
	bool topsort(){
		int ql=0,qr=0;
		rep(i,1,tot)++deg[to[i]];
		rep(i,1,ps)if(!deg[i])q[qr++]=i;
		while(ql!=qr){
			int k=q[ql++];
			if(a[k]==0)a[k]=low[k];
			else if(low[k]>a[k])return 0;
			for(int p=head[k];p;p=next[p]){
				up(low[to[p]],a[k]+len[p]);
				if(--deg[to[p]]==0)q[qr++]=to[p];
			}
		}
		return qr==ps;
	}
}G;
#define ls son[k][0]
#define rs son[k][1]
struct SGT{
	int son[P][2];
	void build(int&k,int l,int r){
		if(l==r){k=l;return;}
		k=++ps;
		int m=(l+r)>>1;
		build(ls,l,m);
		build(rs,m+1,r);
		G.ins(ls,k,0);
		G.ins(rs,k,0);
	}
	void ins(int p,int ll,int rr,int k,int l,int r){
		if(ll>rr)return;
		if(ll<=l&&r<=rr)return G.ins(k,p,0);
		int m=(l+r)>>1;
		if(ll<=m)ins(p,ll,rr,ls,l,m);
		if(rr>m)ins(p,ll,rr,rs,m+1,r);
	}
}T;
int main(){
	scanf("%d%d%d",&n,&s,&m);
	ps=n;
	while(s--){
		int p,d;scanf("%d%d",&p,&d);
		a[p]=d;
	}
	T.build(rt,1,n);
	while(m--){
		int l,r,k;scanf("%d%d%d",&l,&r,&k);
		static int x[N];
		x[0]=l-1;x[k+1]=r+1;
		rep(i,1,k)scanf("%d",&x[i]);
		++ps;
		rep(i,1,k)G.ins(ps,x[i],1);
		rep(i,1,k+1)T.ins(ps,x[i-1]+1,x[i]-1,rt,1,n);
	}
	a[++ps]=inf;
	rep(i,1,ps-1)G.ins(i,ps,0);
	rep(i,1,ps)low[i]=1;
	if(G.topsort()){
		puts("TAK");
		rep(i,1,n)printf("%d ",a[i]);
	}else puts("NIE");
	return 0;
}
