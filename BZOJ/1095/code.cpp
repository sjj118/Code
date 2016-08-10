#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100009
#define inf 1e9
#define lson son[k][0]
#define rson son[k][1]
#define ws(k) (son[pa[k]][1]==k)

using namespace std;

int n,m,light[maxn],height[maxn][30],clo;
struct heap{
	priority_queue<int> A,B;
	int size(){
		return A.size()-B.size();
	}
	int top(){
		while(B.size()&&A.top()==B.top()) A.pop(),B.pop();
		if(!A.size())return -inf;
		return A.top();
	}
	void pop(){
		while(B.size()&&A.top()==B.top()) A.pop(),B.pop();
		A.pop();
	}
	int sectop(){
		int x=top();
		int ans=top();
		A.push(x);
		return ans;
	}
	void add(int x){
		A.push(x);
	}
	void del(int x){
		B.push(x);
	}
} A,B[maxn],C[maxn];
struct Tree{
	int tot,head[maxn],next[maxn<<1],son[maxn<<1],pa[maxn],dep[maxn];
	void addson(int a,int b){
		son[++tot]=b;
		next[tot]=head[a];
		head[a]=tot;
		pa[b]=a;
		dep[b]=dep[a]+1;
	}
	Tree(){
		dep[1]=1;
	}
} T;
struct graph{
	int tot,head[maxn],next[maxn<<1],to[maxn<<1],size[maxn],mark[maxn];
	void addedge(int a,int b){
		to[++tot]=b;
		next[tot]=head[a];
		head[a]=tot;
	}
	int findSize(int k,int pre){
		size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]])size[k]+=findSize(to[p],k);
		return size[k];
	}
	int gg,minmax;
	void findG(int k,int s,int pre){
		int temp=s-size[k];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]])temp=max(temp,size[to[p]]),findG(to[p],s,k);
		if(temp<minmax){
			minmax=temp;
			gg=k;
		}
	}
	int findG(int k,int s){
		gg=0;minmax=inf;
		findG(k,s,0);
		return gg;
	}
	void dfs(int k,int rt,int dep,int pre){
		C[rt].add(dep);height[k][T.dep[rt]]=dep;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]])dfs(to[p],rt,dep+1,k);
	}
	void build(int k){
		mark[k]=1;
		dfs(k,k,0,k);
		findSize(k,k);
		for(int p=head[k];p;p=next[p])if(!mark[to[p]]){
			int gr=findG(to[p],size[to[p]]);
			T.addson(k,gr);
			build(gr);
		}
	}
} G;
int query(){
	if(clo<=1)return clo-1;
	else return A.top();
}
void turnon(int k){
	--clo;
	light[k]=1;
	
}
void turnoff(int k){
	++clo;
	light[k]=0;
	
}

int main(){
	scanf("%d",&n);
	clo=n;
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		G.addedge(a,b);
		G.addedge(b,a);
	}
	G.build(1);
	for(int i=1;i<=n;++i) A.add(B[i].top()+B[i].sectop());
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		char op;
		scanf("\n%c",&op);
		if(op=='G'){
			printf("%d\n",query());
		}else{
			int x;
			scanf("%d",&x);
			if(light[x])turnoff(x);else turnon(x);
		}
	}
	return 0;
}
