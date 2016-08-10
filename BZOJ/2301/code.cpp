#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 50005
#define ll long long

using namespace std;

int n;
int miu[maxn],sum[maxn],prime[5133],tot;
bool s[maxn];
void getmiu(){
	miu[1]=1;
	for(int i=2;i<maxn;++i){
		if(!s[i]){
			prime[tot++]=i;
			miu[i]=-1;
		}
		for(int j=0;j<tot&&prime[j]*i<maxn;++j){
			s[prime[j]*i]=1;
			if(i%prime[j]==0){
				miu[prime[j]*i]=0;
				break;
			}else{
				miu[prime[j]*i]=-miu[i];
			}
		}
	}
	for(int i=1;i<maxn;++i)sum[i]=sum[i-1]+miu[i];
}
ll get(int a,int b){
	ll ans=0;
	if(a>b)swap(a,b);
	for(int d=1,ne=0;d<=a;d=ne+1){
		ll t1=a/d,t2=b/d;
		ne=min(a/t1,b/t2);
		ans+=t1*t2*(sum[ne]-sum[d-1]);
	}
	return ans;
}

int main(){
	getmiu();
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		a=ceil(double(a)/k);b=floor(double(b)/k);c=ceil(double(c)/k);d=floor(double(d)/k);
		printf("%lld\n",get(b,d)+get(a-1,c-1)-get(b,c-1)-get(a-1,d));
	}
	return 0;
}
