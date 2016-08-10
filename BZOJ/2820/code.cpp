#include<iostream>
#include<cstdio>
#define LL long long
#define maxn 10000010

using namespace std;

int T,n,m;
int tot,prime[maxn],miu[maxn];
LL g[maxn];
bool s[maxn];
void init(){
	miu[1]=1;
	for(int i=2;i<maxn;++i){
		if(!s[i])prime[tot++]=i,miu[i]=-1;
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
	for(int i=0;i<tot;++i)for(int j=1;j*prime[i]<maxn;++j)g[prime[i]*j]+=miu[j];
	for(int i=1;i<maxn;++i)g[i]+=g[i-1];
}

int main(){
	init();
	scanf("%d",&T);
	while(T--){
		LL ans=0;
		scanf("%d%d",&n,&m);if(n>m)swap(n,m);
		for(int i=1,ne;i<=n;i=ne+1){
			ne=min(n/(n/i),m/(m/i));
			ans+=(LL)(n/i)*(m/i)*(g[ne]-g[i-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
