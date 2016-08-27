#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
inline int lowbit(int x){return x&(-x);}
const int maxn=1e6+10;
int n;
LL a[maxn],b[maxn],dp[maxn],d[maxn],s[maxn];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	f[0]=0;
	per(i,n,1)s[i]=s[i+1]+b[i];
	per(i,n,1)d[i]=d[i+1]+(n-i)*b[i];
	rep(i,1,n)dp
	return 0;
}
