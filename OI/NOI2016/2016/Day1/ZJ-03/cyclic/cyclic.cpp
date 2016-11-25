#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=2e7+10;
typedef long long LL;
using namespace std;
inline int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
int n,m,k;
LL ans;
int tot,prime[maxn],miu[maxn];
bool s[maxn];
void pre(){
	miu[1]=1;
	rep(i,2,maxn-1){
		if(!s[i])prime[++tot]=i,miu[i]=-1;
		for(int j=1;j<=tot&&i*prime[j]<maxn;++j){
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
	freopen("cyclic.in","r",stdin);freopen("cyclic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	pre();
	int mm=min(n,m);
	rep(d,1,mm){
		LL tmp=0;
		for(int i=1;i*i<=k;++i)if(k%i==0){
			tmp+=miu[i]*(m*gcd(d,i)/d/i);
			if(i*i!=k)tmp+=miu[k/i]*(m*gcd(d,k/i)/d/(k/i));
		}
		ans+=miu[d]*(n/d)*tmp;
	}
	printf("%lld\n",ans);
	return 0;
}
