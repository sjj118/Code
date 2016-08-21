#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int maxn=1e5+10,mo=0;
using namespace std;
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0;char c=gc();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,a[maxn];
int main(){
	int T=read();
	while(T--){
		n=read();LL ans=0;
		rep(i,1,n)a[i]=read();
		int fir=0,sec=0,thi=0,pf=0,ps=0;
		rep(i,1,n-1)if(abs(a[i]-a[i+1])>=fir)thi=sec,sec=fir,ps=pf,fir=abs(a[i]-a[i+1]),pf=i;else if(abs(a[i]-a[i+1])>=sec)thi=sec,sec=abs(a[i]-a[i+1]),ps=i;else if(abs(a[i]-a[i+1])>=thi)thi=abs(a[i]-a[i+1]);
		rep(i,1,n){
			int maxv=0;
			if(i==pf||i==pf+1){
				if(i==ps||i==ps+1)maxv=thi;else maxv=sec;
			}else maxv=fir;
			if(i>1&&i<n)maxv=max(maxv,abs(a[i-1]-a[i+1]));
			ans+=maxv;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
