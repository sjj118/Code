#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],len[N<<1],size[N];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	LL dfs(int k,int pre){
		LL ret=0;size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			ret+=dfs(to[p],k);
			size[k]+=size[to[p]];
			ret+=(LL)len[p]*min(size[to[p]],n-size[to[p]]);
		}
		return ret;
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int a,b,c;scanf("%d%d%d",&a,&b,&c);G.addedge(a,b,c);}
	printf("%lld\n",G.dfs(1,0));
	return 0;
}
