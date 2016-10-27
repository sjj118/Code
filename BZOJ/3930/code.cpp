#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
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
	rep(i,1,N-1)miu[i]+=miu[i-1];
}
LL smiu[2][N];
LL summiu(int n,int p,int t){
	if(n<N)return miu[n];
	if(smiu[p][t])return smiu[p][t];
	smiu[p][t]=1;
	for(int i=2,ne;i<=n;i=ne+1){
		ne=n/(n/i);
		ad(smiu[p][t],-summiu(n/i,p,t*i)*(ne-i+1)%MO,MO);
	}
	return smiu[p][t];
}
int main(){
	pre();
	scanf("%d%d%d%d",&n,&k,&l,&r);l=(l-1)/k+1;r/=k;
	--l;
	for(int i=1,ne,p,t,lastp,lastt;i<=r;i=ne+1){
		if(l<i)ne=r/(r/i);
		else ne=min(l/(l/i),r/(r/i));
		if(l<i)p=1,t=r/i;
		else if(l/(l/i)<r/(r/i))p=0,t=l/i;else p=1,t=r/i;
		ad(ans,power(r/i-l/i,n,MO)*(summiu(ne,p,t)-summiu(i-1,lastp,lastt))%MO,MO);
		lastp=p;lastt=t;
	}
	printf("%lld",ans);
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
