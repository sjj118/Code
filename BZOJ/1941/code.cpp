#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=5e5+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n;
bool cmp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[N],ml,rl[N];
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,cmp);
		for(int i=1,lst=-inf;i<=tot;++i){
			if(*val[i]>lst)lst=rl[++ml]=*val[i];
			*val[i]=ml;
		}
	}
	void clear(){tot=ml=0;}
}li;
struct Point{
	int x,y,mx,mn;
	Point(){}
	Point(int x,int y):x(x),y(y){}
	void input(){
		scanf("%d%d",&x,&y);
	}
	void rotate(){swap(x,y);x=-x;}
}p[N];
bool operator<(const Point&a,const Point&b){return a.y<b.y||(a.y==b.y&&a.x<b.x);}
inline int lowbit(int x){return x&(-x);}
struct MaxBit{
	int arr[N<<1];
	void clear(){rep(i,1,li.ml)arr[i]=-inf;}
	void set(int x,int y){
		for(;x<=li.ml;x+=lowbit(x))up(arr[x],y);
	}
	int get(int x){
		int ret=-inf;
		for(;x;x-=lowbit(x))up(ret,arr[x]);
		return ret;
	}
}mb;
struct MinBit{
	int arr[N<<1];
	void clear(){rep(i,1,li.ml)arr[i]=inf;}
	void set(int x,int y){
		for(;x<=li.ml;x+=lowbit(x))dn(arr[x],y);
	}
	int get(int x){
		int ret=inf;
		for(;x;x-=lowbit(x))dn(ret,arr[x]);
		return ret;
	}
}ma;
int main(){
	scanf("%d",&n);
	rep(i,1,n)p[i].input();
	rep(i,1,n)p[i].mx=-inf,p[i].mn=inf;
	rep(coo,1,4){
		rep(i,1,n)p[i].rotate();
		sort(p+1,p+1+n);
		li.clear();
		rep(i,1,n)li.ins(p[i].x);
		li.work();
		ma.clear();mb.clear();
		rep(i,1,n){
			up(p[i].mx,li.rl[p[i].x]+p[i].y-ma.get(p[i].x));
			dn(p[i].mn,li.rl[p[i].x]+p[i].y-mb.get(p[i].x));
			mb.set(p[i].x,li.rl[p[i].x]+p[i].y);
			ma.set(p[i].x,li.rl[p[i].x]+p[i].y);
		}
		rep(i,1,n)p[i].x=li.rl[p[i].x];
	}
	int ans=inf;
	rep(i,1,n)dn(ans,p[i].mx-p[i].mn);
	printf("%d",ans);
	return 0;
}
