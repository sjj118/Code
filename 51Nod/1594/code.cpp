#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000001
#define LL long long
#define sqr(x) ((x)*(x))

using namespace std;

int T,n;
int tot,prime[maxn],phi[maxn],miu[maxn],c[maxn],D[maxn],g[maxn],mi[maxn];
bool s[maxn];
void init(){
	phi[1]=1;miu[1]=1;g[1]=1;mi[1]=1;
	for(int i=2;i<maxn;++i){
		if(!s[i])prime[tot++]=i,phi[i]=i-1,miu[i]=-1,g[i]=i-2,mi[i]=i;
		for(int j=0;j<tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
				miu[i*prime[j]]=-miu[i];
				mi[i*prime[j]]=prime[j];
				g[i*prime[j]]=g[i]*(prime[j]-2);
			}else{
				phi[i*prime[j]]=phi[i]*prime[j];
				miu[i*prime[j]]=0;
				mi[i*prime[j]]=mi[i]*prime[j];
				g[i*prime[j]]=g[i/mi[i]]*(phi[mi[i*prime[j]]]-phi[mi[i]]);
				break;
			}
		}
	}
}
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	init();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		memset(D,0,sizeof(D));
		for(int i=1;i<=n;++i)++c[phi[i]];
		for(int i=1;i<=n;++i)for(int j=1;i*j<=n;++j)D[i]+=c[i*j];
		LL ans=0;
		for(int i=1;i<=n;++i)ans+=(LL)D[i]*D[i]*g[i];
		printf("%lld\n",ans);
	}
	return 0;
}
