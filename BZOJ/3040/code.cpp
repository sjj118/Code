#include<iostream>
#include<cstdio>
#include<ext/pb_ds/priority_queue.hpp>
#define maxn 1000010
#define maxm 10000010
#define LL long long
#define inf 1e18
#define dij pair<LL,int>
#define Heap __gnu_pbds::priority_queue<dij,greater<dij>,pairing_heap_tag>

using namespace std;
using namespace __gnu_pbds;

Heap::point_iterator id[maxn];
Heap heap;

int n,m;
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],len[maxm];
	LL dis[maxn];
	void ins(int a,int b,int c){to[++tot]=b;len[tot]=c;next[tot]=head[a];head[a]=tot;}
	LL Dijkstra(int s,int t){
		for(int i=1;i<=n;++i)dis[i]=inf;
		dis[s]=0;
		id[s]=heap.push(make_pair(dis[s],s));
		while(heap.size()){
			int k=heap.top().second;heap.pop();
			for(int p=head[k];p;p=next[p])if(dis[k]+len[p]<dis[to[p]]){
				dis[to[p]]=dis[k]+len[p];
				if(id[to[p]]!=0)heap.modify(id[to[p]],make_pair(dis[to[p]],to[p]));
				else id[to[p]]=heap.push(make_pair(dis[to[p]],to[p]));
			}
		}
		return dis[t];
	}
}G;

int main(){
	scanf("%d%d",&n,&m);
	int T,rxa,rxc,rya,ryc,rp;
	scanf("%d%d%d%d%d%d",&T,&rxa,&rxc,&rya,&ryc,&rp);
	LL x=0,y=0,z=0;
	for(int i=1;i<=T;++i){
		x=(x*rxa+rxc)%rp;
		y=(y*rya+ryc)%rp;
		int a=min(x%n+1,y%n+1),b=max(y%n+1,y%n+1);
		G.ins(a,b,1e8-100*a);
	}
	for(int i=T+1;i<=m;++i){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		G.ins(x,y,z);
	}
	printf("%lld",G.Dijkstra(1,n));
	return 0;
}
