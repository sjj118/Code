#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=1500001+100;
int s[maxn],tot,prime[maxn],phi[maxn];
void pre(){
	phi[1]=1;
	rep(i,2,maxn-1){
		if(!s[i])prime[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&i*prime[j]<maxn;++j){
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
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline LL sqr(LL x){return x*x;}
int num[maxn];
int main(){
	int n;scanf("%d",&n);LL cnt=0;
	int r1=floor(sqrt(n/2));
	rep(i,1,r1)rep(j,1,i-1){
		if(2ll*i*(i+j)>n)break;
		int tmp=2*i*(i+j);
		if(gcd(i*i+j*j,i*i-j*j)>1)continue;
		for(int x=tmp;x<=n;x+=tmp)++num[x];
	}
	rep(i,1,n)if(num[i]==1)++cnt;
	printf("%lld",cnt);
	return 0;
}
