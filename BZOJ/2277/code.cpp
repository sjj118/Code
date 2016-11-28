#include<iostream>
#include<cstdio>
#include<algorithm> 
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=250000+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline LL read(){LL ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL n,a[N],p[N],m;
int k,tot;
bool check(LL x){
	rep(i,1,tot)if(a[i]%x==0)return 0;
	return 1;
}
int main(){
	scanf("%lld%d",&n,&k);
	rep(i,1,k)a[i]=gcd(n,read());
	sort(a+1,a+k);
	tot=unique(a+1,a+k)-a;
	LL ans=0;
	for(int i=1;(LL)i*i<=a[k];++i)if(a[k]%i==0){
		p[++m]=i;
		if((LL)i*i<a[k])p[++m]=a[k]/i;
	}
	sort(p+1,p+1+m);
	rep(i,1,m)if(check(p[i])){ans=p[i];break;}
	printf("%lld",n/ans);
	return 0;
}
