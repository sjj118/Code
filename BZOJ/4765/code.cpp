#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::min;
using std::max;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
typedef long long LL;
const int N=1e5+10,B=130;
int n,m;
int num[N][B];
LL val[N],sum[B],prsum[B][B];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		if(k){
			int r1=n/B;rep(i,0,r1)num[k][i]=num[pre][i];
			++num[k][k/B];
		}
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k),val[k]+=val[to[p]];
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lld",&val[i]);
	rep(i,1,n)G.addedge(read(),read());
	G.dfs(0,0);
	rep(i,1,n)sum[i/B]+=val[i];
	int r1=n/B;rep(i,0,r1){
		int l2=i*B,r2=min(n,i*B+B-1);
		prsum[i][0]=val[l2];
		rep(j,l2+1,r2)prsum[i][j-l2]=prsum[i][j-l2-1]+val[j];
	}
	while(m--){
		int op;scanf("%d",&op);
		if(op==1){
			int u,v;scanf("%d%d",&u,&v);
			LL det=v-val[u];val[u]=v;
			int r1=n/B;rep(i,0,r1)sum[i]+=det*num[u][i];
			r1=
		}else{
			int l,r;scanf("%d%d",&l,&r);
			LL ans=0;
		}
	}
	return 0;
}
