#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::swap;
typedef long long LL;
const int N=3e5+10;
int n,m,type,a[N],rfh[N];
LL query(LL l,LL r){
	LL ret=0;
	rep(i,l,r){
		int p=i+1;
		while(p<=r){
			++ret;
			if(a[p]>=a[i])break;
			p=rfh[p];
		}
	}
	return ret;
}
int main(){
	scanf("%d%d%d",&n,&m,&type);
	rep(i,1,n)scanf("%d",&a[i]);
	per(i,n,1){
		rfh[i]=i+1;
		while(rfh[i]<=n&&a[rfh[i]]<=a[i])rfh[i]=rfh[rfh[i]];
	}
	LL ans=0;
	while(m--){
		int l,r;scanf("%d%d",&l,&r);
		if(type)l=(l+ans-1)%n+1,r=(r+ans-1)%n+1;
		if(l>r)swap(l,r);
		printf("%lld\n",ans=query(l,r));
	}
	return 0;
}
