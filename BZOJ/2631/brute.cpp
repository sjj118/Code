#include<iostream>
#include<cstdio>
#define mo 51061
#define maxn 100010

using namespace std;

int n,q;
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1],val[maxn];
	void addedge(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	bool dfs(int k,int tar,int kind,int&c,int pre=0){
		bool flag=0;
		if(k==tar)flag=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)if(dfs(to[p],tar,kind,c,k))flag=1;
		if(flag){
			if(kind==0)val[k]=(val[k]+c)%mo;
			if(kind==1)val[k]=val[k]*c%mo;
			if(kind==2)c=(c+val[k])%mo;
		}
		return flag;
	}
	Graph(){
		for(int i=0;i<maxn;++i)val[i]=1;
	}
}G;

int main(){
	freopen("tree.in","r",stdin);
	freopen("brute.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;++i){
		int u,v;scanf("%d%d",&u,&v);
		G.addedge(u,v);G.addedge(v,u);
	}
	for(int i=1;i<=q;++i){
		char op;scanf("\n%c",&op);
		if(op=='+'){
			int u,v,c;scanf("%d%d%d",&u,&v,&c);
			G.dfs(u,v,0,c);
		}else if(op=='-'){
			int u1,v1,u2,v2;scanf("%d%d%d%d",&u1,&v1,&u2,&v2);
			
		}else if(op=='*'){
			int u,v,c;scanf("%d%d%d",&u,&v,&c);
			G.dfs(u,v,1,c);
		}else{
			int u,v;scanf("%d%d",&u,&v);
			int ans=0;G.dfs(u,v,2,ans);
			printf("%d\n",ans);
		}
	}
	return 0;
}
