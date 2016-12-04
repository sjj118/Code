#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000+10,M=250000+10;
int nl,nr,m,vis[N],match[N],ans,_match[N];
struct Graph{
	int tot,head[N],to[M],next[M];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	bool findMatch(int k){
		for(int p=head[k];p;p=next[p])if(!vis[to[p]]){
			vis[to[p]]=1;
			if(!match[to[p]]||findMatch(match[to[p]]))return match[to[p]]=k,1;
		}
		return 0;
	}
}G;
int main(){
	scanf("%d%d%d",&nl,&nr,&m);
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);G.ins(u,v);}
	rep(i,1,nl){
		cls(vis);
		if(G.findMatch(i))++ans;
	}
	rep(i,1,nr)_match[match[i]]=i;
	printf("%d\n",ans);
	rep(i,1,nl)printf("%d ",_match[i]);
	return 0;
}
