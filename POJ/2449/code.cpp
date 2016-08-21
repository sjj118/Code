#include<iostream>
#include<cstdio>
#include<queue>
#define ls son[k][0]
#define rs son[k][1]
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1010,maxm=2e5+10,inf=1e9;
int n,m,s,t,k;
struct DijkHeap{
	priority_queue<pii,vector<pii>,greater<pii> > A,B;
	int size(){return A.size()-B.size();}
	void update(){while(B.size()&&A.top()==B.top())A.pop(),B.pop();}
	void push(pii x){A.push(x);}
	void pop(){update();A.pop();}
	pii top(){update();return A.top();}
	void del(pii x){B.push(x);}
}dijhp;
struct Heap{
	priority_queue<pii,vector<pii>,greater<pii> > A,B;
	int size(){return A.size()-B.size();}
	void update(){while(B.size()&&A.top()==B.top())A.pop(),B.pop();}
	void push(pii x){A.push(x);}
	void pop(){update();A.pop();}
	pii top(){update();return A.top();}
	void del(pii x){B.push(x);}
}heap;
const int maxp=1e6;
int root[maxn];
struct LeftistTree{
	int tot,pa[maxp],son[maxp][2],len[maxp][2],dis[maxp];
	LeftistTree(){dis[0]=-1;}
	inline int ws(int k){return son[pa[k]][1]==k;}
	void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	void pushup(int k){if(dis[ls]<dis[rs])swap(ls,rs);dis[k]=dis[rs]+1;}
	void rot(int k){
		int f=pa[k],w=ws(k);
		set(ls,f,0);set(rs,f,1);set(son[f][!w],k,!w);set(k,pa[f],ws(f));set(f,k,w);
		pushup(f);pushup(k);
	}
	void pushdown(int k){

	}
}lt;
struct Graph{
	int tot,head[maxn],next[maxm],to[maxm],len[maxm],dis[maxn];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	void Dijkstra(int s){
		rep(i,1,n)dis[i]=inf;dis[s]=0;
		rep(i,1,n)dijhp.push(mp(dis[i],i));
		rep(i,1,n){
			int k=dijhp.top().se;dijhp.pop();
			for(int p=head[k];p;p=next[p])if(dis[to[p]]>dis[k]+len[p]){
				dijhp.del(mp(dis[to[p]],to[p]));
				dis[to[p]]=dis[k]+len[p];
				dijhp.push(mp(dis[to[p]],to[p]));
			}
		}
	}
	int buildHeap(int k){

	}
	void buildGraph(){
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		G.addedge(a,b,c);
	}
	scanf("%d%d%d",&s,&t,&k);
	G.Dijkstra(t);
	G.buildGraph();
	return 0;
}
