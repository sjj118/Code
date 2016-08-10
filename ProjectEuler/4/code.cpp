#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
inline LL gcd(LL a,LL b){if(!b)return a;return gcd(b,a%b);}
inline LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
using namespace std;
bool check(int n){
	int a[10],l=0;
	while(n)a[++l]=n%10,n/=10;
	rep(i,1,l/2)if(a[i]!=a[l-i+1])return 0;
	return 1;
}
int main(){
	int ans=0;
	rep(i,100,999)rep(j,100,999)if(check(i*j))ans=max(ans,i*j);
	printf("%d\n",ans);
	return 0;
}

