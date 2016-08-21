#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
#define cls(a) memset(a,0,sizeof(a))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
LL n,m,k;
void solve(LL n){
	if(n==4){m=3;k=5;return;}
	if(n==1){m=-1;return;}
	if(n&1){m=(n*n)>>1;k=m+1;return;}
	solve(n/2);
	m<<=1;k<<=1;
}
int main(){
	scanf("%I64d",&n);
	if(n==1){printf("-1");return 0;}
	solve(n);
	if(m>0)printf("%I64d %I64d",m,k);
	else printf("-1");
	return 0;
}
