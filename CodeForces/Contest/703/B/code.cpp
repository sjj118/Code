#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int maxn=1e5+10;
using namespace std;
int n,k,c[maxn],cap[maxn];
LL sum,ans;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&c[i]);
	rep(i,1,k){int x;scanf("%d",&x);cap[x]=1;}
	rep(i,1,n)sum+=c[i];
	rep(i,1,n){
		if(cap[i])sum-=c[i],ans+=sum*c[i];else if(!cap[i-1])ans+=c[i]*c[i-1];
	}
	if(!cap[1]&&!cap[n])ans+=c[1]*c[n];
	printf("%I64d",ans);
	return 0;
}
