#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxm=4e5+10;
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int type,n,m,vt,path[maxm];
struct Graph{
	int tot,head[maxn],cur[maxn],to[maxm],next[maxm],vis[maxm],in[maxn],out[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);++in[b];++out[a];}
	Graph(){tot=1;}
	int checklink(int k){
		int tmp=0;
		for(int&p=cur[k];p;p=next[p])if(!vis[p]){
			vis[p]=vis[p^1]=1;
			tmp+=1+checklink(to[p]);
		}
		return tmp;
	}
	void dfs(int k){
		for(int&p=cur[k];p;p=next[p])if(!vis[p]&&(type==1||(p&1)==0)){
			vis[p]=vis[p^1]=1;int tmp=p;
			dfs(to[p]);
			path[m--]=tmp;
		}
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	type=read();
	n=read();m=vt=read();
	rep(i,1,m){int u=read(),v=read();G.addedge(u,v);}
	bool flag=0;int s=1;
	rep(i,1,n)G.cur[i]=G.head[i];
	rep(i,1,n)if(G.checklink(i)==m)flag=1,s=i;
	if(!flag){puts("NO");return 0;}
	if(type==1){
		rep(i,1,n)if((G.in[i]+G.out[i])&1){puts("NO");return 0;}
	}else{
		rep(i,1,n)if(G.in[i]!=G.out[i]){puts("NO");return 0;}
	}
	rep(i,1,n)G.cur[i]=G.head[i];
	cls(G.vis);
	G.dfs(s);
	puts("YES");
	rep(i,1,vt)if(type==1)printf("%d ",((path[i]&1)?-1:1)*(path[i]/2));else printf("%d ",path[i]/2);
	return 0;
}
