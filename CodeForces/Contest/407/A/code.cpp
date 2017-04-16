#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::cin;
using std::cout;
typedef long long LL;
const LL inf=1e18;
const int N=1e5+10;
inline void up(LL&x,LL y){if(y>x)x=y;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
inline LL abs(LL x){return x>0?x:-x;}
LL a[N],s[N];
int n;
int main(){
	scanf("%d",&n);
	rep(i,1,n)cin>>a[i];
	rep(i,1,n-1){
		if(i&1)s[i]=s[i-1]+abs(a[i]-a[i+1]);
		else s[i]=s[i-1]-abs(a[i]-a[i+1]);
	}
	LL mx=s[n-1],mn=s[n-1];
	LL ans=0;
	per(i,n-2,0){
		if((i&1)==0)up(ans,mx-s[i]);
		else up(ans,s[i]-mn);
		up(mx,s[i]);
		dn(mn,s[i]);
	}
	cout<<ans;
	return 0;
}
