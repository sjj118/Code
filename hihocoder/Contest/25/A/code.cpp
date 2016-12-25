#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=3000+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,f[N],g[N],deg[N];
int main(){
	scanf("%d",&n);
	rep(i,2,n)scanf("%d",&f[i]),++deg[f[i]];
	rep(i,2,n)g[i]=inf;
	rep(i,1,n){
		per(j,n-deg[i],1)dn(g[j+deg[i]],g[j]+1);
	}
	rep(i,1,n)printf("%d ",g[i]==inf?-1:g[i]);
	return 0;
}
