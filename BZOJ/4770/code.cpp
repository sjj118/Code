#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const int N=50+10,M=8+2,mo=258280327,V=(1<<8)+10;
int n,m,v;
LL f[M][V][N][N];
int main(){
	scanf("%d%d",&n,&m);v=1<<m;
	rep(i,1,n)rep(j,1,n-i)f[0][0][i][j]=1;
	rep(i,1,m-1){
		rep(a,1,n)rep(b,1,n-a){
		}
	}
	return 0;
}
