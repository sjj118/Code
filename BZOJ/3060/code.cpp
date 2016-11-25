#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e6+10,M=2e6+10;
int n,m,k,p,v,c;
bool vis[N];
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
}S,G;
int main(){
	scanf("%d%d%d",&n,&m,&k);p=n;
	S.clear();G.clear();
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		G.unio(a,b);
		if(a>k&&b>k){
			if(S.unio(a,b))--p;
		}else ++v;
	}
	rep(i,1,n)if(!vis[G.find(i)])++c,vis[G.find(i)]=1;
	printf("%d",v-p+c);
	return 0;
}
