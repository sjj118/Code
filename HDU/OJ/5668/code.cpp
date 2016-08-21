#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
const int maxn=22;
typedef long long LL;
inline int lowbit(int x){return x&(-x);}
using namespace std;

LL n,a[maxn],mod[maxn],b[maxn];
LL exgcd(LL a,LL b,LL&x,LL&y){
	if(!b)return x=1,y=0,a;
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
LL CRT(){
	for(int i=n;i>1;--i){
		LL y1,y2,d=exgcd(mod[i],mod[i-1],y1,y2);
		if((a[i]-a[i-1])%d)return -1;
		y1*=(a[i]-a[i-1])/d;y2*=(a[i]-a[i-1])/d;
		a[i-1]=a[i]-y1*mod[i];
		mod[i-1]=mod[i]/d*mod[i-1];
		a[i-1]=(a[i-1]%mod[i-1]+mod[i-1])%mod[i-1];
	}
	return a[1];
}
struct BIT{
	int arr[maxn];
	void clear(){cls(arr);}
	void add(int x,int t){
		while(x<=n)arr[x]+=t,x+=lowbit(x);
	}
	int sum(int x){
		if(!x)return 0;
		int tmp=0;
		while(x)tmp+=arr[x],x-=lowbit(x);
		return tmp;
	}
}bit;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		bit.clear();for(int i=1;i<=n;++i)bit.add(i,1);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		for(int i=1;i<=n;++i)b[a[i]]=i;
		for(int i=1,last=0;i<=n;++i){
			if(last<=b[i])a[i]=bit.sum(b[i])-bit.sum(last);
			else a[i]=bit.sum(n)-bit.sum(last)+bit.sum(b[i]);
			bit.add(b[i],-1);last=b[i];
			a[i]%=n-i+1;
			mod[i]=n-i+1;
		}
		LL ans=CRT();if(ans==0)ans+=mod[1];
		if(ans==-1)printf("Creation August is a SB!\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
