#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace brute{
	
const int N=1e5+10;
int n,a[N],fir,sec;
void dfs(int k,int d){
	if(k==n+1){
		if(d>fir)sec=fir,fir=d;
		if(d<fir&&d>sec)sec=d;
		return;
	}
	dfs(k+1,d);dfs(k+1,d^a[k]);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	dfs(1,0);
	printf("%d %d",fir,sec);
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return brute::main();
}
