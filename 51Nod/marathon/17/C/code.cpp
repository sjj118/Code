#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=110,maxm=5e4+10,mo=1e9+7;
inline void ck(LL&x){if(x<0)x+=mo;if(x>=mo)x-=mo;}
inline void ad(LL&x,LL y){x+=y;ck(x);}
int n,m,T,gcd[maxn][maxn];
int tot,head[maxn],from[maxm],to[maxm],next[maxm],len[maxm],indegree[maxn];
void ins(int a,int b,int c){to[++tot]=b;from[tot]=a;next[tot]=head[a];head[a]=tot;len[tot]=c;++indegree[b];}
int lp[maxn][maxn],num[maxn],topsort[maxn],cnt;
LL dp[maxn][maxn],tmp[maxn][maxn];
int q[maxn];
int ql,qr;
const int maxp=1e4+10,maxv=12e6;
int main(){
	rep(i,0,maxn-1)gcd[0][i]=i;
	rep(i,1,maxn-1)rep(j,0,maxn-1)gcd[i][j]=gcd[j%i][i];
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y,z;scanf("%d%d%d",&x,&y,&z);ins(x,y,z);}
	ql=1;qr=0;
	rep(i,1,n){dp[i][0]=1;if(indegree[i]==0)q[++qr]=i,topsort[++cnt]=i;}
	while(ql<=qr){
		int k=q[ql++];
		for(int p=head[k];p;p=next[p]){
			rep(i,0,maxn-1)if(dp[k][i])ad(dp[to[p]][gcd[i][len[p]]],dp[k][i]);
			--indegree[to[p]];
			if(indegree[to[p]]==0)q[++qr]=to[p],topsort[++cnt]=to[p];
		}
	}
	LL ans=0;
	rep(i,1,n)ad(ans,dp[i][1]);
	printf("%lld\n",ans);
	scanf("%d",&T);
	while(T--){
		int x,y;scanf("%d%d",&x,&y);
		cls(tmp);ans=0;
		rep(i,0,maxn-1)ad(tmp[to[x]][gcd[i][len[x]]],dp[from[x]][i]);
		rep(t,1,n){
			int k=topsort[t];
			rep(i,0,maxn-1)if(tmp[k][i])for(int p=head[k];p;p=next[p]){
				ad(dp[to[p]][gcd[i][len[p]]],-tmp[k][i]);
				ad(tmp[to[p]][gcd[i][len[p]]],tmp[k][i]);
			}
		}
		rep(i,0,maxn-1)ad(dp[to[x]][gcd[i][len[x]]],-dp[from[x]][i]);
		len[x]=y;
		rep(i,0,maxn-1)ad(dp[to[x]][gcd[i][len[x]]],dp[from[x]][i]);
		cls(tmp);
		rep(i,0,maxn-1)ad(tmp[to[x]][gcd[i][len[x]]],dp[from[x]][i]);
		rep(t,1,n){
			int k=topsort[t];
			rep(i,0,maxn-1)if(tmp[k][i])for(int p=head[k];p;p=next[p]){
				ad(dp[to[p]][gcd[i][len[p]]],tmp[k][i]);
				ad(tmp[to[p]][gcd[i][len[p]]],tmp[k][i]);
			}
		}
		rep(i,1,n)ad(ans,dp[i][1]);
		printf("%lld\n",ans);
	}
	return 0;
}
