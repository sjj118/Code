#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=400,M=N*N;
int n,l;
inline int abs(int x){return x<0?-x:x;}
struct Point{
	int x,y;
	Point(){}
	Point(int x,int y):x(x),y(y){}
}p[N];
int dis(const Point a,const Point&b){return abs(a.x-b.x)+abs(a.y-b.y);}
struct Graph{
	int tot,head[N],to[M],next[M];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int mat[N],v[N],clo,vis[N],nxt[N],pa[N],q[N],ql,qr;
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);};
	int lca(int a,int b){
		for(++clo;v[a]!=clo;swap(a,b))if(a)v[a]=clo,a=find(nxt[mat[a]]);
		return a;
	}
	void blossom(int a,int b,int f){
		while(find(a)!=f){
			nxt[a]=b;b=mat[a];
			if(vis[b]==2)vis[q[qr++]=b]=1;
			pa[a]=pa[b]=f;a=nxt[b];
		}
	}
	bool match(int s){
		cls(vis);rep(i,1,n)pa[i]=i;
		ql=qr=0;q[qr++]=s;vis[s]=1;
		while(ql!=qr){
			int k=q[ql++];
			for(int p=head[k];p;p=next[p]){
				int g=to[p];
				if(vis[g]==0){
					nxt[g]=k;vis[g]=2;
					if(!mat[g]){for(int lst;k;k=nxt[g=lst])lst=mat[k],mat[k]=g,mat[g]=k;return 1;}
					vis[q[qr++]=mat[g]]=1;
				}
				if(vis[g]==1&&find(k)!=find(g)){
					int f=lca(find(g),find(k));
					blossom(g,k,f);blossom(k,g,f);
				}
			}
		}
		return 0;
	}
	void clear(){tot=0;cls(head);cls(mat);}
}G;
int main(){
	while(scanf("%d",&n)>=0){
		rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y);
		scanf("%d",&l);
		G.clear();
		rep(i,1,n)rep(j,i+1,n)if(dis(p[i],p[j])<=l)G.addedge(i,j);
		int ans=0;
		rep(i,1,n)if(!G.mat[i]&&G.match(i))++ans;
		if(ans*2==n)puts("YES");else puts("NO");
	}
	return 0;
}
