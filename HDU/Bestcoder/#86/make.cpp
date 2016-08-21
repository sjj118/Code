#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int maxn=0,mo=0;
using namespace std;
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0;char c=gc();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n=30,m=n*(n-1)/2,k=1e9,q=n*n*n;
int main(){
	freopen("code.in","w",stdout);
	printf("1\n");
	printf("%d %d %d %d\n",n,m,k,q);
	for(int i=1;i<=n;++i)printf("%d ",1);printf("\n");
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)printf("%d %d\n",i,j);
	printf("%d %d %d\n",1,1,1);
	return 0;
}
