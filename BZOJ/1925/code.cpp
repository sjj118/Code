#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=5000;
int n,p;
LL f[N][2][2],C[2][N];
int main(){
	scanf("%d%d",&n,&p);
	f[0][0][1]=f[0][1][0]=1;
	f[1][0][0]=f[1][1][1]=1;
	C[0][0]=1;
	rep(i,2,n){
		C[i&1^1][0]=1;
		rep(j,1,i-1)C[i&1^1][j]=(C[i&1][j-1]+C[i&1][j])%p;
		rep(j,1,i){
			(f[i][0][0]+=f[j-1][0][1]*f[i-j][1][0]%p*C[i&1^1][j-1])%=p;
			(f[i][0][1]+=f[j-1][0][1]*f[i-j][1][1]%p*C[i&1^1][j-1])%=p;
			(f[i][1][0]+=f[j-1][1][1]*f[i-j][1][0]%p*C[i&1^1][j-1])%=p;
			(f[i][1][1]+=f[j-1][1][1]*f[i-j][1][1]%p*C[i&1^1][j-1])%=p;
		}
	}
	printf("%lld",(f[n][0][0]+f[n][0][1]+f[n][1][0]+f[n][1][1])%p);
	return 0;
}
