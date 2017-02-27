#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10;
int n,m;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n-1){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	while(m--){
		char op;scanf("\n%c",&op);
		if(op=='+'){
			int u,v,w;scanf("%d%d%d",&u,&v,&w);
		}else{
			int t;scanf("%d",&t)
		}
	}
	return 0;
}
