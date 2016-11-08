#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=250+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,K,a[N][N],b[N],tmp[N],vis[N],ans=inf;
bool cmp(int a,int b){return a>b;}
void dfs(int k){
	if(k==n+1){
		rep(i,1,n)tmp[i]=b[i];
		sort(tmp+1,tmp+1+n,cmp);
		dn(ans,tmp[K]);
		return;
	}
	rep(i,1,m)if(!vis[i])vis[i]=1,b[k]=a[k][i],dfs(k+1),vis[i]=0;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
	dfs(1);
	printf("%d",ans);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
