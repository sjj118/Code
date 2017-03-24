#include<cstdio>
#include<algorithm>
#include<assert.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
const int N=500+10,mo=1e9+7;
inline LL exgcd(LL a,LL b,LL&x,LL&y){
	if(!b)return x=1,y=0,a;
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
const int M=1e6;
LL fact[M],inv[M],_fact[M];
inline LL C(LL n,LL m){
	if(m>n)return 0;
	return fact[n]*_fact[m]%mo*_fact[n-m]%mo;
}
LL x0,y0,x1,y1,x2,y2,n,x[N],y[N];
LL calc(LL x0,LL y0){
	LL t1,t2,d=exgcd(x1,x2,t1,t2);
	if(x0%d)return 0;
	LL p1=x2/d,p2=x1/d;
	t1*=x0/d;t2*=x0/d;
	LL t=y0-t1*y1-t2*y2;
	if(t%(p1*y1-p2*y2))return 0;
	LL det=t/(p1*y1-p2*y2);
	t1+=det*p1;t2-=det*p2;
	assert(x1*t1+x2*t2==x0);
	assert(y1*t1+y2*t2==y0);
	if(t1<0||t2<0)return 0;
	return C(t1+t2,t1);
}
LL f[N];
bool vis[N];
LL count(int p){
	if(vis[p])return f[p];
	LL ret=calc(x[p],y[p]);
	rep(i,1,n)if(!(x[p]==x[i]&&y[p]==y[i]&&i<=p)){
		LL t=calc(x[p]-x[i],y[p]-y[i]);
		if(t)ad(ret,-t*count(i)%mo,mo);
	}
	vis[p]=1;
	return f[p]=ret;
}
int main(){
	scanf("%lld%lld%lld",&x0,&y0,&n);
	scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
	rep(i,1,n)scanf("%lld%lld",&x[i],&y[i]);
	inv[1]=1;rep(i,2,M-1)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	fact[0]=1;rep(i,1,M-1)fact[i]=fact[i-1]*i%mo;
	_fact[0]=1;rep(i,1,M-1)_fact[i]=_fact[i-1]*inv[i]%mo;
	x[n+1]=x0;y[n+1]=y0;
	printf("%lld",count(n+1));
	return 0;
}
