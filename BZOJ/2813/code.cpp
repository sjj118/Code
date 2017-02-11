#include<iostream>
#include<cstdio>
#include<assert.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int mo=1e9+7,N=1e7+10;
inline LL sqr(LL x){return x*x%mo;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline LL inv(LL n,LL p){return power(n,p-2,p);}
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
int prime[N],tot,s[N],f[N],mi[N],num[N],_p2[N];
LL g[N];
LL q1,a,b,c;
void pre(){
	f[1]=g[1]=mi[1]=1;
	num[1]=0;
	rep(i,2,c){
		if(!s[i])prime[++tot]=i,f[i]=2,g[i]=((LL)i*i+1)%mo,mi[i]=i,num[i]=1,_p2[tot]=inv((sqr(i)+mo-1)%mo,mo);
		for(int j=1;j<=tot&&i*prime[j]<=c;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				num[i*prime[j]]=1;
				mi[i*prime[j]]=prime[j];
				f[i*prime[j]]=f[i]*f[prime[j]]%mo;
				g[i*prime[j]]=g[i]*g[prime[j]]%mo;
			}else{
				num[i*prime[j]]=num[i]+1;
				mi[i*prime[j]]=mi[i]*prime[j];
				f[i*prime[j]]=f[i/mi[i]]*(num[mi[i]]+2)%mo;
				g[i*prime[j]]=g[i/mi[i]]*(sqr((LL)mi[i]*prime[j]%mo*prime[j]%mo)+mo-1)%mo*_p2[j]%mo;
				break;
			}
		}
	}
}
LL A,B;
inline LL calcA(LL x){
	if(x<=2)return 2;
	return (f[x]+(x&1))%mo;
}
inline LL calcB(LL x){
	if(x<=2)return 5;
	return (g[x]+((x&1)?4:0))%mo;
}
int main(){
	int q;scanf("%d",&q);
	scanf("%lld%lld%lld%lld",&q1,&a,&b,&c);
	pre();
	rep(i,1,q){
		ad(A,calcA(q1),mo);
		ad(B,calcB(q1),mo);
		//cout<<calcA(q1)<<" "<<calcB(q1)<<endl;
		q1=(q1*a+b)%c+1;
	}
	printf("%lld\n%lld",A,B);
	return 0;
}
