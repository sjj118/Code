#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=1e7+10,maxt=10000+10;
int p,n[maxt],m[maxt],maxx;
LL fact[maxn],inv[maxn],phi[maxn];
bool s[maxn];
int prime[664580],tot;
void pre(){
	rep(i,2,maxx){
		if(!s[i])prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=maxx;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main(){
	int T,p;scanf("%d%d",&T,&p);
	rep(i,1,T){
		scanf("%d%d",&n[i],&m[i]);
		if(n[i]>maxx)maxx=n[i];
	}
	pre();
	phi[1]=1;inv[1]=1;
	fact[0]=1;rep(i,1,maxx)fact[i]=fact[i-1]*i%p;
	for(rg int i=2;i<=maxx&&i<p;++i)inv[i]=(p-p/i)*inv[p%i]%p;
	rep(i,2,maxx){
		if(s[i])phi[i]=phi[i-1];
		else phi[i]=phi[i-1]*(i-1)%p*inv[i%p]%p;
	}
	rep(i,1,T){
		printf("%d\n",phi[m[i]]*fact[n[i]]%p);
	}
	return 0;
}
