#include<iostream>
#include<cstdio>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int M=20000+10,mo=998244353;
inline void ck(LL&x,LL p){if(x>=p)x-=p;if(x<0)x+=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
int m;
LL n,x,a[M],q[M],C[2][M],p1[M],p2[M],inv[M],fact[M],_fact[M];
LL _pr[M],*pr,sf[M],invpr[M],invsf[M];
int main(){
	scanf("%lld%d%lld",&n,&m,&x);
	rep(i,0,m)scanf("%lld",&a[i]);
	inv[1]=1;rep(i,2,m)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	fact[0]=1;rep(i,1,m)fact[i]=fact[i-1]*i%mo;
	_fact[0]=1;rep(i,1,m)_fact[i]=_fact[i-1]*inv[i]%mo;
	p1[0]=1;rep(i,1,m)p1[i]=p1[i-1]*x%mo;
	p2[0]=1;rep(i,1,m)p2[i]=p2[i-1]*(mo+1-x)%mo;
	rep(i,0,m)p2[i]=p2[i]*_fact[i]%mo;
	rep(i,0,m)a[i]=a[i]*p1[i]%mo*_fact[i]%mo;
	rep(i,0,m){
		//C[i&1][0]=1;
		//rep(j,1,i)C[i&1][j]=(C[i&1^1][j-1]+C[i&1^1][j])%mo;
		rep(j,0,i){
			ad(q[i],a[j]*p2[i-j]%mo,mo);
		}
		q[i]=q[i]*fact[i]%mo;
	}
	LL ans=0;
	pr=_pr+1;
	pr[-1]=1; rep(i,0,m)pr[i]=pr[i-1]*(n-i)%mo;
	sf[m+1]=1;per(i,m,0)sf[i]=sf[i+1]*(n-i)%mo;
	invpr[0]=1;rep(i,1,m)invpr[i]=invpr[i-1]*inv[i]%mo;
	rep(i,0,m){
		LL tmp=q[i]*pr[i-1]%mo*sf[i+1]%mo;
		//rep(j,0,m)if(i!=j)tmp=tmp*(n-j)%mo;
		tmp=tmp*invpr[i]%mo*invpr[m-i]%mo;
		if((m-i)&1)tmp=mo-tmp;
		/*rep(j,0,m)if(i!=j){
			if(j<i)tmp=tmp*inv[i-j]%mo;
			else tmp=tmp*(mo-inv[j-i])%mo;
		}*/
		ad(ans,tmp,mo);
	}
	printf("%lld",ans);
	return 0;
}
