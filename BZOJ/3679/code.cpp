#include<cstdio>
#include<algorithm>
#include<map>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::map;
typedef long long LL;
inline void dn(LL&x,LL y){if(y<x)x=y;}
const int L=20;
LL n,l,r;
map<LL,LL> f[L][2];
int a[L];
LL calc(LL x){
	int l=0;while(x)a[++l]=x%10,x/=10;
	rep(i,0,l)f[i][0].clear(),f[i][1].clear();
	std::reverse(a+1,a+1+l);
	f[0][1][1]=1;
	rep(i,1,l)f[i][0][1]=1;
	rep(i,1,l){
		for(map<LL,LL>::iterator it=f[i-1][0].begin();it!=f[i-1][0].end();++it){
			rep(j,0,9){
				LL t=it->first*j;
				dn(t,n+1);
				f[i][0][t]+=it->second;
			}
		}
		for(map<LL,LL>::iterator it=f[i-1][1].begin();it!=f[i-1][1].end();++it){
			rep(j,0,a[i]-1){
				LL t=it->first*j;
				dn(t,n+1);
				f[i][0][t]+=it->second;
			}
			LL t=it->first*a[i];
			dn(t,n+1);
			f[i][1][t]+=it->second;
		}
	}
	LL ret=0;
	for(map<LL,LL>::iterator it=f[l][0].begin();it!=f[l][0].end();++it)if(it->first<=n&&it->first>0)ret+=it->second;
	for(map<LL,LL>::iterator it=f[l][1].begin();it!=f[l][1].end();++it)if(it->first<=n&&it->first>0)ret+=it->second;
	return ret;
}
int main(){
	scanf("%lld%lld%lld",&n,&l,&r);
	printf("%lld",calc(r-1)-calc(l-1));
	return 0;
}
