#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg LL i=(x);i<=(y);++i)
#define per(i,x,y) for(rg LL i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int mo=666623333,N=1e6+10;
LL l,r,a[N],phi[N],ans;
bool s[N];
int tot,prime[N];
void pre(){
	rep(i,2,N-1){
		if(!s[i])prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<N;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main(){
	pre();
	scanf("%lld%lld",&l,&r);
	rep(i,0,r-l)a[i]=i+l,phi[i]=1;
	rep(i,1,tot){
		LL p=1;
		int tmp=0;
		while(1){
			p*=prime[i];
			++tmp;
			LL s=l/p,t=r/p;
			if(s*p<l)++s;
			if(s>t)break;
			rep(j,s,t){
				a[j*p-l]/=prime[i];
				if(tmp==1)phi[j*p-l]*=(prime[i]-1);
				else phi[j*p-l]*=prime[i];
			}
		}
	}
	rep(i,0,r-l)if(a[i]>1)phi[i]=phi[i]*(a[i]-1);
	rep(i,0,r-l)ans=(ans+phi[i])%mo;
	ans=mo-ans;
	for(LL i=l;i<=r;++i)ans=(ans+i)%mo;
	printf("%lld",ans);
	return 0;
}
