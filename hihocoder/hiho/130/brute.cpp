#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e6+10,mo=1e9+7;
int n,tot;
string s[N],t[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)cin>>s[i];
	rep(i,1,n){
		rep(l,0,s[i].length()-1)rep(r,l,s[i].length()-1){
			t[++tot]=string(s[i],l,r-l+1);
		}
	}
	sort(t+1,t+1+tot);
	tot=unique(t+1,t+1+tot)-t-1;
	LL ans=0;
	rep(i,1,tot){
		LL pw=1;
		per(j,t[i].length()-1,0)(ans+=pw*(t[i][j]-'0')%mo)%=mo,pw=pw*10%mo;
	}
	printf("%lld",ans);
	return 0;
}
