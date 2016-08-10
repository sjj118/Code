#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=3e5+10,maxt=1e6+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline int lowbit(int x){return x&(-x);}
int n,dp[maxn];
struct Wave{
	int m,f,w;
}a[maxn];
bool operator<(Wave a,Wave b){return a.m<b.m;}
struct Bit{
	int arr[maxt];
	void set(int x,int t){
		for(;x<maxt;x+=lowbit(x))up(arr[x],t);
	}
	int get(int x){
		int tmp=0;
		for(;x;x-=lowbit(x))up(tmp,arr[x]);
		return tmp;
	}
}bit;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d%d",&a[i].m,&a[i].f,&a[i].w);
	sort(a+1,a+1+n);
	int ans=0;
	rep(i,1,n){
		dp[i]=bit.get(a[i].m)+a[i].f;
		bit.set(a[i].m+a[i].w,dp[i]);
		up(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
