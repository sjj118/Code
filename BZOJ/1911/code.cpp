#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e6+10;
const double eps=1e-6;
int n;
LL a,b,c,x[N],s[N],f[N];
LL X(int i){return f[i]+a*s[i]*s[i];}
LL Y(int i){return s[i];}
int q[N],ql,qr;
LL calc(int i,int j){return f[j]+a*(s[i]-s[j])*(s[i]-s[j])+b*(s[i]-s[j])+c;}
int main(){
	scanf("%d",&n);
	scanf("%lld%lld%lld",&a,&b,&c);
	rep(i,1,n)scanf("%lld",&x[i]),s[i]=s[i-1]+x[i];
	q[qr++]=0;
	rep(i,1,n){
		while(ql+1<qr&&(X(q[ql+1])-X(q[ql]))>=(2*a*s[i]+b)*(Y(q[ql+1])-Y(q[ql])))++ql;
		f[i]=calc(i,q[ql]);
		while(ql+1<qr&&1.0*(X(i)-X(q[qr-1]))/(Y(i)-Y(q[qr-1]))+eps>1.0*(X(q[qr-1])-X(q[qr-2]))/(Y(q[qr-1])-Y(q[qr-2])))--qr;
		q[qr++]=i;
	}
	printf("%lld",f[n]);
	return 0;
}
