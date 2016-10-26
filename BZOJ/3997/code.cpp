#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;

namespace sjj118{
	
const int N=1000+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,a[N][N],f[N][N];
inline int lowbit(int x){return x&(-x);}
struct Bit{
	int arr[N];
	void clear(){cls(arr);}
	void ins(int x,int t){
		for(;x<=n;x+=lowbit(x))up(arr[x],t);
	}
	int get(int x){
		int ret=0;
		for(;x;x-=lowbit(x))up(ret,arr[x]);
		return ret;
	}
}bit;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
		bit.clear();
		int ans=0;
		rep(j,1,m)rep(i,1,n){
			f[i][j]=bit.get(n-i)+a[i][j];
			bit.ins(n-i+1,f[i][j]);
			up(ans,f[i][j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
