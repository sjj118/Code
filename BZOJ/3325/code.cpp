#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10;
int n,r[maxn<<1],p[maxn<<1];
struct UFS{
	int pa[maxn],rank[maxn];
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	void unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return;
		if(rank[a]<rank[b])swap(a,b);
		pa[b]=a;
		if(rank[a]==rank[b])++rank[a];
	}
	void clear(){rep(i,1,n)pa[i]=i;}
}S;
struct Graph{
	int tot,head[maxn],next[maxn<<2],to[maxn<<2];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
}G;
struct Linkmap{
	int head[maxn],next[maxn];
	void ins(int a,int b){next[b]=head[a];head[a]=b;}
}lp;
int a[maxn],vis[maxn][27];
int main(){
	scanf("%d",&n);S.clear();
	rep(i,1,n)scanf("%d",&r[i<<1]);
	rep(i,1,n-1)scanf("%d",&r[i*2+1]);
	rep(i,1,n<<1|1)++r[i];
	int ms=1;
	rep(i,1,n<<1|1){
		p[i]=min(p[ms*2-i],ms+p[ms]-i);
		while(p[i]<r[i]){
			if((i+p[i])%2==0)S.unio((i+p[i])>>1,(i-p[i])>>1);
			++p[i];
		}
		if(i+p[i]>ms+p[ms])ms=i;
		if(i-p[i]&&i+p[i]<=n*2)G.addedge((i-p[i])>>1,(i+p[i])>>1);
	}
	rep(i,1,n)lp.ins(S.find(i),i);
	rep(i,1,n)if(!a[i]){
		rep(j,1,26)if(!vis[S.find(i)][j]){a[i]=j;break;}
		for(int p=lp.head[S.find(i)];p;p=lp.next[p]){
			a[p]=a[i];
			for(int t=G.head[p];t;t=G.next[t])vis[S.find(G.to[t])][a[i]]=1;
		}
	}
	rep(i,1,n)printf("%c",a[i]-1+'a');
	return 0;
}
