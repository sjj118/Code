#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
const int maxn=1550;
using namespace std;
int n,k,ans;
inline int sqr(int x){return x*x;}
inline int get(int x,int y){if(x==0||y==0||x==n||y==n)return 0;return (x-1)*(n-1)+y;}
struct UFS{
	int pa[maxn*maxn],rank[maxn*maxn];
	void init(){rep(i,0,sqr(n-1))pa[i]=i,rank[i]=0;}
	int find(int k){return ((pa[k]==k)?k:(pa[k]=find(pa[k])));}
	bool unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return 1;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
		return 0;
	}
}set;

int main(){
	scanf("%d%d\n",&n,&k);set.init();
	rep(i,1,k){
		int a,b,e,f;char c,g;
		if(ans)scanf("\n%d%d %c %d%d %c",&e,&f,&g,&a,&b,&c);
		else scanf("\n%d%d %c %d%d %c",&a,&b,&c,&e,&f,&g);
		if(c=='N')e=a,f=b,a=a-1;else e=a,f=b,b=b-1;
		ans=set.unio(get(a,b),get(e,f));
		if(ans)printf("NIE\n");else printf("TAK\n");
	}
	return 0;
}
