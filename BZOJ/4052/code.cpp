#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const int maxn=1e5+10;
using namespace std;
inline LL read(){LL tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,x[maxn],top;
LL gcd(LL a,LL b){
	if(!b)return a;
	return gcd(b,a%b);
}
LL ans=0,g[maxn],a[maxn];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ans=top=0;
		rep(i,1,n)a[i]=read();
		rep(i,1,n){
			++top;
			x[top]=i;g[top]=0;
			rep(j,1,top)g[j]=gcd(g[j],a[i]);
			int p=1;
			rep(j,2,top)if(g[j]!=g[p])++p,x[p]=x[j],g[p]=g[j];
			top=p;
			rep(j,1,top)ans=max(ans,(LL)(i-x[j]+1)*g[j]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
