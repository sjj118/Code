#include<cstdio>
#include<algorithm>
#include<bitset>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::swap;
using std::bitset;
const int N=2000+10,M=500000+10;
int n,m;
bitset<N> a[N];
struct Query{
	int u,v;
}q[M];
int Gauss(){
	int ret=1;
	rep(i,1,n){
		if(a[i][i]==0){
			rep(j,i,n)if(a[j][i]){swap(a[i],a[j]);break;}
		}
		rep(j,i+1,n)if(a[j][i])a[j]^=a[i];
		ret&=a[i][i];
	}
	return ret;
}
bool check(int u,int v){

	return 233;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d%d",&q[i].u,&q[i].v),a[q[i].u].set(q[i].v);
	Gauss();
	rep(i,1,m)if(check(q[i].u,q[i].v))puts("YES");else puts("NO");
	return 0;
}
