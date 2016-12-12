#include "flea.h"
#include<iostream>
#include<queue>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL,int> pli;
const int N=1000+10;
const LL inf=1e18;
inline void up(LL&x,LL y){if(y>x)x=y;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
inline LL f(LL k,LL a,LL b,LL c){return a*k*k+b*k+c;}
int n,m;
struct VFK{
	LL a,b,c;
	VFK(){}
	VFK(LL a,LL b,LL c):a(a),b(b),c(c){}
}p[N];
int tot;
priority_queue<pli>heap;
LL findlow(int x){
	LL ans=inf;
	rep(i,1,tot)dn(ans,f(x,p[i].a,p[i].b,p[i].c));
	return ans;
}
pli findl(int r){
	int l=1;
	while(l<r){
		int mid=(l+r)>>1;
		if(findlow(mid)<f(mid,p[tot].a,p[tot].b,p[tot].c))l=mid+1;else r=mid;
	}
	if(l>1&&findlow(l-1)>f(l,p[tot].a,p[tot].b,p[tot].c))return mp(findlow(l-1),l-1);
	return mp(f(l,p[tot].a,p[tot].b,p[tot].c),l);
}
pli findr(int l){
	int r=m;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(findlow(mid)<f(mid,p[tot].a,p[tot].b,p[tot].c))r=mid-1;else l=mid;
	}
	if(l<m&&findlow(l+1)>f(l,p[tot].a,p[tot].b,p[tot].c))return mp(findlow(l+1),l+1);
	return mp(f(l,p[tot].a,p[tot].b,p[tot].c),l);
}
LL find_max(int n, int m){
	::n=n;::m=m;
	if(m<=n){
		LL ans=0;
		rep(i,1,m){
			LL a,b,c;get(i,&a,&b,&c);
			up(ans,f(i,a,b,c));
		}
		return ans;
	}
	if(n==1){
		LL a,b,c;get(1,&a,&b,&c);
		return max(f(1,a,b,c),f(m,a,b,c));
	}
	LL a,b,c;get(1,&a,&b,&c);
	p[++tot]=VFK(a,b,c);
	get(m,&a,&b,&c);
	p[++tot]=VFK(a,b,c);
	heap.push(findl(m));
	LL ans=0;
	up(ans,f(1,p[1].a,p[1].b,p[1].c));
	up(ans,f(m,p[2].a,p[2].b,p[2].c));
	rep(i,3,n){
		pli k=heap.top();heap.pop();
		get(k.se,&a,&b,&c);
		if(f(k.se,a,b,c)==k.fi)return max(ans,k.fi);
		p[++tot]=VFK(a,b,c);
		heap.push(findl(k.se));heap.push(findr(k.se));
	}
	return max(ans,heap.top().first);
}
