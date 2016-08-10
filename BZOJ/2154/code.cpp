#include<iostream>
#include<cstdio>
#define maxn 10000010
#define mo 20101009
#define LL long long

using namespace std;

LL ans;
int n,m;
int prime[maxn],tot;
LL miu[maxn];
bool s[maxn];
void init(){
	miu[1]=1;
	for(LL i=2;i<=n;++i){
		if(!s[i])prime[tot++]=i,miu[i]=-1;
		for(LL j=0;j<tot&&i*prime[j]<=n;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				miu[i*prime[j]]=-miu[i];
			}else{
				miu[i*prime[j]]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i)miu[i]=(miu[i-1]+miu[i]*i*i%mo)%mo;
}
LL sum(LL l,LL r){
	return (l+r)*(r-l+1)/2%mo;
}
LL F(LL x,LL y){
	LL ans=0;
	for(int i=1,ne;i<=x;i=ne+1){
		ne=min(x/(x/i),y/(y/i));
		ans=(ans+(miu[ne]-miu[i-1])*sum(1,x/i)%mo*sum(1,y/i)%mo)%mo;
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	init();
	for(int i=1,ne;i<=n;i=ne+1){
		ne=min(n/(n/i),m/(m/i));
		ans=(ans+sum(i,ne)*F(n/i,m/i)%mo)%mo;
	}
	ans=(ans+mo)%mo;
	printf("%d",ans);
	return 0;
}
