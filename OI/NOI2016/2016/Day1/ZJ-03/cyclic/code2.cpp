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
int tot,prime[maxn],miu[maxn],phi[maxn];
bool s[maxn];
void pre(){
	miu[1]=phi[1]=1;
	rep(i,2,maxn-1){
		if(!s[i])prime[++tot]=i,miu[i]=-1,phi[i]=i-1;
		for(int j=1;j<=tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				miu[i*prime[j]]=-miu[i];
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}else{
				miu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
		}
	}
}
LL calc(int a,int b,int c,int x){
	LL tmp=0;
	rep(i,b,c)tmp+=miu[i]*gcd(a,i)*x;
	return tmp;
}

int main(){
//	freopen("cyclic.in","r",stdin);freopen("code2.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	pre();
	int mm=min(n,m);
	for(int d=1,ne;d<=mm;d=ne+1){
		ne=min(mm,min(n/(n/d),m/(m/d)));
		LL tmp=0;
		for(int _d=1;_d*_d<=k;++_d)if(k%_d==0){
//			rep(i,d,ne)tmp+=miu[i]*miu[_d]*(m/d)*gcd(_d,i)/_d;
//			if(_d*_d<k)rep(i,d,ne)tmp+=miu[i]*miu[k/_d]*(m/d)*gcd(k/_d,i)/(k/_d);
			tmp+=miu[_d]*calc(_d,d,ne,m/d/_d);
			if(_d*_d<k)tmp+=miu[k/_d]*calc(k/_d,d,ne,m/d/(k/_d));
		}
		ans+=tmp*(n/d);
	}
	printf("%lld\n",ans);
	return 0;
}
