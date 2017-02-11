#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=30+5,mo=1e9+7;
inline void ck(int&x){if(x<0)x+=mo;if(x>=mo)x-=mo;}
inline void ad(int&x,int y){x+=y;ck(x);}
int n;
LL p[N],d[2][N];
struct Graph{
	int tot,head[N],to[N*N],next[N*N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void clear(){tot=0;cls(head);}
}G;
struct Div{
	int n,val[N];
};
bool operator<(const Div&a,const Div&b){
	if(a.n<b.n)return 1;
	if(a.n>b.n)return 0;
	rep(i,1,a.n){
		if(a.val[i]<b.val[i])return 1;
		if(a.val[i]>b.val[i])return 0;
	}
	return 0;
}
map<Div,LL> dp[2][N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		G.clear();
		scanf("%d",&n);
		rep(i,1,n)scanf("%lld",&p[i]);
		rep(i,1,n){
			int x;scanf("%d",&x);
			rep(j,1,x){
				int y;scanf("%d",&y);
				G.ins(i,y);
			}
		}
		d[0][1]=1;
		rep(i,1,n*(n-1)/2){
			cls(dp[i&1]);
			rep(k,1,n){
				for(int p=G.head[k];p;p=G.next[p])ad(dp[i&1][G.to[p]],dp[i&1^1][k]);
			}
		}
	}
	return 0;
}
