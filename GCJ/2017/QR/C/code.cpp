#include<cstdio>
#include<algorithm>
#include<map>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
using std::map;
LL n,k;
map<LL,LL> s;
LL calc(LL n,const LL&mn,const bool&sm){
	if(n<=0)return 0;
	if(s.count(n))return s[n];
	LL ret=0;
	LL mid=(n+1)>>1;
	if(mid-1>mn||(mid-1==mn&&n-mid>=mn+sm))ret=1+calc(mid-1,mn,sm)+calc(n-mid,mn,sm);
	return s[n]=ret;
}
LL count(LL mn,bool sm){
	s.clear();
	return calc(n,mn,sm);
}
int main(){
	int tasknumber;scanf("%d",&tasknumber);
	rep(taskid,1,tasknumber){
		scanf("%lld%lld",&n,&k);
		printf("Case #%d: ",taskid);
		LL l=0,r=n;
		while(l<r){
			LL mid=(l+r+1)>>1;
			if(count(mid,0)>=k)l=mid;else r=mid-1;
		}
		if(count(l,1)>=k)printf("%lld %lld\n",l+1,l);else printf("%lld %lld\n",l,l);
	}
	return 0;
}
