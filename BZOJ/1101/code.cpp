#include<iostream>
#include<cstdio>
#define LL long long
#define maxn 50010

using namespace std;

int tot,prime[maxn],miu[maxn];
bool s[maxn];
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
	for(int i=1;i<maxn;++i)miu[i]+=miu[i-1];
}
LL calc(int x,int y){
	LL ans=0;
	if(x>y)swap(x,y);
	for(int i=1,ne;i<=x;i=ne+1){
		ne=min(min(x/(x/i),y/(y/i)),x);
		ans+=(LL)(miu[ne]-miu[i-1])*(x/i)*(y/i);
	}
	return ans;
}

int main(){
	pre();
	int T;scanf("%d",&T);
	while(T--){
		int a,b,d;scanf("%d%d%d",&a,&b,&d);
		printf("%lld\n",calc(a/d,b/d));
	}
	return 0;
}
