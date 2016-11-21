#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=2e6+10;
LL k;
int n,m,a[N],b[N];
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d",&b[i]);

	return 0;
}
