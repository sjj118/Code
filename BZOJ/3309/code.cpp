#include<iostream>
#include<cstdio>
#define ll long long
#define maxn 10000005

using namespace std;

int t,prime[664579],tot,f[maxn],g[maxn],miu[maxn],summiu[maxn];
ll a,b;

bool s[maxn];
void init(){
	g[1]=f[1]=0;
	miu[1]=1;
	for(int i=2;i<=1e7;++i){
		if(!s[i]){
			prime[tot++]=i;
			miu[i]=-1;
			g[i]=1;
			f[i]=1;
		}
		for(int j=0;j<tot&&i*prime[j]<=1e7;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]==0){
				miu[i*prime[j]]=0;
				g[i*prime[j]]=g[i]+1;
				f[i*prime[j]]=max(f[i],g[i*prime[j]]);
				break;
			}else{
				miu[i*prime[j]]=-miu[i];
				g[i*prime[j]]=1;
				f[i*prime[j]]=f[i];
			}
		}
	}
	for(int i=1;i<=1e7;++i)summiu[i]=summiu[i-1]+miu[i];
}

int main(){
	init();
	scanf("%d",&t);
	while(t--){
		ll ans=0;
		scanf("%d%d",&a,&b);
		for(int d=1;d<=min(a,b);++d){
			ll cnt=0;
			int ta=a/d,tb=b/d; 
			for(int k=1;k<=min(ta,tb);++k)cnt+=miu[k]*(ta/k)*(tb/k);
			ans+=f[d]*cnt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
