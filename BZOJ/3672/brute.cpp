#include<iostream>
#include<cstdio>
#define maxn 200009
#define inf (1e9)

using namespace std;

int n,dp[maxn];
struct graph{
	int tot,pa[maxn],head[maxn],to[maxn<<1],next[maxn<<1],s[maxn],l[maxn],p[maxn],q[maxn];
	void addson(int a,int b){
		to[++tot]=b;
		next[tot]=head[a];
		head[a]=tot;
		pa[b]=a;
	}
	void dfs(int k,int pre=0){
		if(pre){
			dp[k]=inf;
			for(int len=s[k],f=pa[k];f&&len<=l[k];len+=s[f],f=pa[f])dp[k]=min(dp[k],dp[f]+len*p[k]+q[k]);
		}
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			dfs(to[p],k);
		}
	}
} G;

int main(){
	freopen("code.in","r",stdin);
	freopen("brute.out","w",stdout); 
	int t;
	scanf("%d%d",&n,&t);
	for(int i=2;i<=n;++i){
		int f,s,p,q,l;
		scanf("%d%d%d%d%d",&f,&s,&p,&q,&l);
		G.addson(f,i);
		G.p[i]=p;G.q[i]=q;G.l[i]=l;G.s[i]=s;
	}
	G.dfs(1);
	for(int i=2;i<=n;++i)printf("%d\n",dp[i]);
	return 0;
}
