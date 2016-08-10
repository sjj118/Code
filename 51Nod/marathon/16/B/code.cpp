#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register LL i=(x);i<=(y);++i)
#define per(i,x,y) for(register LL i=(x);i>=(y);--i)
typedef long long LL;
const LL inf=1e9,maxn=100,mo=1000000007;
const double eps=1e-8;
using namespace std;
inline char gc(){char c=getchar();while(!(c=='-'||c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0,f=1;char c=gc();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp*f;}
inline LL ck(LL&x){while(x<0)x+=mo;while(x>=mo)x-=mo;return x;}
inline LL ad(LL&x,LL y){return x+=y%mo;ck(x);}
inline void up(LL&x,LL y){if(y>x)x=y;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
inline LL gcd(LL a,LL b){if(!b)return a;return gcd(b,a%b);}
inline LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
inline LL sqr(LL x){return x*x;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;x=x*x%p,y>>=1)if(y&1)a=a*x%p;return a;}
inline LL exgcd(LL a,LL b,LL&x,LL&y){if(!b)return x=1,y=0,a;LL d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
inline LL inv(LL n,LL p){LL x,y;if(exgcd(n,p,x,y)>1)cerr<<"NO_REV"<<endl;return ck(x);}
/*ÏßÐÔÉ¸
int tot,prime[maxn],miu[maxn],phi[maxn];
bool s[maxn];
void sieve(){
	miu[1]=phi[1]=1;
	rep(i,2,maxn-1){
		if(!s[i])prime[++tot]=i,miu[i]=-1,phi[i]=i-1;
		for(int j=1;j<=tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				miu[i*prime[j]]=-miu[i];
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}else{
				miu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
		}
	}
}
//*/
LL dp[20][2];
LL calc(LL n){
	LL len=0,tmp=n;LL ans=0,a[20];
	while(tmp)a[++len]=tmp%10,tmp=tmp/10;
	rep(i,1,len/2)swap(a[i],a[len-i+1]);
	rep(i,1,len-1){
		if(i==1)ad(ans,285);
		else if(i==2)ad(ans,4050); 
		else{
			if(i&1)ad(ans,power(10,i-2,mo)%mo*9%mo*285%mo);
			ad(ans,power(10,i-2,mo)*4050%mo);
			if(i>3)ad(ans,(LL)(i-2-(i&1))*2025%mo*power(10,i-3,mo)%mo*9%mo);
		}
	}
	rep(i,1,len){
		if(i*2-1==len){
			rep(x,1,9){
				cls(dp);dp[0][1]=1;
				rep(j,1,len){
					if(j==i){
						if(a[j]==x)dp[j][0]=dp[j-1][0],dp[j][1]=dp[j-1][1];
						if(x<a[j])dp[j][0]=(dp[j-1][0]+dp[j-1][1])%mo;
						if(x>a[j])dp[j][0]=dp[j-1][0];
					}else rep(k,j==1,9){
						if(a[j]==k)ad(dp[j][0],dp[j-1][0]),ad(dp[j][1],dp[j-1][1]);
						if(k<a[j])ad(dp[j][0],dp[j-1][0]+dp[j-1][1]);
						if(k>a[j])ad(dp[j][0],dp[j-1][0]);
					}
				}
				ad(ans,(LL)x*x*(dp[len][0]+dp[len][1])%mo);
			}
		}else{
			rep(x,1,9)rep(y,1,9){
				cls(dp);dp[0][1]=1;
				rep(j,1,len){
					if(j==i){
						if(a[j]==x)dp[j][0]=dp[j-1][0],dp[j][1]=dp[j-1][1];
						if(x<a[j])dp[j][0]=(dp[j-1][0]+dp[j-1][1])%mo;
						if(x>a[j])dp[j][0]=dp[j-1][0];
					}else if(j==len-i+1){
						if(a[j]==y)dp[j][0]=dp[j-1][0],dp[j][1]=dp[j-1][1];
						if(y<a[j])dp[j][0]=(dp[j-1][0]+dp[j-1][1])%mo;
						if(y>a[j])dp[j][0]=dp[j-1][0];
					}else rep(k,j==1,9){
						if(a[j]==k)ad(dp[j][0],dp[j-1][0]),ad(dp[j][1],dp[j-1][1]);
						if(k<a[j])ad(dp[j][0],dp[j-1][0]+dp[j-1][1]);
						if(k>a[j])ad(dp[j][0],dp[j-1][0]);
					}
				}
				ad(ans,(LL)x*y*(dp[len][0]+dp[len][1])%mo);
			}
		}
	}
	return ans;
}
LL L,R;
int main(){
	scanf("%lld%lld",&L,&R);
	printf("%lld",((calc(R)-calc(L-1)%mo)+mo)%mo);
	return 0;
}
