#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::sort;
const int N=1e5+10;
int n,c,k,t[N];
int main(){
	scanf("%d%d%d",&n,&c,&k);
	rep(i,1,n)scanf("%d",&t[i]);
	sort(t+1,t+1+n);
	int ans,i;
	for(i=1,ans=0;i<=n;++ans){
		int j;
		for(j=i;j<i+c&&j<=n&&t[j]-t[i]<=k;++j);
		i=j;
	}
	printf("%d",ans);
	return 0;
}
