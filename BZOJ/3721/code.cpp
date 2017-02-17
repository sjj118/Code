#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::sort;
typedef long long LL;
const int N=1e6+10;
inline void up(LL&x,LL y){x=y>x?y:x;}
LL s[N];
int n,k,a[N],lst[N][2],fst[N][2];
bool cmp(int a,int b){return a>b;}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	rep(i,1,n)s[i]=s[i-1]+a[i];
	int c[2];
	c[0]=c[1]=0;
	rep(i,1,n){
		c[a[i]&1]=i;
		lst[i][0]=c[0];
		lst[i][1]=c[1];
	}
	c[0]=c[1]=0;
	per(i,n,1){
		c[a[i]&1]=i;
		fst[i][0]=c[0];
		fst[i][1]=c[1];
	}
	int q;scanf("%d",&q);
	while(q--){
		int x;scanf("%d",&x);
		LL ans=s[x];
		if((ans&1)==0){
			ans=-1;
			if(lst[x][0]&&fst[x+1][1])up(ans,s[x]-a[lst[x][0]]+a[fst[x+1][1]]);
			if(lst[x][1]&&fst[x+1][0])up(ans,s[x]-a[lst[x][1]]+a[fst[x+1][0]]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
