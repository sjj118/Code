#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=110,inf=1e9;
int n,m,a[maxn][maxn],b[maxn][maxn],sum;
int ans=inf;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]),sum+=a[i][j];
	rep(r,1,n)rep(c,1,m){
		cls(b);bool ok=1;
		rep(i,1,n-r+1){
			if(!ok)break;
			rep(j,1,m-c+1){
				b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
				if(a[i][j]<b[i][j])ok=0;
				b[i+r][j+c]+=a[i][j]-b[i][j];
				b[i+r][j]-=a[i][j]-b[i][j];
				b[i][j+c]-=a[i][j]-b[i][j];
				b[i][j]=a[i][j];
			}
			rep(j,m-c+2,m){
				b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
				if(a[i][j]!=b[i][j])ok=0;
			}
		}
		rep(i,n-r+2,n){
			if(!ok)break;
			rep(j,1,m){
				b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
				if(a[i][j]!=b[i][j])ok=0;
			}
		}
		if(ok)ans=min(ans,sum/r/c);
	}
	printf("%d",ans);
	return 0;
}
