#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=1e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,x[N],pos[N];
inline int lowbit(int x){return x&(-x);}
struct Bit{
	int arr[N];
	void add(int x,int t){
		for(;x<=n;x+=lowbit(x))arr[x]+=t;
	}
	int get(int x){
		int ret=0;
		for(;x;x-=lowbit(x))ret+=arr[x];
		return ret;
	}
}bit;
struct Mit{
	int arr[N];
	void set(int x,int y){
		for(;x<=n;x+=lowbit(x))up(arr[x],y);
	}
	int get(int x){
		int ret=0;
		for(;x;x-=lowbit(x))up(ret,arr[x]);
		return ret;
	}
}mit;
int f[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&x[i]);
	per(i,n,1){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(mid>=x[i]+1+bit.get(mid))r=mid;else l=mid+1;
		}
		pos[i]=l;
		bit.add(pos[i],1);
	}
	int ans=0;
	rep(i,1,n){
		f[i]=mit.get(pos[i])+1;
		mit.set(pos[i],f[i]);
		up(ans,f[i]);
		printf("%d\n",ans);
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
