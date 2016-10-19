#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1000+10;
inline bool vaild(char c){return c=='R'||c=='F';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,a[maxn][maxn],h[maxn],l[maxn],r[maxn],ans;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m){char c=gc();a[i][j]=(c=='F');}
	rep(d,1,n){
		rep(i,1,m)if(a[d][i]==0)h[i]=0;else ++h[i];
		rep(i,1,m){
			l[i]=i;
			while(l[i]>1&&h[l[i]-1]>=h[i])l[i]=l[l[i]-1];
		}
		per(i,m,1){
			r[i]=i;
			while(r[i]<m&&h[r[i]+1]>=h[i])r[i]=r[r[i]+1];
		}
		rep(i,1,m)up(ans,h[i]*(r[i]-l[i]+1));
	}
	printf("%d",3*ans);
	return 0;
}
