#include<iostream>
#include<cstdio>
#define maxn 1005

using namespace std;

int n,e,c,m;
struct Graph{
	int tot;
	int head[maxn],to[maxn],next[maxn];
	void addedge(int a,int b){
		to[++tot]=b;
		next[tot]=head[a];
		head[a]=tot;
	}
} G;

double getP(int u,int v){
	
} 

int main(){
	scanf("%d%d",&n,&e);
	scanf("%d%d",&c,&m);
	for(int i=0;i<e;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		G.addedge(a,b);
		G.addedge(b,a);
	}
	printf("%ld",getP(c,m));
	return 0;
}
