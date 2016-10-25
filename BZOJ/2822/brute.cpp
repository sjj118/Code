#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace Brute{
	
const int N=500+10;
int n,vis[N][N],ans;
void dfs(int k,int x,int y){
	if(k==n+1&&x==n&&y==n+1){
		++ans;
		return;
	}
	if(y==x+1)return dfs(k,x+1,1);
	if(vis[x][y])return dfs(k,x,y+1);
	if(k>n||x>n||y>n)return;
	rep(i,x,n)rep(j,y,x){
		bool flag=0;
		rep(p,x,i)rep(q,y,j)if(vis[p][q])flag=1;
		if(!flag){
			rep(p,x,i)rep(q,y,j)vis[p][q]=1;
			dfs(k+1,x,y+1);
			rep(p,x,i)rep(q,y,j)vis[p][q]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	dfs(1,1,1);
	printf("%d",ans);
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return Brute::main();
}
