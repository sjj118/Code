#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const LL mo=1e10;
int n;
LL ans=0;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		LL tmp=1;
		rep(j,1,i)tmp=tmp*i%mo;
		(ans+=tmp)%=mo;
	}
	printf("%010lld",ans);
	return 0;
}
