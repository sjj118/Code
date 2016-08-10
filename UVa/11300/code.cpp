#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1000010
#define ll long long

using namespace std;

int n;
ll a[maxn],c[maxn];

int main(){
	while(scanf("%d",&n)>0){
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		ll m=0,ans=0;
		for(int i=0;i<n;++i)m+=a[i];
		m/=n;
		c[0]=0;
		for(int i=1;i<n;++i)c[i]=c[i-1]+a[i]-m;
		sort(c,c+n);
		ll x=c[n>>1];
		for(int i=0;i<n;++i)ans+=abs(x-c[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
