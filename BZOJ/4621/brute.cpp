#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=10+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,k,a[N],f[N][N][N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,0,n)rep(j,0,n)rep(p,0,k)f[i][j][p]=1;
	rep(l,1,n)rep(r,l,n)rep(p,0,k){
		int maxc=0;
		f[l][r][p]=0;
		rep(i,l,r)if(a[i]>a[maxc])maxc=i;
		rep(q,0,p)f[l][r][p]+=f[l][maxc-1][q]*f[maxc+1][r][p-q];
		rep(i,l,maxc)rep(j,maxc,r)if(i!=j)rep(q,0,p-1)f[l][r][p]+=f[l][i-1][q]*f[j+1][r][p-1-q];
	}
	int ans=0;
	rep(i,0,k)ans+=f[1][n][i];
	printf("%d",ans);
	return 0;
}
