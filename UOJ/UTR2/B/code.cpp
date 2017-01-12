#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=400+10,mo=998244353,inf=1e9+7;
inline void dn(int&x,int y){if(y<x)x=y;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
int n,k,w[N][N],d[N][N],f[N][N],nid[N],tot,size[N];
LL g[N],h[N],C[N][N];
void dfs(int k){
	nid[k]=tot;++size[tot];
	rep(i,1,n)if(d[k][i]==0&&!nid[i])dfs(i);
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)rep(j,1,n)scanf("%d",&d[i][j]);
	rep(i,1,n)h[i]=power(k+1,i*(i-1)/2,mo);
	rep(i,0,n){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	g[1]=1;rep(i,2,n){
		g[i]=h[i];
		rep(j,1,i-1)g[i]=(mo+g[i]-g[j]*h[i-j]%mo*C[i-1][j-1]%mo*power(k,j*(i-j),mo)%mo)%mo;
	}
	LL ans=1;
	rep(i,1,n)rep(j,1,n)if(d[i][j]!=d[j][i])ans=0;
	rep(i,1,n)if(!nid[i])++tot,dfs(i);
	rep(i,1,tot)ans=(ans*g[size[i]])%mo;
	rep(i,1,n)rep(j,1,n){
		if(nid[i]==nid[j]&&d[i][j])ans=0;
		if(nid[i]!=nid[j]){
			if(w[nid[i]][nid[j]]==0)w[nid[i]][nid[j]]=d[i][j];
			else if(w[nid[i]][nid[j]]!=d[i][j])ans=0;
		}
	}
	n=tot;
	rep(i,1,n)rep(j,1,n)d[i][j]=w[i][j];
	rep(i,1,n)rep(j,1,n)f[i][j]=inf;
	rep(k,1,n)rep(i,1,n)rep(j,1,n)if(k!=i&&k!=j)dn(f[i][j],min(f[i][k],d[i][k])+min(f[k][j],d[k][j]));
	rep(i,1,n)rep(j,i+1,n){
		if(f[i][j]<d[i][j])ans=0;
		if(f[i][j]==d[i][j]){
			if(f[i][j]<=k)(ans*=power(k-f[i][j]+1,size[i]*size[j],mo))%=mo;
			else ans=0;
		}
		if(f[i][j]>d[i][j]){
			if(d[i][j]>k)ans=0;
			else (ans*=(mo+power(k-d[i][j]+1,size[i]*size[j],mo)-power(k-d[i][j],size[i]*size[j],mo)))%=mo;
		}
	}
	printf("%lld",ans);
	return 0;
}
