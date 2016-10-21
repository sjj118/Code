#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=15000+10,M=30000+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,k;
struct Graph{
	int tot,head[N],to[M<<1],next[M<<1],len[M<<1],dis[N],vis[N];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	int query_minmax(int a,int b){
		rep(i,1,n)dis[i]=inf;dis[a]=0;cls(vis);
		while(!vis[b]){
			int k=0;
			rep(i,1,n)if(!vis[i]&&(k==0||dis[i]<dis[k]))k=i;
			if(k==0)break;
			vis[k]=1;
			for(int p=head[k];p;p=next[p])dn(dis[to[p]],max(dis[k],len[p]));
		}
		return dis[b];
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){int x,y,d;scanf("%d%d%d",&x,&y,&d);G.addedge(x,y,d);}
	while(k--){
		int a,b;scanf("%d%d",&a,&b);
		printf("%d\n",G.query_minmax(a,b));
	}
	return 0;
}
