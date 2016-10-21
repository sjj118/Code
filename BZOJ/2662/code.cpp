#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=50+5,M=1000+10,P=N*N+10,V=M*N*4+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,k,m,p;
struct Graph{
	int tot,head[P],to[V],next[V],len[V],dis[P],vis[P];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	void Dijkstra(int s){
		rep(i,1,p)dis[i]=inf;dis[s]=0;
		while(1){
			int k=0;
			rep(i,1,p)if(!vis[i]&&(k==0||dis[i]<dis[k]))k=i;
			if(k==0)break;
			vis[k]=1;
			for(int p=head[k];p;p=next[p])dn(dis[to[p]],dis[k]+len[p]);
		}
	}
}G;
inline int cw(int x,int y){return (x-1)*(k+1)+y+1;}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	p=cw(n,k);
	rep(i,1,m){
		int a,b,w;scanf("%d%d%d",&a,&b,&w);
		rep(j,0,k-1)G.addedge(cw(a,j),cw(b,j),w),G.ins(cw(a,j),cw(b,j+1),w>>1),G.ins(cw(b,j),cw(a,j+1),w>>1);
		G.addedge(cw(a,k),cw(b,k),w);
	}
	G.Dijkstra(cw(1,0));
	int ans=inf;
	rep(i,0,k)dn(ans,G.dis[cw(n,i)]);
	printf("%d",ans);
	return 0;
}
