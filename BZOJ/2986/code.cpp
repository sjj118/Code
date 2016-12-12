#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e6+10;
bool s[N];
int tot,prime[N],miu[N];
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
}
LL n;
LL count(LL n){
	LL ret=0;
	for(int i=1;(LL)i*i<=n;++i)ret+=n/i/i*miu[i];
	return n-ret;
}
int main(){
	pre();
	scanf("%lld",&n);
	LL l=1,r=1e12;
	while(l<r){
		LL mid=(l+r)>>1;
		if(count(mid)>=n)r=mid;else l=mid+1;
	}
	printf("%lld",l);
	return 0;
}
