#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=1e5+10,mo=998244353;
int n,a[maxn],nx[maxn],c[3];
LL f[maxn];
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		char c;
		scanf(" %c%c",&c,&c);
		if(c=='|')a[i]=1;else a[i]=0;
	}
	c[0]=c[1]=c[2]=n;
	per(i,n-1,1)nx[i]=c[a[i]+1],c[a[i]]=i;
	f[n]=1;
	per(i,n-1,1){
		f[i]=(1+f[i+1]+f[nx[i]+1])%mo;
	}
	printf("%lld",(f[1]+1)%mo);
	return 0;
}
