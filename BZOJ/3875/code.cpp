#include<iostream>
#include<cstdio>
#include<queue>
#define pli pair<LL,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=2e5+10,M=1e6+10;
int n;
struct Heap{
	priority_queue<pli,vector<pli>,greater<pli> >A,B;
	int size(){return A.size()-B.size();}
	void update(){while(B.size()&&A.top()==B.top())A.pop(),B.pop();}
	void push(pli x){A.push(x);}
	void del(pli x){B.push(x);}
	pli top(){update();return A.top();}
	void pop(){update();A.pop();}
}heap;
struct Graph{
	int tot,head[N],to[M],next[M];
	LL dis[N],d1[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	LL Dijkstra(int t){
		rep(i,1,n)heap.push(mp(min(dis[i],d1[i]),i));
		while(heap.size()){
			int k=heap.top().se;heap.pop();
			if(k==t)break;
			if(dis[k]<d1[k])for(int p=head[k];p;p=next[p]){
				heap.del(mp(min(dis[to[p]],d1[to[p]]),to[p]));
				dis[to[p]]-=d1[k]-dis[k];
				heap.push(mp(min(dis[to[p]],d1[to[p]]),to[p]));
			}
		}
		return min(d1[t],dis[t]);
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		LL s,k,r;scanf("%lld%lld%lld",&s,&k,&r);
		G.d1[i]=k;G.dis[i]=s;
		rep(j,1,r){int x;scanf("%d",&x);G.ins(x,i);}
	}
	rep(i,1,n)for(int p=G.head[i];p;p=G.next[p])G.dis[G.to[p]]+=G.d1[i];
	printf("%lld",G.Dijkstra(1));
	return 0;
}
