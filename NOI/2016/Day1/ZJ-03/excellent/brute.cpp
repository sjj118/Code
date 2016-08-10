#include<iostream>
#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=2e3+10;
typedef long long LL;
using namespace std;

char s[maxn];
int next[maxn][maxn],n,tw[maxn][maxn],sum[maxn];

int main(){
	freopen("excellent.in","r",stdin);freopen("brute.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);int ans=0;
		rep(i,1,n){
			for(int j=i+3;j<=n;j+=2){
				for(int k=i+2;k<=j-1;k+=2){
					bool flag=1;
					for(int p=i,q=(i+k)>>1;q<k&&flag;++p,++q)if(s[p]!=s[q])flag=0;
					for(int p=k,q=(k+j+1)>>1;q<=j&&flag;++p,++q)if(s[p]!=s[q])flag=0;
					ans+=flag;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
