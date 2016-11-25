#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10;
template<class T>inline T abs(T x){return x>0?x:-x;}
int n,a[N];
LL x,y;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	per(i,n,2)a[i]-=a[i-1];
	rep(i,2,n)if(a[i]>0)x+=a[i];else y-=a[i];
	LL ans1=min(x,y)+abs(x-y);
	printf("%lld\n",ans1);
	LL ans2=abs(x-y)+1;
	printf("%lld",ans2);
	return 0;
}
