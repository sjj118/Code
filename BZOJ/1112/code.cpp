#include<iostream>
#include<cstdio>
#define lowbit(x) x&(-x)
#define maxn 100010
#define maxv 1000010
#define LL long long

using namespace std;

int n,k,h[maxn];
struct Bit{
	LL arr[maxv];
	void add(int x,int t){
		while(x<maxv)arr[x]+=t,x+=lowbit(x);
	}
	LL get(int x){
		LL ans=0;
		while(x)ans+=arr[x],x-=lowbit(x);
		return ans;
	}
}bit,sum;
int find(){
	int l=1,r=maxv;
	while(l<r){
		int m=(l+r)>>1;
		if(bit.get(m)<=k/2)l=m+1;else r=m;
	}
	return l;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&h[i]),++h[i];
	for(int i=1;i<=k;++i)bit.add(h[i],1),sum.add(h[i],h[i]);
	LL m=find();
	LL ans=sum.get(maxv-1)-2*sum.get(m)+m*(2*bit.get(m)-bit.get(maxv-1));
	for(int i=k+1;i<=n;++i){
		bit.add(h[i-k],-1);sum.add(h[i-k],-h[i-k]);
		bit.add(h[i],1);sum.add(h[i],h[i]);
		m=find();
		ans=min(sum.get(maxv-1)-2*sum.get(m)+m*(2*bit.get(m)-bit.get(maxv-1)),ans);
	}
	printf("%lld",ans);
	return 0;
}
