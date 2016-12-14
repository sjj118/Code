#include<iostream>
#include<cstdio>
#include<set>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
int n;
LL ans;
multiset<int> T;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int k;scanf("%d",&k);
		rep(j,1,k){int x;scanf("%d",&x);T.insert(x);}
		multiset<int>::iterator it=T.begin();
		ans-=*it;T.erase(it);
		it=T.end();it--;
		ans+=*it;T.erase(it);
	}
	printf("%lld",ans);
	return 0;
}
