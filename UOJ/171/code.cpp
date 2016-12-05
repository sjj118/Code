#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int M=100+10,N=3*M,E=N*M,P=N+3*M,V=2*(3*M+3*E);
int n,m,e,ps;
struct Graph{
	int tot,head[P],to[V],next[V];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int mat[P],q[P],ql,qr,v[P],vis[P],clo,pa[P],nxt[P];
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
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
		rep(i,1,ps)pa[i]=i;
		cls(vis);cls(nxt);vis[s]=1;ql=qr=0;
		q[qr++]=s;
		while(ql!=qr){
			int k=q[ql++];
			for(int p=head[k];p;p=next[p]){
				int g=to[p];
				if(vis[g]==0){
					nxt[g]=k;vis[g]=2;
					if(!mat[g]){
						for(int lst;k;k=nxt[g=lst])lst=mat[k],mat[k]=g,mat[g]=k;
						return 1;
					}
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
	void clear(){
		tot=0;cls(head);
		cls(mat);
	}
}G;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&e);ps=n+m*3;
		G.clear();
		rep(i,1,e){
			int u,v;scanf("%d%d",&u,&v);
			G.addedge(u,n+3*v-2);G.addedge(u,n+3*v-1);G.addedge(u,n+3*v);
		}
		rep(i,1,m)G.addedge(n+i*3-2,n+i*3-1),G.addedge(n+i*3-2,n+i*3),G.addedge(n+i*3-1,n+i*3);
		int ans=-n;
		rep(i,1,ps)if(!G.mat[i]&&G.match(i))++ans;
		printf("%d\n",ans);
		rep(i,1,n)printf("%d ",(G.mat[i]-n+2)/3);puts("");
	}
	return 0;
}
