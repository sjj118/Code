#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=5000+10,maxm=2e5+10,inf=1e9;
int n,m;
struct Heap{
	priority_queue<pii,vector<pii>,greater<pii> > A,B;
	int size(){return A.size()-B.size();}
	void update(){while(B.size()&&A.top()==B.top())A.pop(),B.pop();}
	void push(pii x){A.push(x);}
	void pop(){update();A.pop();}
	pii top(){update();return A.top();}
	void del(pii x){B.push(x);}
}heap;
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],len[maxm],dis[maxn];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	void Dijkstra(int s){
		rep(i,1,n)dis[i]=inf;dis[s]=0;
		rep(i,1,n)heap.push(mp(dis[i],i));
		rep(i,1,n){
			int k=heap.top().se;heap.pop();
			for(int p=head[k];p;p=next[p])if(dis[to[p]]>dis[k]+len[p]){
				heap.del(mp(dis[to[p]],to[p]));
				dis[to[p]]=dis[k]+len[p];
				heap.push(mp(dis[to[p]],to[p]));
			}
		}
	}
	int second(int k){
		int tmp=inf;
		while(1){
			int s=0;
			for(int p=head[k];p;p=next[p]){
				if(dis[to[p]]+len[p]==dis[k])s=to[p];
				else tmp=min(tmp,dis[to[p]]-dis[k]+len[p]);
			}
			if(s)k=s;else break;
		}
		return tmp;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		G.addedge(a,b,c);
	}
	G.Dijkstra(n);
	printf("%d\n",G.dis[1]+G.second(1));
	return 0;
}
