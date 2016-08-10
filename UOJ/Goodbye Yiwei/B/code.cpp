#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
#define maxm 200010

using namespace std;

int T,n,m;
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],du[maxn],mark[maxn];
	void addedge(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;++du[a];}
	void clear(){tot=0;memset(head,0,sizeof(head));memset(du,0,sizeof(du));memset(mark,0,sizeof(mark));}
	void solve(){
		for(int k=1;k<=n;++k){
			if(du[k]==1){mark[k]=1;continue;}
			for(int p=head[k];p;p=next[p])if(du[to[p]]==1){mark[k]=1;break;}
		}
	}
}G;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		G.clear();
		for(int i=1;i<=m;++i){
			int u,v;scanf("%d%d",&u,&v);
			G.addedge(u,v);G.addedge(v,u);
		}
		G.solve();
		int k=0;
		for(int i=1;i<=n;++i)if(G.mark[i])++k;
		printf("%d\n",k);
		for(int i=1;i<=n;++i)if(G.mark[i])printf("%d ",i);printf("\n");
	}
	return 0;
}
