#include<iostream>
#include<cstdio>
#include<assert.h>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000+10,M=10000+10,inf=1e9;
inline int mul(int a,int b){
	if(a==0||b==0)return 0;
	if(a==b)return 1;
	return -1;
}
int n,m;
int a[N][M];
void pivot(int x,int y){
	rep(i,0,m)if(i!=y)a[x][i]/=a[x][y];a[x][y]=1/a[x][y];
	rep(i,0,n)if(i!=x&&a[i][y]){
		rep(j,0,m)if(j!=y)a[i][j]-=a[x][j]*a[i][y];a[i][y]=-a[i][y]*a[x][y];
	}
}
void simplex(){
	while(1){
		int x=0,y=0;int mn=inf;
		rep(i,1,m)if(a[0][i]>0)y=i;if(!y)break;
		rep(i,1,n)if(a[i][y]>0&&a[i][0]/a[i][y]<mn)mn=a[i][0]/a[i][y],x=i;assert(x);
		pivot(x,y);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i][0]);
	rep(i,1,m){
		int l,r,d;scanf("%d%d%d",&l,&r,&d);
		a[0][i]=d;
		rep(j,l,r)a[j][i]=1;
	}
	simplex();
	printf("%d",(int)(-a[0][0]+0.5));
	return 0;
}
