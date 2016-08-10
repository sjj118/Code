#include<iostream>
#include<cstdio>
#define maxn 300000
#define lowbit(x) (x)&(-(x))

using namespace std;

int n,m;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],in[maxn],out[maxn],depth[maxn],sign;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		in[k]=++sign;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			depth[to[p]]=depth[k]+1;
			dfs(to[p],k);
		}
		out[k]=++sign;
	}
}G;
struct Bit{
	int arr[maxn<<1];
	void add(int x,int t){
		while(x<=G.sign)arr[x]+=t,x+=lowbit(x);
	}
	int sum(int x){
		int ans=0;
		while(x)ans+=arr[x],x-=lowbit(x);
		return ans;
	}
}bit;

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int u,v;scanf("%d%d",&u,&v);
		G.addedge(u,v);
	}
	G.dfs(1,0);
	scanf("%d",&m);
	for(int i=1;i<n+m;++i){
		char op;scanf("\n%c",&op);
		if(op=='A'){
			int a,b;scanf("%d%d",&a,&b);
			if(G.depth[a]<G.depth[b])swap(a,b);
			bit.add(G.in[a],1);bit.add(G.out[a],-1);
		}else{
			int a;scanf("%d",&a);
			printf("%d\n",G.depth[a]-bit.sum(G.in[a]));
		}
	}
	return 0;
}
