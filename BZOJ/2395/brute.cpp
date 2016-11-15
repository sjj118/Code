#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int M=1e4+10,N=200+10;
int n,m;
struct Edge{
	int a,b,c,t;
}e[M];
int sel[N];
struct UFS{
	int pa[N],rank[N];
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	bool unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return 0;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
		return 1;
	}
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0;}
}S;
LL ansc=1e6,anst=1e6;
void dfs(int k,int last){
	if(k==n){
		S.clear();
		rep(i,1,n-1)if(!S.unio(e[sel[i]].a,e[sel[i]].b))return;
		LL c=0,t=0;
		rep(i,1,n-1)c+=e[sel[i]].c,t+=e[sel[i]].t;
		if(c*t<ansc*anst||c*t==ansc*anst&&c<ansc)ansc=c,anst=t;
		return;
	}
	rep(i,last+1,m-n+1+k)sel[k]=i,dfs(k+1,i);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d%d%d%d",&e[i].a,&e[i].b,&e[i].c,&e[i].t),++e[i].a,++e[i].b;
	dfs(1,0);
	printf("%lld %lld",ansc,anst);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
