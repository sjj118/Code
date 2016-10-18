#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=2e5+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,k,a[maxn],ans;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(l,1,n){
		int s=inf;
		rep(r,l+1,n){
			rep(i,l,r-1)dn(s,abs(a[r]-a[i]));
			if(r-l+1>=k)up(ans,s*(r-l));
		}
	}
	printf("%d",ans);
	return 0;
}
