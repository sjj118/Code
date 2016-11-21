#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int MO=119;
const int N=1e6+10;
int n,a,b,p,q,f[N];
int main(){
	while(scanf("%d%d%d%d%d",&n,&a,&b,&p,&q)>0){
		a%=MO;b%=MO;
		rep(i,1,n)(f[i]=a*((i>p)?f[i-p]:1)+b*((i>q)?f[i-q]:1))%=MO;
		printf("%d\n",f[n]);
	}
	return 0;
}

