#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int maxn=1e3+10;
char s[maxn];
int dp[maxn][maxn],a[maxn][maxn];
int n;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);n>>=1;
		per(i,n,1){
			if(s[n+n-i+1]==s[n-i+1]){
				rep(j,0,n){
					if()
				}
			}else{
			}
		}
	}
	return 0;
}
