#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=50+10,M=800+10,inf=1e9;
int n,m,id[N][N],tree[M];
struct Edge{
	int u,v,l;
}e[M];
int w[M][M],lx[M],ly[M],vy[M],match[M],slk[M],nl,nr,nid[M],prev[M];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	bool dfs(int k,int tar,int pre,int q,int w1){
		if(k==tar)return 1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			if(dfs(to[p],tar,k,q,w1)){
				int x=id[k][to[p]];
				w[nid[x]][q]=max(0,e[x].l-w1);
				return 1;
			}
		}
		return 0;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d",&e[i].u,&e[i].v);
		id[e[i].u][e[i].v]=id[e[i].v][e[i].u]=i;
		scanf("%d",&e[i].l);
	}
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);tree[id[u][v]]=1;}
	rep(i,1,m){
		if(tree[i]){
			nid[i]=++nl;
		}else{
			nid[i]=++nr;
		}
	}
	rep(i,1,m){
		if(!tree[i]){
			G.dfs(e[i].u,e[i].v,0,nid[i],e[i].l);
		}
	}
	if(nl>nr){
		rep(i,1,nl)rep(j,1,i)swap(w[i][j],w[j][i]);
		swap(nl,nr);
	}
	rep(i,1,nl){
		cls(vy);rep(y,1,nr)slk[y]=inf;
		int py=0;
		match[py]=i;
		while(match[py]){
			vy[py]=1;
			int x=match[py],yy,d=inf;
			rep(y,1,nr)if(!vy[y]){
				if(lx[x]+ly[y]-w[x][y]<slk[y])slk[y]=lx[x]+ly[y]-w[x][y],prev[y]=py;
				if(slk[y]<d)d=slk[y],yy=y;
			}
			rep(y,0,nr)if(vy[y])ly[y]+=d,lx[match[y]]-=d;else slk[y]-=d;
			py=yy;
		}
		while(py){
			match[py]=match[prev[py]];
			py=prev[py];
		}
	}
	int sum=0;
	rep(i,1,nl)sum+=lx[i];
	rep(i,1,nr)sum+=ly[i];
	printf("%d",sum);
	return 0;
}
