#include<iostream>
#include<cstdio>
#include<algorithm>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,num[N],f[N],ans,tot,s[N];
pii a[N];
inline int lowbit(int x){return x&(-x);}
struct BIT{
	int arr[N];
	void clear(){
		rep(i,1,n)arr[i]=inf;
	}
	void set(int x,int t){
		for(;x<=n;x+=lowbit(x))dn(arr[x],t);
	}
	int get(int x){
		int ret=0;
		for(;x;x-=lowbit(x))dn(ret,arr[x]);
		return ret;
	}
}bit;
bool cmp(pii a,pii b){return a.se<b.se||a.se==b.se&&a.fi<b.fi;}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){int x,y;scanf("%d%d",&x,&y);a[i]=mp(x+1,n-y);}
	sort(a+1,a+1+n,cmp);
	rep(i,1,n){
		if(a[i].fi<=0||a[i].se>n||a[i].se<a[i].fi)++ans;
		else if(a[i]==a[i-1])++num[tot];
		else a[++tot]=a[i],num[tot]=1;
	}
	rep(i,1,tot)if(num[i]>a[i].se-a[i].fi+1)ans+=num[i]-a[i].se+a[i].fi-1,num[i]=a[i].se-a[i].fi+1;
	rep(i,1,tot)s[i]=s[i-1]+num[i];
	bit.clear();
	rep(i,1,tot){
		f[i]=bit.get(a[i].fi-1)+s[i-1];
		bit.set(a[i].se,f[i]-s[i]);
	}
	int tmp=s[tot];
	rep(i,1,tot)dn(tmp,f[i]+s[tot]-s[i]);
	printf("%d",ans+tmp);
	return 0;
}
