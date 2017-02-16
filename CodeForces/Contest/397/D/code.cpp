#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
const int N=1e5+10;
int n,m,f[N],h[N],g[N],v[N],who[N];
bool solve(){
	rep(i,1,n)if(f[i]==i)++m,who[h[m]=i]=m;
	int t=0;
	rep(i,1,n){
		if(!v[f[i]])++t;
		v[f[i]]=1;
	}
	if(t>m)return 0;
	rep(i,1,n)g[i]=who[f[i]];
	return 1;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&f[i]);
	if(solve()){
		printf("%d\n",m);
		rep(i,1,n)printf("%d ",g[i]);puts("");
		rep(i,1,m)printf("%d ",h[i]);
	}else puts("-1");
	return 0;
}
