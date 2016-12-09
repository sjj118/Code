#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
const int N=1e5+10,M=2e5+10;
int n,m,t;
struct Edge{
	int u,v,s,t;
}e[M];
struct Graph{
	int tot,head[N],to[M<<1],next[M<<1],color[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void clear(){tot=0;cls(head);rep(i,1,n)color[i]=-1;}
	bool dfs(int k){
		for(int p=head[k];p;p=next[p]){
			if(color[to[p]]==-1){
				color[to[p]]=color[k]^1;
				if(!dfs(to[p]))return 0;
			}else if(color[to[p]]==color[k])return 0;
		}
		return 1;
	}
}G;
int main(){
	scanf("%d%d%d",&n,&m,&t);
	rep(i,1,m)scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].s,&e[i].t);
	rep(i,1,t){
		G.clear();
		rep(j,1,m)if(e[j].s<i&&e[j].t>=i)G.addedge(e[j].u,e[j].v);
		bool flag=1;
		rep(j,1,n)if(G.color[j]==-1)G.color[j]=0,flag&=G.dfs(j);
		if(flag)puts("Yes");else puts("No");
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
