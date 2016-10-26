#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;

namespace sjj118{
	
const int N=1000+10;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,a[N][N],ans;
void dfs(int k,int x,int y){
	if(k>ans)return;
	if(x==0&&y==0){
		rep(i,1,n)rep(j,1,m)if(a[i][j]){dfs(k+1,i,j);return;}
		dn(ans,k);return;
	}
	--a[x][y];
	rep(i,x,n)rep(j,y,m)if(i!=x||j!=y)if(a[i][j])dfs(k,i,j);
	dfs(k,0,0);
	++a[x][y];
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);ans=N;
		rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
		dfs(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}

