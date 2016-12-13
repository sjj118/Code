#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10,inf=1e9;
int n,pos,nl,nr,a[N],b[N];
bool cmp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[N],mv;
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,cmp);
		for(int i=1,last=-inf;i<=tot;++i){
			if(*val[i]>last)last=*val[i],++mv;
			*val[i]=mv;
		}
	}
}lisan;
inline int lowbit(int x){return x&(-x);}
struct Bit{
	int arr[N];
	void add(int x,int y){
		for(;x<=n;x+=lowbit(x))arr[x]+=y;
	}
	int get(int x){
		int ret=0;
		for(;x;x-=lowbit(x))ret+=arr[x];
		return ret;
	}
	int get(int x,int y){
		return get(y)-get(x-1);
	}
}bit;
int main(){
	scanf("%d%d",&nl,&nr);
	n=nl+nr;pos=nl;
	per(i,nl,1)scanf("%d",&a[i]);
	rep(i,nl+1,n)scanf("%d",&a[i]);
	rep(i,1,n)lisan.ins(a[i]);
	lisan.work();
	rep(i,1,n)b[a[i]]=i;
	LL ans=0;
	per(i,n,1){
		int k=b[i];
		if(k<=pos)ans+=pos-k-bit.get(k+1,pos);
		else ans+=k-pos-1-bit.get(pos+1,k-1);
		bit.add(k,1);pos=k;
	}
	printf("%lld",ans);
	return 0;
}
