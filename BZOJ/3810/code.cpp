#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=300+10,inf=1e9;
typedef long long LL;
int n,m,k;
inline void dn(LL&x,LL y){if(y<x)x=y;}
LL sqr(LL x){return x*x;}
LL f[maxn][maxn][16];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)rep(j,1,m)rep(v,0,15){
		if(v==15)f[i][j][v]=inf;
		else f[i][j][v]=sqr(i*j-k);
		rep(p,1,i-1)dn(f[i][j][v],f[p][j][v|2]+f[i-p][j][v|1]);
		rep(p,1,j-1)dn(f[i][j][v],f[i][p][v|8]+f[i][j-p][v|4]);
	}
	printf("%lld",f[n][m][0]);
	return 0;
}
