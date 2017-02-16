#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::min;
using std::sort;
const int N=2000+10,inf=2e9+7;
inline void up(int&x,int y){if(y>x)x=y;}
int n,f[N][N];
struct SSS{
	int a,b;
}p[N];
bool cmp(const SSS&a,const SSS&b){return a.a>b.a;}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&p[i].a,&p[i].b);
	sort(p+1,p+1+n,cmp);
	rep(i,0,n)rep(j,0,n)f[i][j]=-inf;
	f[0][1]=0;
	int ans=0;
	rep(i,1,n){
		rep(j,1,n){
			up(f[i][min(j+p[i].a-1,n)],f[i-1][j]+p[i].b);
			up(f[i][j],f[i-1][j]);
		}
	}
	rep(i,1,n)rep(j,0,n)up(ans,f[i][j]);
	printf("%d",ans);
	return 0;
}
