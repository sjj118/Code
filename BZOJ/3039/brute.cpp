#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1000+10;
int n,m,a[maxn][maxn],ans;
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m){char c;scanf("\n %c",&c);a[i][j]=(c=='F');}
	rep(x1,1,n)rep(y1,1,m){
		rep(x2,x1,n)rep(y2,y1,m){
			bool flag=1;
			rep(i,x1,x2)rep(j,y1,y2)if(a[i][j]==0)flag=0;
			if(flag)ans=max(ans,(x2-x1+1)*(y2-y1+1));
		}
	}
	printf("%d",ans*3);
	return 0;
}
