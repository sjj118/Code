#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e6+10;
int n,to[maxn],vis[maxn];
int add(int x,int t){x+=t;if(x>n)x%=n;if(x<=0)x+=n;if(t>0)return x*2-1;else return x*2;}
struct UFS{
	int pa[maxn],rank[maxn];
	void clear(){rep(i,1,n<<1)pa[i]=i;}
	int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}
	void unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return;
		if(rank[a]<rank[b])swap(a,b);
		pa[b]=a;if(rank[a]==rank[b])++rank[a];
	}
}S;
struct Forest{
	int tot,head[maxn],to[maxn],next[maxn],pa[maxn][20],dep[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void dfs(int k,int pre){
		dep[k]=dep[pre]+1;pa[k][0]=pre;
		rep(i,1,19)pa[k][i]=pa[pa[k][i-1]][i-1];
		for(int p=head[k];p;p=next[p])dfs(to[p],k);
	}
	int lca(int a,int b){
		if(dep[a]>dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[b][i]]>=dep[a])b=pa[b][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
}T;
int flag,incir[maxn];
void dfs(int k,int clock){
	vis[k]=clock;
	if(!vis[to[k]])dfs(to[k],clock);
	else{
		flag=1;
		if(vis[to[k]]==clock)vis[to[k]]=0;
		else flag=0;
	}
	if(flag)S.unio(k,to[k]),incir[k]=1;
	else T.ins(to[k],k);
	if(!vis[k])vis[k]=clock,flag=0;
}
int cnt,ans[maxn];
bool reachable(int a,int b){
	int lca=T.lca(a,b);
	return lca==a||lca==b||incir[a]||incir[b];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int x;scanf("%d",&x);
		if(x==1)to[i*2-1]=add(i,1),to[i*2]=add(i,-1);
		if(x==2)to[i*2-1]=add(i,-1),to[i*2]=add(i,1);
		if(x==3)to[i*2-1]=add(i,2),to[i*2]=add(i,-2);
		if(x==4)to[i*2-1]=add(i,-2),to[i*2]=add(i,2);
	}
	rep(i,1,n<<1)if(!vis[i])dfs(i,i);
	rep(i,1,n<<1)if(!T.dep[i])T.dfs(i,0);
	rep(i,1,n)if(!reachable(i*2-1,i*2))ans[++cnt]=i;
	printf("%d\n",cnt);
	rep(i,1,cnt)printf("%d ",ans[i]);
	return 0;
}
