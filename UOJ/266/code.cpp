#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::swap;
const int N=1e5+10,P=5e7;
int n,m;
#define ls son[k][0]
#define rs son[k][1]
struct Trie{
	int root[N];
	int tot,son[P][2],rev[P];
	bool full[P];
	void clear(){rep(i,1,n)root[i]=0;rep(i,1,tot)son[i][0]=son[i][1]=rev[i]=full[i]=0;tot=0;}
	void update(int k){
		full[k]=full[ls]&&full[rs];
	}
	void maintain_rev(int v,int k,int d){
		rev[k]^=v;
		if(d>=0)if((v>>d)&1)swap(ls,rs);
	}
	void maintain(int k,int d){
		if(rev[k])maintain_rev(rev[k],ls,d-1),maintain_rev(rev[k],rs,d-1),rev[k]=0;
	}
	void insert(int v,int&k,int d){
		if(!k)k=++tot;
		if(d==-1){full[k]=1;return;}
		maintain(k,d);
		insert(v,son[k][(v>>d)&1],d-1);
		update(k);
	}
	void insert(int k,int v){
		insert(v,root[k],16);
	}
	void modify_rev(int k,int v){
		rev[root[k]]^=v;
	}
	int merge(int a,int b,int d){
		if(!a&&!b)return 0;
		if(a&&b){
			int k=++tot;
			if(d==-1){full[k]=1;return k;}
			maintain(a,d);maintain(b,d);
			ls=merge(son[a][0],son[b][0],d-1);
			rs=merge(son[a][1],son[b][1],d-1);
			update(k);
			return k;
		}
		return a+b;
	}
	void merge(int a,int b){
		root[a]=merge(root[a],root[b],16);
	}
	int query_sg(int k,int d){
		if(d==-1)return 0;
		maintain(k,d);
		if(full[ls])return query_sg(rs,d-1)+(1<<d);
		else return query_sg(ls,d-1);
	}
	int query_sg(int k){
		return query_sg(root[k],16);
	}
}T;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],vis[N],sg[N];
	void clear(){tot=0;cls(head);}
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int dfs(int k,int pre){
		vis[k]=1;
		int t=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)t^=dfs(to[p],k);
		T.insert(k,t);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			T.modify_rev(to[p],t^sg[to[p]]);
			T.merge(k,to[p]);
		}
		sg[k]=T.query_sg(k);
		return sg[k];
	}
	int solve(){
		cls(vis);
		int ret=0;
		rep(i,1,n)if(!vis[i])ret^=dfs(i,0);
		return ret;
	}
}G;
int main(){
	int cas;scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&n,&m);
		G.clear();T.clear();
		rep(i,1,m){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
		if(G.solve())puts("Alice");else puts("Bob");
	}
	return 0;
}
