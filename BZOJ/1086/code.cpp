#include<iostream>
#include<cstdio>
#define maxn 1010

using namespace std;

int n,b,nn;
int belong[maxn],center[maxn];
int stack[maxn],top;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],tsize[maxn];
	void addedge(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	int dfs(int k,int pre=0){
		stack[top++]=k;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			tsize[k]+=dfs(to[p],k);
			if(tsize[k]>=b){
				center[++nn]=k;
				while(top&&(stack[top-1]!=k))belong[stack[--top]]=nn;
				tsize[k]=0;
			}
		}
		++tsize[k];
		if(tsize[k]>=b){
			center[++nn]=k;
			while(top&&(stack[top]!=k))belong[stack[--top]]=nn;
			tsize[k]=0;
		}
		return tsize[k];
	}
}G;

int main(){
	scanf("%d%d",&n,&b);
	for(int i=1;i<n;++i){
		int x,y;scanf("%d%d",&x,&y);
		G.addedge(x,y);G.addedge(y,x);
	}
	G.dfs(1);
	while(top)belong[stack[--top]]=nn;
	printf("%d\n",nn);
	for(int i=1;i<=n;++i)printf("%d ",belong[i]);printf("\n");
	for(int i=1;i<=nn;++i)printf("%d ",center[i]);
	return 0;
}
