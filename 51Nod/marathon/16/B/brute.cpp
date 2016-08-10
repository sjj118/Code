#include<iostream>
#include<cstdio>
typedef long long LL;
const int mo=1e9+7;
using namespace std;
LL l,r,ans;
LL calc(LL n){
	int len=0,a[20];LL tmp=n,ans=0;
	while(tmp)a[++len]=tmp%10,tmp/=10;
	for(int i=1;i<=len;++i)ans+=a[i]*a[len-i+1];
	return ans;
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%lld%lld",&l,&r);
	for(LL i=l;i<=r;++i)ans=(ans+calc(i))%mo;
	printf("%lld\n",ans);
	return 0;
}
