#include<cstdio>
#include<algorithm>
#include "gap.h"
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const LL inf=1e18;
const int N=1e5+10;
inline void up(LL&x,LL y){if(y>x)x=y;}
LL a[N];
LL findGap(int t,int n){
	if(t==1){
		int p=0;
		LL l=0,r=inf;
		while(p<n-p){
			LL mn,mx;
			MinMax(l,r,&mn,&mx);
			a[n-p]=mx;
			if(mn!=mx)a[++p]=mn;else ++p;
			l=mn+1;r=mx-1;
		}
		LL ret=0;
		rep(i,1,n-1)up(ret,a[i+1]-a[i]);
		return ret;
	}
	LL mn,mx;
	MinMax(0,inf,&mn,&mx);
	LL d=(mx-mn)/(n-1)+1;
	int tot=0;
	LL l=mn;
	rep(i,1,n-1){
		MinMax(l,l+d-1,&mn,&mx);
		l+=d;
		if(mn>=0)a[++tot]=mn;
		if(mx>=0&&mx!=mn)a[++tot]=mx;
	}
	LL ret=0;
	rep(i,1,tot-1)up(ret,a[i+1]-a[i]);
	return ret;
}
