#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 100000
#define LL long long

using namespace std;

bool s[maxn];
int prime[maxn],miu[maxn],tot;
void pre(){
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
}

int main(){
	pre();
	int T;scanf("%d",&T);
	while(T--){
		LL k;scanf("%lld",&k);
		LL l=k,r=k*2;
		while(l<r){
			LL m=(l+r)>>1,c=floor(sqrt(m));
			LL tmp=0;
			for(int i=1;i<=c;++i)tmp+=m/i/i*miu[i];
			if(tmp<k)l=m+1;else r=m;
		}
		printf("%lld\n",l);
	}
	return 0;
}
