#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::sort;
using std::min;
typedef long long LL;
const int N=3e5+10;
inline int lowbit(int x){return x&-x;}
int n;
struct IOI{
	int h,pos;
}a[N];
bool operator<(const IOI&a,const IOI&b){return a.h<b.h||(a.h==b.h&&a.pos<b.pos);}
struct Bit{
	int arr[N];
	void add(int x,int y){
		for(;x<=n;x+=lowbit(x))arr[x]+=y;
	}
	int sum(int x){
		int ret=0;
		for(;x;x-=lowbit(x))ret+=arr[x];
		return ret;
	}
}bit;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i].h),a[i].pos=i;
	sort(a+1,a+1+n);
	LL ans=0;
	int cnt=0;
	per(i,n,1){
		if(a[i].h==a[i+1].h)++cnt;else cnt=0;
		ans+=min(bit.sum(a[i].pos-1),n-i-bit.sum(a[i].pos)-cnt);
		bit.add(a[i].pos,1);
	}
	printf("%lld",ans);
	return 0;
}
