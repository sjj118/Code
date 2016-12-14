#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=300+10;
int n,m,w[N][N],ed[N][2],ps;
struct UFS{
	int pa[N<<1],rank[N<<1];
	void clear(){rep(i,2,ps)pa[i]=i,rank[i]=0;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	void unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
	}
}S;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		cls(w);ps=1;
		rep(i,1,n)ed[i][0]=++ps,ed[i][1]=++ps;
		S.clear();
		rep(i,1,m){int x,y;scanf("%d%d",&x,&y);++x;++y;w[x][y]=1;S.unio(ed[x][1],ed[y][0]);}
		bool ans=1;
		rep(i,1,n)rep(j,1,n)if(w[i][j]!=(S.find(ed[i][1])==S.find(ed[j][0])))ans=0;
		if(ans)puts("Yes");else puts("No");
	}
	return 0;
}
