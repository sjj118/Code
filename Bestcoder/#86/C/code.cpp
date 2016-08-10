#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int maxn=2e5+10,mo=0;
using namespace std;
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0;char c=gc();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,m,k,a[maxn];
int main(){
	int T=read();
	while(T--){
		n=read();m=read();k=read();
		rep(i,1,n)a[i]=read();LL ans=0;
		int cnt=0;
		for(int l=1,r=0;l<=n-k+1;++l){
			while(cnt<k&&r<n)cnt+=(a[++r]>=m);
			if(cnt>=k)ans+=n-r+1;
			cnt-=(a[l]>=m);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
