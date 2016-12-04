#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxm=4e5+10;
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int type,n,m,top,path[maxm];
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],vis[maxm],in[maxn],out[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);++in[b];++out[a];}
	Graph(){tot=1;}
	void dfs(int k){
		for(int&p=head[k];p;p=next[p])if(!vis[p]&&(type==1||(p&1)==0)){
			vis[p]=vis[p^1]=1;int tmp=p;
			dfs(to[p]);
			path[top--]=tmp;
		}
	}
}G;
int main(){
	type=read();
	n=read();m=top=read();
	rep(i,1,m){int u=read(),v=read();G.addedge(u,v);}
	rep(i,1,n)if(type==1&&((G.in[i]+G.out[i])&1)||type==2&&(G.in[i]!=G.out[i])){printf("NO");return 0;}
	G.dfs(G.to[2]);
	if(top){printf("NO");return 0;}
	printf("YES\n");
	rep(i,1,m)if(type==1)printf("%d ",((path[i]&1)?-1:1)*(path[i]/2));else printf("%d ",path[i]/2);
	return 0;
}
