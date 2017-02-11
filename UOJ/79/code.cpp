#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
const int N=500+10,M=124750*2+10;
int n,m;
struct Graph{
	int tot,head[N],to[M],next[M];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int mat[N],nxt[N],v[N],vis[N],pa[N];
	int find(int k){return k==pa[k]?k:pa[k]=find(pa[k]);}
	int lca(int a,int b){
	}
	void blossom(int a,int b,int f){
	}
	bool match(int s){
		cls(vis);vis[s]=1;
		rep(i,1,n)pa[i]=i;
		static int q[N];
		int ql=0,qr=0;
		q[qr++]=s;
		while(ql!=qr){int k=q[ql++];
			for(int p=head[k];p;p=next[p]){int g=to[p];
				if(vis[g]==0){
				}
				if(vis[g]==1&&find(g)!=find(k)){
					int f=lca(find(g),find(k));
					blossom(k,g,f);blossom(g,k,f);
				}
			}
		}
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);
	}
	int ans=0;
	rep(i,1,n)ans+=!G.mat[i]&&G.match(i);
	printf("%d\n",ans);
	rep(i,1,n)printf("%d ",G.mat[i]);
	return 0;
}
