#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int n,m,val[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int dfs(int k,int pre,int l){
		if(l<0)return 0;
		int ret=val[k];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)ret+=dfs(to[p],k,l-1);
		return ret;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&val[i]);
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	while(m--){
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if(op){
			val[x]=y;
		}else{
			printf("%d\n",G.dfs(x,0,y));
		}
	}
	return 0;
}
