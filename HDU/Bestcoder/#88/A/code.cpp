#include<iostream>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
char s[maxn];
int n;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("\n%s",s);n=strlen(s);
		int cnt=0;char last=0;
		LL ans=0;
		rep(i,0,n-1){
			if(s[i]=='q')++cnt;
			else{
				ans+=(LL)cnt*(cnt+1)/2;cnt=0;
			}
		}
		ans+=(LL)cnt*(cnt+1)/2;
		printf("%I64d\n",ans);
	}
	return 0;
}
