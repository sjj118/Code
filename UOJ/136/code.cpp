#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n,m,ans;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&m);
		if(n<m)swap(n,m);
		if(m==1){
			if(n<=4)ans=n-1;
			else if(n&1)ans=2+(n-3)/2;else ans=3+(n-4)/2;
		}else{
			int l=n-m;
			if(l<=1)ans=l;
			else if(l&1)ans=3+(l-1)/2-2;else ans=2+(l-2)/2;
			ans+=m;
		}
		printf("%d\n",ans);
	}
	return 0;
}
