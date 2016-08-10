#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int maxn=3010;
using namespace std;
inline LL sqr(LL x){return x*x;}
inline LL read(){LL tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
LL n,m;
LL f[maxn][maxn],a[maxn],sum;
int q[maxn],ql,qr;
inline LL y(int p,int i){return f[p][i]+sqr(a[i])*m+2*sum*a[i];}
inline LL x(int i){return 2*m*a[i];}
inline LL trans(int i,int j,int k){return f[i-1][k]+m*sqr(a[j]-a[k])-2*sum*(a[j]-a[k]);}
int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,1,n)sum+=a[i]=read();
	if(m>n){
		LL ans=0;
		rep(i,1,n)ans+=sqr(a[i])*m-2*sum*a[i];
		printf("%lld",ans+sqr(sum));
	}else{
		rep(i,1,n)a[i]+=a[i-1];
		q[ql=qr=1]=0;
		rep(i,1,m){
			rep(j,1,n){
				while(qr>ql&&(double(y(i-1,q[ql+1])-y(i-1,q[ql]))/double(x(q[ql+1])-x(q[ql]))<=a[j]))++ql;
				f[i][j]=trans(i,j,q[ql]);
			}
			q[ql=qr=1]=0;
			rep(j,1,n){
				while(qr>ql&&double(y(i,j)-y(i,q[qr]))/double(x(j)-x(q[qr]))<=double(y(i,q[qr])-y(i,q[qr-1]))/double(x(q[qr])-x(q[qr-1])))--qr;
				q[++qr]=j;
			}
		}
		printf("%lld",f[m][n]+sqr(sum));
	}
	return 0;
}
