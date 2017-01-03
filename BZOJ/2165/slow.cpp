#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=100+10,LOGM=70;
const LL inf=1e18+10;
inline void up(LL&x,LL y){if(y>x)x=y;if(x>inf)x=inf;}
int n,logm;
LL m;
struct Trans{
	LL val[N][N];
	LL maxval(){
		LL ret=0;
		rep(i,1,n)up(ret,val[1][i]);
		return ret;
	}
}w[LOGM],tmp;
Trans operator*(const Trans&a,const Trans&b){
	Trans ret=a;
	rep(i,1,n)rep(j,1,n)up(ret.val[i][j],b.val[i][j]);
	rep(i,1,n)rep(k,1,n)if(a.val[i][k])rep(j,1,n)if(b.val[k][j])up(ret.val[i][j],a.val[i][k]+b.val[k][j]);
	return ret;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&m);
		logm=ceil(log2(m));
		rep(i,1,n)rep(j,1,n)scanf("%lld",&w[0].val[i][j]);
		rep(i,1,logm)w[i]=w[i-1]*w[i-1];
		LL lift=0;
		cls(tmp.val);
		per(i,logm,0){
			Trans t=tmp*w[i];
			if(t.maxval()<m)lift+=1ll<<i,tmp=t;
		}
		printf("%lld\n",lift+1);
	}
	return 0;
}
