#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=2e4+10,M=2e5+10,inf=1e9;
int n,m,u,v,l,ans=inf;
struct Edge{
	int u,v,w;
}e[M];
bool operator<(const Edge&a,const Edge&b){return a.w<b.w;}
bool del[M];
struct UFS{
	int pa[N],rank[N];
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	bool unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return 0;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
		return 1;
	}
}S;
bool MinST(){
	S.clear();
	rep(i,1,m+1)if(!del[i]){
		if(l<=e[i].w)return S.unio(u,v);
		S.unio(e[i].u,e[i].v);
	}
	return 0;
}
bool MaxST(){
	S.clear();
	per(i,m,0)if(!del[i]){
		if(l>=e[i].w)return S.unio(u,v);
		S.unio(e[i].u,e[i].v);
	}
	return 0;
}
void dfs(int k){
	if(k==m+1){
		if(MinST()&&MaxST()){
			int tmp=0;
			rep(i,1,m)tmp+=del[i];
			ans=min(ans,tmp);
		}
		return;
	}
	del[k]=0;dfs(k+1);
	del[k]=1;dfs(k+1);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+1+m);
	e[m+1].w=inf;
	scanf("%d%d%d",&u,&v,&l);
	dfs(1);
	printf("%d",ans);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
