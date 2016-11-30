#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=60+10,M=1e5+10;
int n,x[N],y[N],match[M],used[M],vis[M],cnt,ans[N],tot;
int find(int k){
	rep(i,x[k],y[k])if(!used[i]){
		used[i]=1;vis[++cnt]=i;
		if(!match[i]||find(match[i])){
			match[i]=k;
			return i;
		}
	}
	return 0;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
		cls(match);
		tot=0;
		per(i,n,1){
			rep(j,1,cnt)used[vis[j]]=0;cnt=0;
			if(find(i))ans[++tot]=i;
		}
		printf("%d\n",tot);
		printf("%d",ans[tot]);per(i,tot-1,1)printf(" %d",ans[i]);puts("");
	}
	return 0;
}
