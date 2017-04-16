#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
int n,ans=1,mx=1;
inline void up(int&x,int y){if(y>x)x=y;}
bool isPrime(int n){
	for(int i=2;i*i<=n;++i)if(n%i==0)return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	if(isPrime(n))puts("1");
	else if((n&1)&&!isPrime(n-2))puts("3");
	else puts("2");
	return 0;
}
