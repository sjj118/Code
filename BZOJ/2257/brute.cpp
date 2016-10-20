#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1000+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,k,a[maxn],ans;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void dfs(int p,int last,int d){
	if(p==k+1)return up(ans,d);
	rep(i,last+1,n-k+p)dfs(p+1,i,gcd(d,a[i]));
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
