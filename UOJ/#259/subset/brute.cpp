#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000;
int n,m,k,p,ans;
int w[N][N],b[N];
void dfs(int x,int last){
	if(x==k+1){
		++ans;
		if(ans==p)ans=0;
		return;
	}
	rep(i,last+1,n-k+x){
		bool flag=0;
		rep(j,1,x-1)if(w[b[j]][i])flag=1;
		if(flag)continue;
		b[x]=i;dfs(x+1,i);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&p);
	rep(i,1,m){int x,y;scanf("%d%d",&x,&y);w[x][y]=w[y][x]=1;}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}

