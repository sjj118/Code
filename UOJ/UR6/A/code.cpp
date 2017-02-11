#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10;
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline LL inv(LL n,LL p){return power(n,p-2,p);}
int n,p;
LL t[N],h[N];
int main(){
	scanf("%d%d",&n,&p);
	rep(i,1,n)scanf("%lld",&h[i]);
	h[n+1]=h[1];
	/*if(power(26,n,p)==1){
		int k=n;
		while(h[1])t[k--]=h[1]%26,h[1]/=26;
	}else*/{
		rep(i,1,n){
			t[i]=(26*h[i]-h[i+1])%p*inv(power(26,n,p)-1,p)%p;
			if(t[i]<0)t[i]+=p;
		}
	}
	rep(i,1,n)printf("%c",(int)t[i]+'a');
	return 0;
}
