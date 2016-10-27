#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace brute{
	
const int MO=1e9+7;
int n,k,l,r,ans;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void dfs(int p,int d){
	if(p==n+1){
		if(d==k)++ans;return;
	}
	rep(i,l,r)dfs(p+1,gcd(d,i));
}
int main(){
	scanf("%d%d%d%d",&n,&k,&l,&r);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return brute::main();
}
