#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=300+10,M=N*N+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m;
int a[N];
struct Friend{
	int x,y;
}fri[M];
int b[N];
int ans=inf;
void dfs(int k){
	if(k==n+1){
		int ret=0;
		rep(i,1,n)ret+=b[i];
		rep(i,1,m)ret+=((a[fri[i].x]^b[fri[i].x])!=(a[fri[i].y]^b[fri[i].y]));
		dn(ans,ret);
		return;
	}
	b[k]=0;dfs(k+1);
	b[k]=1;dfs(k+1);
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d%d",&fri[i].x,&fri[i].y);
	dfs(1);
	printf("%d",ans);
	return 0;
}
