#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=500+10,mo=998244353;
LL dp[N][N];
int n;
char a[N],b[N];
int main(){
	scanf("%d",&n);
	scanf("\n%s",a+1);
	scanf("\n%s",b+1);
	if(a[1]=='0'||b[1]=='1'){printf("0");return 0;}
	per(i,n,1)rep(j,i,n){
		if(a[i]=='0'||a[i]=='?'){
			if(b[i]=='0'||b[i]=='?'){
				if(i==j)(dp[i][j]+=1)%=mo;
			}
			if(b[i]=='1'||b[i]=='?'){
				(dp[i][j]+=dp[i+1][j])%=mo;
			}
		}
		if(a[i]=='1'||a[i]=='?'){
			if(b[i]=='0'||b[i]=='?'){
				(dp[i][j]+=dp[i+1][j])%=mo;
			}
			if(b[i]=='1'||b[i]=='?'){
				rep(k,i+1,j-1)(dp[i][j]+=dp[i+1][k]*dp[k+1][j])%=mo;
			}
		}
	}
	printf("%lld",dp[2][n]);
	return 0;
}
