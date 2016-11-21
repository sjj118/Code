#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000+10;
int n,m,w[N][N],ans;
bool sel[N];
void dfs(int k){
	if(k==n+1){
		rep(i,1,n)if(sel[i])rep(j,i+1,n)if(sel[j])if(w[i][j])return;
		rep(i,1,n)if(!sel[i]){bool flag=1;rep(j,1,n)if(sel[j]&&w[i][j])flag=0;if(flag)return;}
		++ans;
		return;
	}
	sel[k]=0;dfs(k+1);
	sel[k]=1;dfs(k+1);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);w[u][v]=w[v][u]=1;}
	dfs(1);
	printf("%d",ans);
	return 0;
}
