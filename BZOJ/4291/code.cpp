#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e6+10,inf=1e9+1;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,ans;
int main(){
	scanf("%d",&n);
	int t=0,mn=inf;
	rep(i,1,n){
		int x;scanf("%d",&x);
		ans+=x;
		if(x&1)t^=1,dn(mn,x);
	}
	if(t)ans-=mn;
	if(ans==0)puts("NIESTETY");
	else printf("%d",ans);
	return 0;
}
