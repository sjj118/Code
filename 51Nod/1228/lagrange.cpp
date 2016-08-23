#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) fot(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
const int mo=1e9+7,maxk=2010;
LL n,k,inv[maxk],pw[maxk][maxk],m1[maxk],m2[maxk];
int main(){
	inv[1]=1;rep(i,2,maxk-1)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	rep(i,1,maxk-1){pw[i][0]=1;rep(j,1,maxk-1)pw[i][j]=pw[i][j-1]*i%mo;}
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&k);n%=mo;
		LL y=0,x=1,ans=0,f=1;
		m1[0]=1;rep(i,1,k+2)m1[i]=m1[i-1]*(n-k+i-2)%mo;
		m2[0]=1;rep(i,1,k+2)m2[i]=m2[i-1]*(n-i+1)%mo;
		rep(i,1,k+1)x=x*inv[i]%mo;if(k&1^1)f=-f;
		rep(i,1,k+1){
			f=-f;ad(y,pw[i][k],mo);x=x*(k-i+2)%mo*inv[i]%mo;
			ad(ans,y*m1[k-i+1]%mo*m2[i]%mo*x%mo*f,mo);
		}
		printf("%lld\n",ans);
	}
}
