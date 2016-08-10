#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 500010
#define LL double
#define eps 1e-5

using namespace std;

int n,a[maxn];
LL b[maxn];
struct Graph{
	int tot,head[maxn],to[maxn],next[maxn],sons[maxn];
	LL mul[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;++sons[a];}
	void dfs(int k){
		for(int p=head[k];p;p=next[p]){
			mul[to[p]]=mul[k]+log(sons[k]);
			dfs(to[p]);
		}
	}
}G;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<n;++i){
		int a,b;scanf("%d%d",&a,&b);G.ins(a,b);
	}
	G.mul[1]=log(1);
	G.dfs(1);
	for(int i=1;i<=n;++i)b[i]=G.mul[i]+log(a[i]);
	sort(b+1,b+1+n);int tmp=1,ans=1;
	for(int i=1;i<=n;++i){
		if(b[i]-b[i-1]>eps)tmp=1;
		else{
			++tmp;
			ans=max(ans,tmp);
		}
	}
	printf("%d",n-ans);
	return 0;
}
