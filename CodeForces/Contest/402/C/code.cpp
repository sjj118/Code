#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=3e5+10;
int n,num[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b,char c){ins(a,b,c);ins(b,a,c);}
	void dfs(int k,int pre,int dep){
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p]);
		static int a[N];
		int cnt=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)a[++cnt]=to[p];

	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int a,b;char c;scanf("%d%d %c",a,b,c),G.addedge(a,b,c);}
	G.dfs(1,0,1);
	return 0;
}
