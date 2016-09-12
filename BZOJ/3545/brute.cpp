#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxq=5e5+10,maxm=1e6+10;
int n,m,q;
int h[maxn];
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],len[maxm],vis[maxn];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	int dfs(int k,int pre,int x,int t){
		int ans=(h[k]>=t);vis[k]=1;
		for(int p=head[k];p;p=next[p])if(!vis[to[p]]&&len[p]<=x)ans+=dfs(to[p],k,x,t);
		return ans;
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n)scanf("%d",&h[i]);
	rep(i,1,m){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);G.addedge(a,b,c);
	}
	rep(i,1,q){
		int x,v,k;scanf("%d%d%d",&v,&x,&k);
		int l=0,r=maxm;
		while(l<r){
			int m=(l+r+1)>>1;cls(G.vis);
			if(G.dfs(v,0,x,m)>=k)l=m;else r=m-1;
		}
		printf("%d\n",l==0?-1:l);
	}
	return 0;
}
