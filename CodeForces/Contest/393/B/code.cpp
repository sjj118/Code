#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::lower_bound;
inline void dn(int&x,int y){if(y<x)x=y;}
const int N=1e5+10;
int n,t[N],f[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&t[i]);
	f[0]=0;
	rep(i,1,n){
		f[i]=f[i-1]+20;
		dn(f[i],f[lower_bound(t+1,t+1+n,t[i]-90+1)-t-1]+50);
		dn(f[i],f[lower_bound(t+1,t+1+n,t[i]-1440+1)-t-1]+120);
	}
	rep(i,1,n)printf("%d\n",f[i]-f[i-1]);
	return 0;
}
