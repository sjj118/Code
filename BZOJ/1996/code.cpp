#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1000+10,mo=19650827;
int n,h[N];
bool vis[N][N][2];
LL f[N][N][2];
LL calc(LL l,LL r,int x){
	if(vis[l][r][x])return f[l][r][x];
	if(l==r)return x;
	vis[l][r][x]=1;
	if(x==0){
		if(h[l]<h[l+1])(f[l][r][x]+=calc(l+1,r,0))%=mo;
		if(h[l]<h[r])(f[l][r][x]+=calc(l+1,r,1))%=mo;
	}else{
		if(h[r]>h[l])(f[l][r][x]+=calc(l,r-1,0))%=mo;
		if(h[r]>h[r-1])(f[l][r][x]+=calc(l,r-1,1))%=mo;
	}
	return f[l][r][x];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&h[i]);
	printf("%lld",(calc(1,n,0)+calc(1,n,1))%mo);
	return 0;
}
