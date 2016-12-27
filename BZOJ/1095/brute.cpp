#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,on[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre,int l,int&ans){
		if(!on[k])up(ans,l);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k,l+1,ans);
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	scanf("%d",&m);
	while(m--){
		char op;scanf("\n%c",&op);
		if(op=='G'){
			int ans=-1;
			rep(i,1,n)if(!on[i])G.dfs(i,0,0,ans);
			printf("%d\n",ans);
		}else{
			int x;scanf("%d",&x);
			on[x]^=1;
		}
	}
	return 0;
}
