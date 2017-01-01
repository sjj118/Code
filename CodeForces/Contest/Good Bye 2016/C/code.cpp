#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define cls(a) memset(a,0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int inf=1e9,N=200000+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,change,l=-inf,r=inf,d[N],c[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&c[i],&d[i]);
	if(d[1]==1)l=1900;else r=1899;
	rep(i,1,n-1){
		change+=c[i];
		if(d[i+1]==1)up(l,1900-change);
		if(d[i+1]==2)dn(r,1899-change);
	}
	change+=c[n];
	if(l>r)puts("Impossible");
	else if(r==inf)puts("Infinity");
	else printf("%d",r+change);
	return 0;
}
