#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
const int mo=1000000007,maxn=1e6+10;
typedef long long LL;
using namespace std;

int n;
int tot,prime[maxn],phi[maxn],s[maxn];
void pre(){
	phi[1]=1;
	rep(i,2,n){
		if(!s[i])prime[tot++]=i,phi[i]=i-1;
		for(int j=0;j<tot&&i*prime[j]<=n;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}else{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	pre();
	LL ans=1;
	rep(i,1,n)ans=ans*phi[i]%mo;
	printf("%lld",ans);
	return 0;
}
