#include<iostream>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=50+10,mo=258280327,inf=1e9;
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline LL inv(LL n,LL p){return power(n,p-2,p);}
inline void dn(int&x,int y){if(y<x)x=y;}
LL ans;
int n,m,a[N],w[N][N],dis[N],vis[N];
LL solve(){
	rep(i,1,n)rep(j,1,n)w[i][j]=a[i]^a[j];
	LL ret=0;
	rep(i,1,n)dis[i]=inf,vis[i]=0;
	dis[1]=0;
	while(1){
		int k=0;
		rep(i,1,n)if(!vis[i]&&(k==0||dis[i]<dis[k]))k=i;
		if(!k)break;
		vis[k]=1;
		ret+=dis[k];
		rep(i,1,n)dn(dis[i],w[k][i]);
	}
	return ret;
}
void dfs(int k){
	if(k==n+1){
		ans+=solve();
		return;
	}
	rep(i,0,(1<<m)-1)a[k]=i,dfs(k+1);
}
int main(){
	scanf("%d%d",&n,&m);
	dfs(1);
	printf("%lld",ans*inv(power(1<<m,n,mo),mo)%mo);
	return 0;
}
