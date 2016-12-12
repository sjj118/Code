#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118_brute{
	
const int N=1e5+10;
int n,k;
int a[N][6];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)rep(j,0,5)scanf("%d",&a[i][j]);
	int ans=0;
	rep(i,1,n)rep(j,i+1,n){
		int cnt=0;
		rep(k,0,5)cnt+=a[i][k]==a[j][k];
		ans+=cnt==k;
	}
	printf("%d",ans);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118_brute::main();
}
