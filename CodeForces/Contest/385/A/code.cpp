#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000+10,M=1e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,k,c[N],v[N];
struct UFS{
	int pa[N],rank[N],size[N];
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0,size[i]=1;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	void unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return;
		if(rank[a]<rank[b])swap(a,b);
		pa[b]=a;
		if(rank[a]==rank[b])++rank[a];
		size[a]+=size[b];
	}
}S;
int maxsize,ans;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	S.clear();
	rep(i,1,k)scanf("%d",&c[i]);
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);S.unio(u,v);}
	rep(i,1,k){
		c[i]=S.find(c[i]);
		v[c[i]]=1;
		up(maxsize,S.size[c[i]]);
		ans+=S.size[c[i]]*(S.size[c[i]]-1)/2;
	}
	rep(i,1,n)if(!v[S.find(i)]){
		ans+=maxsize;
		++maxsize;
	}
	printf("%d",ans-m);
	return 0;
}
