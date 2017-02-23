#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
const int N=2e6+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,d;
LL p,a[N],s[N];
int q[N],ql,qr;
int main(){
	int ans=0;
	scanf("%d%lld%d",&n,&p,&d);
	rep(i,1,n)a[i]=read(),s[i]=s[i-1]+a[i];
	ql=1;qr=0;q[++qr]=d;
	for(int l=1,r=d;r<=n;++r){
		while(ql<=qr&&s[r]-s[r-d]>=s[q[qr]]-s[q[qr]-d])--qr;
		q[++qr]=r;
		while(s[r]-s[l-1]-(s[q[ql]]-s[q[ql]-d])>p){
			++l;
			while(q[ql]-d+1<l)++ql;
		}
		up(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
