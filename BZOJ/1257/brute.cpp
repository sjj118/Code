#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
LL n,k;
int main(){
	cin>>n>>k;
	LL ans=0;
	rep(i,1,n)ans+=k%i;
	cout<<ans;
	return 0;
}
