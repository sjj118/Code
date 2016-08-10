#include<iostream>
#include<cstdio>
#define maxn 10000010
#define mo 100000009
#define LL long long

using namespace std;

int T,n,m;
int tot,prime[maxn],miu[maxn],mi[maxn];
LL g[maxn];
bool s[maxn];
void init(){
	miu[1]=g[1]=mi[1]=1;
	for(int i=2;i<maxn;++i){
		if(!s[i])prime[tot++]=i,miu[i]=-1,g[i]=1-i,mi[i]=i;
		for(int j=0;j<tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				miu[i*prime[j]]=-miu[i];
				mi[i*prime[j]]=prime[j];
				g[i*prime[j]]=g[i]*g[prime[j]]%mo;
			}else{
				miu[i*prime[j]]=0;
				mi[i*prime[j]]=mi[i]*prime[j];
				g[i*prime[j]]=g[i];
				break;
			}
		}
	}
	for(int i=1;i<maxn;++i)g[i]=(i*g[i]+g[i-1])%mo;
}
LL sum(LL x){
	return (1+x)*x/2%mo;
}

int main(){
	init();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n>m)swap(n,m);
		LL ans=0;
		for(int i=1,ne;i<=n;i=ne+1){
			ne=min(n/(n/i),m/(m/i));
			ans=(ans+sum(n/i)*sum(m/i)%mo*(g[ne]-g[i-1])%mo)%mo;
		}
		ans=(ans+mo)%mo;
		printf("%d\n",ans);
	}
	return 0;
}
