#include<iostream>
#include<cstdio>
#include<assert.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1000+10,M=10000+10;
const LL inf=1e18;
int n,m;
LL a[M][N];
void pivot(int x,int y){
	rep(i,0,m)if(i!=y)a[x][i]/=a[x][y];a[x][y]=1/a[x][y];
	static int q[M],qr;
	qr=0;
	rep(i,0,m)if(i!=y&&a[x][i])q[++qr]=i;
	rep(i,0,n)if(i!=x&&a[i][y]){
		rep(j,1,qr)a[i][q[j]]-=a[i][y]*a[x][q[j]];a[i][y]=-a[i][y]*a[x][y];
	}
}
void simplex(){
	while(1){
		int x=0,y=0;LL mn=inf;
		rep(i,1,m)if(a[0][i]>0)y=i;if(!y)break;
		rep(i,1,n)if(a[i][y]>0&&a[i][0]/a[i][y]<mn)x=i,mn=a[i][0]/a[i][y];assert(x);
		pivot(x,y);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lld",&a[0][i]);
	rep(i,1,m){
		int k;scanf("%d",&k);
		while(k--){
			int l,r;scanf("%d%d",&l,&r);
			rep(j,l,r)a[i][j]=1;
		}
		int c;scanf("%d",&c);
		a[i][0]=c;
	}
	swap(n,m);
	simplex();
	printf("%lld",-a[0][0]);
	return 0;
}
