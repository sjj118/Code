#include<cstdio>
#include<iostream>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int n,fa[N],a[N],dep[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n-1)scanf("%d",&fa[i]);
		rep(i,0,n-1)scanf("%d",&a[i]);
		rep(i,1,n-1)dep[i]=dep[fa[i]]+1;
		int ans=0;
		rep(i,0,n-1)if(dep[i]&1)ans^=a[i];
		if(ans)puts("win");else puts("lose");
	}
	return 0;
}
