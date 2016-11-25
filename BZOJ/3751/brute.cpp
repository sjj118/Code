#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=100+10,M=1e6+10;
int n,m,a[N],ans[M],cnt;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,0,n)scanf("%d",&a[i]);
	rep(i,1,m){
		LL sum=0,x=1;
		rep(j,0,n)sum+=a[j]*x,x=x*i;
		if(sum==0)ans[++cnt]=i;
	}
	printf("%d\n",cnt);
	rep(i,1,cnt)printf("%d\n",ans[i]);
	return 0;
}
