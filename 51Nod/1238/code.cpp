#include<iostream>
#include<cstdio>
#define mo 1000000007
#define sqr(x) ((x)*(x))
#define maxp 1270607
#define maxn 20000000
#define ha 3899393 
#define min(a,b) (a<b?a:b) 
#define NOT_FOUND 1e18
#define LL long long

using namespace std;

int tot,prime[maxp];
int miu[maxn];
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
	for(int i=1;i<maxn;++i)miu[i]=((LL)miu[i]*i%mo*i%mo+miu[i-1])%mo;
}
struct Hash{
	LL key[ha],val[ha];
	int head[ha],next[ha],tot;
	void ins(LL k,LL v){key[++tot]=k;val[tot]=v;next[tot]=head[k%ha];head[k%ha]=tot;}
	LL get(LL k){for(int p=head[k%ha];p;p=next[p])if(key[p]==k)return val[p];return NOT_FOUND;}
}hash;
LL S2(LL x){return x%mo*((x+1)%mo)/2%mo*(2*x+1)/3%mo;}
LL getmiu(LL n){
	if(n<maxn)return miu[n];
	LL ans=hash.get(n);
	if(ans!=NOT_FOUND)return ans;
	ans=0;
	for(int i=2,ne;i<=n;i=ne){
		ne=min(n+1,n/(n/i)+1);
		ans=(ans+(S2(ne-1)-S2(i-1))*getmiu(n/i))%mo;
	}
	ans=1-ans;
	hash.ins(n,ans);
	return ans;
}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}

LL S(LL x){return x*(x+1)/2%mo;}
LL S(LL a,LL b){return (a+b)*(b-a+1)/2%mo;}
LL G(LL n){
	LL ans=0;
	for(LL i=1,ne;i<=n;i=ne){
		ne=min(n+1,n/(n/i)+1);
		ans=(ans+(getmiu(ne-1)-getmiu(i-1))*S(n/i))%mo;
	}
	return ans;
}
LL n,ans;

int main(){
	init();
	scanf("%lld",&n);
	for(LL i=1,ne;i<=n;i=ne){
		ne=min(n+1,n/(n/i)+1);
		ans=(ans+sqr(S(n/i))%mo*(G(ne-1)-G(i-1)))%mo;
	}
	ans=(ans%mo+mo)%mo; 
	printf("%lld",ans);
	return 0;
}
