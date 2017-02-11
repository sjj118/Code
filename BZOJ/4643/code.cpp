#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::sort;
typedef unsigned int UI;
const int N=150+10,inf=2e9+7;
inline void dn(int&x,int y){if(y<x)x=y;}
int n;
bool cmp(int*a,int*b){return*a<*b;}
struct Lisan{
	int tot,*val[N*N],ml,rl[N*N];
	void clear(){tot=ml=0;}
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,cmp);
		for(int i=1,lst=-1;i<=tot;++i){
			if(*val[i]>lst)rl[++ml]=lst=*val[i];
			*val[i]=ml;
		}
	}
}la,lb;
struct LinkMap{
	int tot,head[N*N],next[N*N],to[N*N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
}lpa,lpb;
struct Bitset{
	UI v[N>>5];
	int get(int x){return v[x>>5]>>(x&31)&1;}
	void set(int x){v[x>>5]|=1<<(x&31);}
	void flip(int x){v[x>>5]^=1<<(x&31);}
	void reset(int x){set(x);flip(x);}
	void clear(){cls(v);}
};
int pa,pb;
int w[N][N],a[N][N],b[N][N];
void adda(int k){
	for(int p=lpa.head[k];p;p=lpa.next[p]){
		int x=lpa.to[p]/n,y=lpa.to[p]%n;
		if(b[x][y]<=pb)w[x][y]=1;
	}
}
void delb(int k){
	for(int p=lpb.head[k];p;p=lpb.next[p]){
		int x=lpb.to[p]/n,y=lpb.to[p]%n;
		if(a[x][y]<=pa)w[x][y]=0;
	}
}
int clo;
Bitset dfn,vis;
void dfs1(int k){

}
bool isVaild(){
	dfn.clear();vis.clear();
	dfs1(0);
}
int main(){
	scanf("%d",&n);
	rep(i,0,n)rep(j,0,n)scanf("%d",&a[i][j]),la.ins(a[i][j]);
	rep(i,0,n)rep(j,0,n)scanf("%d",&b[i][j]),lb.ins(b[i][j]);
	la.work();lb.work();
	rep(i,0,n)rep(j,0,n)lpa.ins(a[i][j],i*n+j),lpb.ins(b[i][j],i*n+j);
	int ans=inf;
	pa=1,pb=lb.ml;
	rep(i,0,n)rep(j,0,n)w[i][j]=a[i][j]<=pa&&b[i][j]<=pb;
	for(;pa<=la.ml;adda(++pa)){
		while(isVaild())dn(ans,la.rl[pa]+lb.rl[pb]),delb(pb--);
	}
	printf("%d\n",ans);
	return 0;
}
