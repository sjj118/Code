#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=5000+10,mo=1e9+7;
typedef long long LL;
int n,m;
LL a[N],c[N],_a[N];
int main(){
	freopen("code.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&_a[i]);
	fclose(stdin);
	freopen("code.out","r",stdin);
	scanf("%d",&m);
	rep(i,1,m)scanf("%lld",&c[i]);
	rep(i,1,m)a[i]=_a[i];
	rep(i,m+1,n)rep(j,1,m)a[i]=(a[i]+c[j]*a[i-j])%mo;
	rep(i,1,n)if(a[i]!=_a[i])while(1)cerr<<"ERROR"<<endl;

	return 0;
}
