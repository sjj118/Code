#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int inf=1e9+7;
inline int min(int a,int b){return a<b?a:b;}
inline void up(int&x,int y){if(y>x)x=y;}
int n,l1,r1,l2,r2;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		--l1;--l2;
		int m=min(r1,r2);
		int ans=0;
		for(int i=1,ne;i<=m;i=ne+1){
			ne=min(r1/(r1/i),r2/(r2/i));
			if(l1/ne!=r1/ne&&l2/ne!=r2/ne)up(ans,ne);
		}
		printf("%d\n",ans);
	}
	return 0;
}
