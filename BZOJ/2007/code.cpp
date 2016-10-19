#include<iostream>
#include<cstdio>
#include<queue>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=500+10,maxp=300000,maxv=2.5e6,inf=1e9;
int n,ps;
inline int cw(int x,int y){
	if(x==0||y==n+1)return n*n+1;
	if(x==n+1||y==0)return n*n+2;
	return (x-1)*n+y;
}
struct Heap{
	priority_queue<pii,vector<pii>,greater<pii> >A,B;
	int size(){return A.size()-B.size();}
	void update(){while(B.size()&&A.top()==B.top())A.pop(),B.pop();}
	pii top(){update();return A.top();}
	void pop(){update();A.pop();}
	void push(pii x){A.push(x);}
	void del(pii x){B.push(x);}
}heap;
struct Graph{
	int tot,head[maxp],next[maxv],to[maxv],len[maxv],dis[maxp];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	int Dijkstra(int s,int t){
		rep(i,1,ps)dis[i]=inf;dis[s]=0;
		rep(i,1,ps)heap.push(mp(dis[i],i));
		while(heap.size()){
			int k=heap.top().se;heap.pop();
			if(k==t)break;
			for(int p=head[k];p;p=next[p])if(dis[to[p]]>dis[k]+len[p]){
				heap.del(mp(dis[to[p]],to[p]));
				dis[to[p]]=dis[k]+len[p];
				heap.push(mp(dis[to[p]],to[p]));
			}
		}
		return dis[t];
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d",&n);ps=n*n+2;
	rep(i,1,n+1)rep(j,1,n){int w;scanf("%d",&w);G.ins(cw(i-1,j),cw(i,j),w);}
	rep(i,1,n)rep(j,1,n+1){int w;scanf("%d",&w);G.ins(cw(i,j),cw(i,j-1),w);}
	rep(i,1,n+1)rep(j,1,n){int w;scanf("%d",&w);G.ins(cw(i,j),cw(i-1,j),w);}
	rep(i,1,n)rep(j,1,n+1){int w;scanf("%d",&w);G.ins(cw(i,j-1),cw(i,j),w);}
	printf("%d",G.Dijkstra(n*n+1,n*n+2));
	return 0;
}
