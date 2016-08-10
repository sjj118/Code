#include<iostream>
#include<cstdio>
#define ll long long
#define maxn 10000009

using namespace std;

int n,tot,prime[maxn],miu[maxn],sum[maxn];
bool s[maxn];
void getP(){
	miu[1]=1;
	for(int i=2;i<maxn;++i){
		if(!s[i]){
			prime[tot++]=i;
			miu[i]=-1;
		}
		for(int j=0;j<tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				miu[i*prime[j]]=-miu[i];
			}else{
				miu[i*prime[j]]=0;
				break;
			}
		}
	}
	for(int i=1;i<maxn;++i)sum[i]=sum[i-1]+miu[i];
}

ll get(int a){
	ll ans=0;
	for(int d=1,ne=0;d<=a;d=ne+1){
		ll t=a/d;
		ne=a/t;
		ans+=t*t*(sum[ne]-sum[d-1]);
	}
	return ans;
}

int main(){
	getP();
	scanf("%d",&n);
	ll ans=0;
	for(int i=0;i<tot&&prime[i]<=n;++i)ans+=get(n/prime[i]);
	printf("%lld",ans);
	return 0;
} 
