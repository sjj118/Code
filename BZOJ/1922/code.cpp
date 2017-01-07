#include<iostream>
#include<cstdio>
#include<queue>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
typedef pair<LL,int> pli;
const int N=3000+10,M=70000+10,V=1e6;;
const LL inf=1e18;
inline void up(LL&x,LL y){if(y>x)x=y;}
int n,m,lp[N][N],deg[N];
struct Heap{
	priority_queue<pli,vector<pli>,greater<pli> >A,B;
	int size(){return A.size()-B.size();}
	void update(){while(B.size()&&A.top()==B.top())A.pop(),B.pop();}
	void push(pli x){A.push(x);}
	void del(pli x){B.push(x);}
	void pop(){update();A.pop();}
	pli top(){update();return A.top();}
}heap;
struct Graph{
	int tot,head[N],to[M],next[M],len[M];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	LL dis[N],tim[N];
	LL Dijkstra(){
		rep(i,1,n)dis[i]=inf;
		dis[1]=0;
		rep(i,1,n)if(deg[i]==0)heap.push(mp(dis[i],i));
		while(heap.size()){
			int k=heap.top().se;heap.pop();
			for(int p=head[k];p;p=next[p])if(max(dis[k],tim[k])+len[p]<dis[to[p]]){
				if(!deg[to[p]])heap.del(mp(max(dis[to[p]],tim[to[p]]),to[p]));
				dis[to[p]]=max(dis[k],tim[k])+len[p];
				if(!deg[to[p]])heap.push(mp(max(dis[to[p]],tim[to[p]]),to[p]));
			}
			rep(i,1,n)if(lp[k][i]){
				up(tim[i],max(dis[k],tim[k]));
				if(--deg[i]==0)heap.push(mp(max(dis[i],tim[i]),i));
			}
		}
		return max(dis[n],tim[n]);
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int a,b,c;scanf("%d%d%d",&a,&b,&c);G.ins(a,b,c);}
	rep(i,1,n){
		scanf("%d",&deg[i]);
		rep(j,1,deg[i]){int x;scanf("%d",&x);lp[x][i]=1;}
	}
	printf("%lld",G.Dijkstra());
	return 0;
}
