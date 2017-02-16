#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
typedef long long LL;
using namespace std;
const int N=5000+10,mo=1e9+7;
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline LL inv(LL n,LL p){return power(n,p-2,p);}
int BM(int n,const LL*s,LL*c){
	static LL a[N];
	cls(a);a[0]=1;
	c[0]=1;
	LL b=1,l=0,m=1;
	rep(i,1,n){
		LL d=s[i];
		rep(j,1,l)d=(d+s[i-j]*c[j])%mo;
		if(d==0){++m;continue;}
		if(2*l<i){
			static LL t[N];
			rep(j,0,l)t[j]=c[j];
			l=i-l;
			rep(j,m,l)c[j]=(c[j]-a[j-m]*d%mo*inv(b,mo)%mo+mo)%mo;
			rep(j,0,l)a[j]=t[j];
			m=1;
			b=d;
		}else{
			rep(j,m,l)c[j]=(c[j]-a[j-m]*d%mo*inv(b,mo)%mo+mo)%mo;
			++m;
		}
	}
	return l;
}
int n,m;
LL a[N],c[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	m=BM(n,a,c);
	printf("%d\n",m);
	rep(i,1,m)printf("%lld ",(mo-c[i])%mo);
	return 0;
}
