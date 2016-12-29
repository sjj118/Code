#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e4+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,q,a[N],b[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	scanf("%d",&q);
	int ans=0;
	while(q--){
		int x[4];rep(i,0,3)scanf("%d",&x[i]),x[i]=(ans+x[i])%n+1;
		sort(x,x+4);
		ans=0;
		rep(l,x[0],x[1])rep(r,x[2],x[3]){
			rep(i,l,r)b[i-l]=a[i];
			sort(b,b+r-l+1);
			up(ans,b[(r-l+1)/2]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
