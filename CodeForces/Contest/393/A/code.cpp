#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=2e5+10;
int n,p[N],b[N],vis[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	int ans=1;
	rep(i,1,n)ans^=b[i];
	int tmp=0;
	rep(i,1,n)if(!vis[i]){
		for(int k=i;!vis[k];k=p[k])vis[k]=1;
		++tmp;
	}
	if(tmp>1)ans+=tmp;
	printf("%d",ans);
	return 0;
}
