#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace brute2{
	
typedef long long LL;
const int N=1e6,MO=1e9+7;
inline void ck(LL&x,LL p){if(x>=p)x-=p;if(x<0)x+=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
int n,k,l,r;
int prime[N],tot,s[N],miu[N];
LL ans;
void pre(){
	miu[1]=1;
	rep(i,2,N-1){
		if(!s[i])prime[++tot]=i,miu[i]=-1;
		for(int j=1;j<=tot&&i*prime[j]<N;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				miu[i*prime[j]]=-miu[i];
			}else{
				miu[i*prime[j]]=0;
				break;
			}
		}
	}
//	rep(i,1,N-1)miu[i]+=miu[i-1];
}
int main(){
	pre();
	scanf("%d%d%d%d",&n,&k,&l,&r);l=(l-1)/k+1;r/=k;
	rep(i,1,r)ad(ans,miu[i]*power(r/i-(l-1)/i,n,MO),MO);
	printf("%lld",ans);
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("brute2.out","w",stdout);
	return brute2::main();
}
