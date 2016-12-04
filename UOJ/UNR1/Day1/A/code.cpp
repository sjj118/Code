#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int mo=998244353,maxn=1e6+10;
using namespace std;

inline void ck(int&x){while(x<0)x+=mo;while(x>=mo)x-=mo;}
inline void ad(int&x,int y){x+=y;ck(x);}
int n,ans,sum,ii,dd,pa=1,pb=1,pc=1;
struct A{
	int h,x,l,r,t;
}a[maxn],b[maxn],c[maxn];
bool operator<(A a,A b){return a.t<b.t;}
inline int read(){
	int tmp=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}

int main(){
	scanf("%d",&n);
	rep(i,1,n)a[i].h=read(),a[i].x=i;
	rep(i,1,n){
		a[i].l=i;
		while(a[i].l>1&&a[a[i].l-1].h<=a[i].h)a[i].l=a[a[i].l-1].l;
	}
	per(i,n,1){
		a[i].r=i;
		while(a[i].r<n&&a[a[i].r+1].h<a[i].h)a[i].r=a[a[i].r+1].r;
	}
	rep(i,1,n)b[i].h=a[i].h,b[i].t=max(a[i].x-a[i].l,a[i].r-a[i].x)+1;
	rep(i,1,n)c[i].h=a[i].h,c[i].t=a[i].r-a[i].l+2;
	rep(i,1,n)a[i].t=min(a[i].x-a[i].l,a[i].r-a[i].x)+1;
	sort(a+1,a+1+n);sort(b+1,b+1+n);sort(c+1,c+1+n);
	rep(i,1,n)ad(sum,a[i].h);
	ans=sum;ii=sum;
	rep(i,2,n){
		while(pa<=n&&a[pa].t<i)ad(ii,-a[pa++].h);
		while(pb<=n&&b[pb].t<i)ad(dd,b[pb++].h);
		while(pc<=n&&c[pc].t<i)ad(dd,-c[pc++].h);
		ad(sum,ii);ad(sum,-dd);
		ans^=sum;
	}
	printf("%d",ans);
	return 0;
}
