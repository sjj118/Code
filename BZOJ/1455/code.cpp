#include<bits/stdc++.h>
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e6+10;
int n,m,dead[maxn];
struct LeftistTree{
	int val[maxn],son[maxn][2],dis[maxn],pa[maxn];
	void update(int k){
		if(dis[ls]<dis[rs])swap(ls,rs);
		dis[k]=dis[ls]+1;
	}
	int merge(int a,int b){
		if(a==0||b==0)return a+b;
		if(val[a]>val[b])swap(a,b);
		son[a][1]=merge(son[a][1],b);
		update(a);
		return a;
	}
	void del(int k){
		int f=merge(ls,rs);
		pa[k]=f;pa[f]=f;
		dead[k]=1;
	}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	void unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return;
		if(val[a]>val[b])swap(a,b);
		pa[b]=a;
		merge(a,b);
	}
}T;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&T.val[i]),T.pa[i]=i;
	scanf("%d",&m);
	while(m--){
		char op;scanf("\n%c",&op);
		if(op=='M'){
			int x,y;scanf("%d%d",&x,&y);
			if(dead[x]||dead[y])continue;
			T.unio(x,y);
		}else{
			int x;scanf("%d",&x);
			if(dead[x])puts("0");
			else printf("%d\n",T.val[T.find(x)]),T.del(T.find(x));
		}
	}
	return 0;
}
