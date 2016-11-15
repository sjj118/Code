#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000+10,mo=1e9+7;
int n,m,w[N][N],g[N],ans;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);w[u][v]=w[v][u]=1;}
	g[0]=1;
	rep(i,1,n){
		int last=0;
		per(j,i-1,1)if(!w[i][j]&&(last==0||w[j][last]))last=j,(g[i]+=g[j])%=mo;
		if(last==0)++g[i];
		bool flag=0;
		rep(j,i+1,n)if(!w[i][j])flag=1;
		if(!flag)(ans+=g[i])%=mo;
	}
	printf("%d",ans);
	return 0;
}
