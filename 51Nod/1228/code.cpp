#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int maxk=2016,mo=1e9+7;
using namespace std;
inline LL read(){LL tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
inline void ck(LL&x){x%=mo;if(x>=mo)x-=mo;if(x<0)x+=mo;}
inline void ad(LL&x,LL y){x+=y;ck(x);}
LL n,k,B[maxk],fact[maxk],inv[maxk],_fact[maxk];
inline LL C(int n,int m){if(m>n)return 0;return fact[n]*_fact[m]%mo*_fact[n-m]%mo;}
int main(){
	inv[1]=1;rep(i,2,maxk-1)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i]);
	fact[0]=1;rep(i,1,maxk-1)fact[i]=fact[i-1]*i%mo;
	_fact[0]=1;rep(i,1,maxk-1)_fact[i]=_fact[i-1]*inv[i]%mo;
	B[0]=1;rep(i,1,maxk-2){rep(j,0,i-1)ad(B[i],-C(i+1,j)*B[j]%mo);B[i]=B[i]*inv[i+1]%mo;}
	int T=read();
	while(T--){
		n=(read()+1)%mo;k=read();
		LL ans=0,tmp=n;per(i,k,0)ad(ans,C(k+1,i)*B[i]%mo*tmp%mo),tmp=tmp*n%mo;
		printf("%lld\n",ans*inv[k+1]%mo);
	}
	return 0;
}
