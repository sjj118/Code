#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int MO=119;
const int K=1e4+10;
struct Polynomial{
	int a[K];
}c;
Polynomial 
int n,a,b,p,q,f[K<<1];
int A[K<<1];
int main(){
	while("%d%d%d%d%d",&n,&a,&b,&p,&q){
		a%=MO;b%=MO;
		rep(i,1,K<<1)(f[i]=a*((i>p)?f[i-p]:1)+b*((i>q)?f[i-q]:1))%=MO;
		if(n<=(k<<1)){printf("%d\n",f[n]);continue;}
		rep(i,0,)
	}
	return 0;
}
