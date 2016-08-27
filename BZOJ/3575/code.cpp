#include<iostream>
#include<cstdio>
#define ls (k<<1)
#define rs (k<<1|1)
#define fa (k>>1)
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxm=4e5+10,inf=1e9+7;
int n,m,l,dis[maxn];
struct Heap{
	int key[maxn],pos[maxn],tot;
	void pushup(int k){
		while(1){
			if(dis[key[k]]<dis[key[fa]])swap(key[k],key[fa]),swap(pos[key[k]],pos[key[fa]]),k=fa;else break;
		}
	}
	void pushdown(int k){
		while(ls<=tot){
			if((rs>tot||dis[key[ls]]<dis[key[rs]])&&dis[key[ls]]<dis[key[k]])swap(key[k],key[ls]),swap(pos[key[k]],pos[key[ls]]),k=ls;
			else if(rs<=tot&&dis[key[rs]]<dis[key[ls]]&&dis[key[rs]]<dis[key[k]])swap(key[k],key[rs]),swap(pos[key[k]],pos[key[rs]]),k=rs;
			else break;
		}
	}
	void push(int x){
		key[++tot]=x;pos[x]=tot;
		pushup(tot);
	}
	int top(){return key[1];}
	int size(){return tot;}
	void pop(){key[1]=key[tot],pos[key[1]]=1;--tot;pushdown(1);}
}heap;
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],len[maxm],path[maxm],mark[maxn],pa[maxn];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	Graph(){tot=1;}
	void Dijkstra(int s){
		rep(i,1,n)dis[i]=inf;dis[s]=0;
		rep(i,1,n)heap.push(i);
		while(heap.size()){
			int k=heap.top();heap.pop();
			for(int p=head[k];p;p=next[p])if((p&1)&&dis[to[p]]>dis[k]+len[p]){
				dis[to[p]]=dis[k]+len[p];pushup(to[p]);
			}
		}
	}
	void dfs(int k){

	}
}G;
int main(){
	scanf("%d%d%d",&n,&m,&l);
	rep(i,1,m){int a,b,c;scanf("%d%d%d",&a,&b,&c);G.ins(a,b,c);}
	G.Dijkstra(n);
	int k=1;G.mark[k]=1;
	rep(i,1,l){
		int x;scanf("%d",&x);
		G.path[x<<1]=1;
		G.pa[k]=G.to[x];
		k=G.to[x];mark[k]=1;
	}
	G.dfs(n);
	return 0;
}
