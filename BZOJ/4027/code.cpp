#include<iostream>
#include<algorithm>
#include<cstdio>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e6+10;
typedef pair<int,int> pii;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,m,c[N],son[N];
pii ans[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void dfs(int k){
		for(int p=head[k];p;p=next[p])dfs(to[p]);
		static pii a[N];
		int cnt=0;
		for(int p=head[k];p;p=next[p])a[++cnt]=ans[to[p]];
		sort(a+1,a+1+cnt);
		pii ret=mp(0,0);
		rep(i,1,cnt)ret.se+=a[i].se;
		ret.fi=son[k]+c[k];
		rep(i,1,cnt)if(ret.fi+a[i].fi-1<=m)++ret.se,ret.fi+=a[i].fi-1;
		ans[k]=ret;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)c[i]=read();
	rep(i,1,n){
		son[i]=read();
		rep(j,1,son[i])G.ins(i,read()+1);
	}
	G.dfs(1);
	printf("%d",ans[1].se);
	return 0;
}
