#include<iostream>
#include<cstdio>
#define maxn 100010
#define LL long long

using namespace std;

int a,b,x[maxn];
LL ll,rr;
LL sum;
LL getNum(LL n){
	LL tmp=0,sum=0;
	for(int i=1;i<=a;++i){
		sum+=x[i];
		if(sum<0)sum=0;
		if(sum>=n)sum=0,++tmp;
	}
	return tmp;
}

int main(){
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;++i)scanf("%d",&x[i]);
	for(int i=1;i<=a;++i)if(x[i]>0)sum+=x[i];
	LL l=1,r=sum/b;
	while(l<r){
		LL m=(l+r)>>1;
		if(getNum(m)<=b)r=m;else l=m+1;
	}
	ll=l;
	l=1,r=sum/b;
	while(l<r){
		LL m=(l+r+1)>>1;
		if(getNum(m)<b)r=m-1;else l=m;
	}
	rr=l;
	if(ll<=rr&&getNum(ll)==b)printf("%lld %lld",ll,rr);else printf("-1");
	return 0;
}
