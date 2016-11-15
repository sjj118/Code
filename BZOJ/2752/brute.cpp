#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=1e5+10;
int n,m;
LL v[N];
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		char c;scanf("\n%c",&c);
		if(c=='C'){
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			rep(i,l,r-1)v[i]+=x;
		}else{
			int l,r;scanf("%d%d",&l,&r);
			LL p=0,q=(LL)(r-l+1)*(r-l)/2;
			rep(i,l,r){
				LL tmp=0;
				rep(j,i,r-1){
					tmp+=v[j];
					p+=tmp;
				}
			}
			LL d=gcd(p,q);
			p/=d;q/=d;
			printf("%lld/%lld\n",p,q);
		}
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
