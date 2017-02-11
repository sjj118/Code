#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int mo=10007;
int fact[mo+10],inv[mo+10];
inline int power(int x,int y,int p){int a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
int calc(int n){
	if(n==0)return 0;
	return n/mo+calc(n/mo);
}
int count(int n){
	if(n==0)return 1;
	return power(fact[mo-1],n/mo,mo)%mo*fact[n%mo]%mo*count(n/mo)%mo;
}
int C(int n,int m){
	if(m>n)return 0;
	if(calc(n)-calc(m)-calc(n-m))return 0;
	return count(n)*inv[count(m)]%mo*inv[count(n-m)]%mo;
	//fact[n]/fact[m]/fact[n-m];
}
int main(){
	inv[1]=1;rep(i,2,mo-1)inv[i]=-mo/i*inv[mo%i]%mo+mo;
	fact[0]=1;rep(i,1,mo-1)fact[i]=fact[i-1]*i%mo;
	int T;scanf("%d",&T);
	while(T--){
		int n,m;scanf("%d%d",&n,&m);
		printf("%d\n",C(n,m));
	}
	return 0;
}
