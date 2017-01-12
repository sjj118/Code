#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,inf=1e9;
int n,a[N],f[N],g[N],ans[N];
int main(){
	freopen("code.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&ans[i]);
	fclose(stdin);
	freopen("code.out","r",stdin);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)g[i]=inf;
	rep(i,1,n){
		int t=upper_bound(g,g+n,a[i])-g;
		f[i]=t;
		g[t]=a[i];
	}
	rep(i,1,n)if(f[i]!=ans[i])return 1;
	return 0;
}
