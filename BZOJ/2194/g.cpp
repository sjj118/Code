#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int mo=998244353;
LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
int main(){
	rep(g,2,10000){
		int p=mo-1;bool flag=1;
		for(int i=2;i*i<=p;++i)if(p%i==0){
			while(p%i==0)p/=i;
			if(power(g,(mo-1)/i,mo)==1){flag=0;break;}
		}
		if(p>1)if(power(g,(mo-1)/p,mo)==1)flag=0;
		if(flag){printf("%d",g);break;}
	}
	return 0;
}
