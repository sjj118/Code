#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=110,maxv=4194304+10,mo=20110520;
inline void ck(int&x){if(x<0)x+=mo;if(x>=mo)x-=mo;}
inline void ad(int&x,int y){x+=y;ck(x);}
int n,m,v;
char map[maxn][maxn];
const int ha=300007;
struct Hash{
	int tot,head[ha],next[maxv],val[maxv],key[maxv];
	void clear(){cls(head);tot=0;}
	int find(int x){for(int p=head[x%ha];p;p=next[p])if(key[p]==x)return p;return 0;}
	void ins(int a,int b){key[++tot]=a;val[tot]=b;a%=ha;next[tot]=head[a];head[a]=tot;}
	void add(int a,int b){
		int t=find(a);
		if(t)ad(val[t],b);
		else ins(a,b);
	}
}dp[2];
int main(){
	scanf("%d%d",&n,&m);
	if(n<m){
		swap(n,m);
		rep(i,1,m)rep(j,1,n)scanf("\n%c",&map[j][i]);
	}else rep(i,1,n)rep(j,1,m)scanf("\n%c",&map[i][j]);
	v=1<<((m+1)<<1);
	int x=0;dp[0].add(0,1);
	rep(i,1,n){
		rep(j,1,m){
			x^=1;dp[x].clear();
			int l=(j-1)<<1,r=j<<1;
			rep(p,1,dp[x^1].tot){
				int k=dp[x^1].key[p],d=dp[x^1].val[p];
				if(((k>>l)&3)==0&&((k>>r)&3)==0){
					if(map[i][j]=='*'){dp[x].add(k,d);continue;}
					dp[x].add(k|(2<<l)|(2<<r),d);
					dp[x].add(k|(1<<l),d);
					dp[x].add(k|(1<<r),d);
				}else if(map[i][j]=='*')continue;
				else if(((k>>l)&3)==1&&((k>>r)&3)==1){
					dp[x].add(k^(1<<l)^(1<<r),d);
				}else if(((k>>l)&3)==0&&((k>>r)&3)==1){
					dp[x].add(k^(3<<r),d);
					dp[x].add(k^(1<<r)^(1<<l),d);
				}else if(((k>>l)&3)==1&&((k>>r)&3)==0){
					dp[x].add(k^(3<<l),d);
					dp[x].add(k^(1<<r)^(1<<l),d);
				}else if(((k>>l)&3)==2&&((k>>r)&3)==0){
					dp[x].add(k^(2<<l)^(2<<r),d);
					dp[x].add(k^(2<<l),d);
				}else if(((k>>l)&3)==0&&((k>>r)&3)==2){
					dp[x].add(k^(2<<l)^(2<<r),d);
					dp[x].add(k^(2<<r),d);
				}
			}
		}
		x^=1;dp[x].clear();
		rep(p,1,dp[x^1].tot)if((dp[x^1].key[p]<<2)<v)dp[x].add(dp[x^1].key[p]<<2,dp[x^1].val[p]);
	}
	printf("%d",dp[x].val[dp[x].find(0)]);
	return 0;
}
