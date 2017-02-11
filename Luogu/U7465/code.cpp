#include<iostream>
#include<cstdio>
#include<map>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::map;
using std::cerr;
using std::endl;
typedef long long LL;
const int N=100+10,mo=1e9+7,P=1e4;
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline LL inv(LL n,LL p){return power(n,p-2,p);}
inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
LL x;
int n,a[N],tot,num[P],egcd[P][N];
LL dp[N][P];
map<int,int> id;
LL f(LL n){
	return (mo+1-power(x,n,mo))*inv(mo+1-x,mo)%mo;
}
int main(){
	scanf("%lld%d",&x,&n);
	x%=mo;
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]==0)--i,--n;
		else ++a[i];
	}
	id[0]=0;
	rep(i,1,n){
		for(int j=1;j*j<=a[i];++j)if(a[i]%j==0){
			if(id[j]==0)num[id[j]=++tot]=j;
			if(j*j<a[i]&&id[a[i]/j]==0)num[id[a[i]/j]=++tot]=a[i]/j;
		}
	}
	rep(i,0,tot)rep(j,1,n)egcd[i][j]=gcd(num[i],a[j]);
	dp[0][0]=1;
	rep(i,1,n){
		per(j,i-1,0){
			rep(p,0,tot)if(dp[j][p])ad(dp[j+1][id[egcd[p][i]]],dp[j][p],mo-1);
		}
	}
	LL ans=1;
	rep(i,1,n){
		rep(j,1,tot){
			if(i&1)ans=ans*power(f(num[j]),dp[i][j],mo)%mo;
			else ans=ans*inv(power(f(num[j]),dp[i][j],mo),mo)%mo;
		}
	}
	printf("%lld",ans);
	return 0;
}
