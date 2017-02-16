#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=5e5+10;
int n,m;
LL a[N],s[N],ans;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lld",&a[i]);
	int t=0;
	per(d,60,0){
		int cnt=0;
		++t;
		rep(i,1,n){
			cnt^=a[i]>>d&1;
			if(!cnt)++s[i];
		}
		int num=0;
		rep(i,1,n)if(s[i]==t)++num;
		if(cnt||num<m-1){
			--t;
			ans+=1ll<<d;
			cnt=0;
			rep(i,1,n){
				cnt^=a[i]>>d&1;
				if(!cnt)--s[i];
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
