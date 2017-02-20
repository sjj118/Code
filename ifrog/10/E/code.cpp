#include<iostream>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::map;
typedef long long LL;
const int N=10000;
const LL inf=1e10;
int tot;
LL l,r,a[N];
void pre(LL x){
	if(x>inf)return;
	if(x)a[++tot]=x;
	pre(x*10+1);
	pre(x*10+6);
}
map<LL,LL> s[N];
LL calc(LL n,int p){
	if(p>tot)return 0;
	if(n==0)return 0;
	if(a[p]==n)return 1;
	if(s[p].count(n))return s[p][n];
	s[p][n]=calc(n,p+1)+(a[p]>1?calc(n/a[p],p):0);
	return s[p][n];
}
int main(){
	pre(0);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",calc(r,1)-calc(l-1,1));
	}
	return 0;
}
