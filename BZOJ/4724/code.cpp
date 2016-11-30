#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e6+10;
typedef long long LL;
int q;
LL a[N],b,s[N];
int main(){
	scanf("%lld%d",&b,&q);
	LL sum=0;
	rep(i,0,b-1)scanf("%lld",&a[i]),(sum+=a[i]*i)%=(b-1);
	if(sum)--a[sum];
	s[0]=a[0];rep(i,1,b-1)s[i]=s[i-1]+a[i];
	rep(i,1,q){
		LL k;scanf("%lld",&k);
		if(k>=s[b-1])puts("-1");
		else printf("%d\n",lower_bound(s,s+b,k+1)-s);
	}
	return 0;
}
