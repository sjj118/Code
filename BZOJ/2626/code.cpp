#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n;
struct Point{
	int c[2];
	Point(){}
	Point(int x,int y){c[0]=x;c[1]=y;}
}node[N];
bool operator<=(const Point&a,const Point&b){
	rep(i,0,1)if(a.c[i]>b.c[i])return 0;
	return 1;
}
#define ls son[k][0]
#define rs son[k][1]
int rt;
struct KDT{
	int son[N][2],val[N],sum[N];
	Point mn[N],mx[N];
	void update(int k){
		sum[k]=val[k]+sum[ls]+sum[rs];
		mn[k]=mx[k]=node[k];
		if(ls)rep(i,0,1)up(mx[k].c[i],mx[ls].c[i]),dn(mn[k].c[i],mn[ls].c[i]);
		if(rs)rep(i,0,1)up(mx[k].c[i],mx[rs].c[i]),dn(mn[k].c[i],mn[rs].c[i]);
	}
	void rebuild(int k){

	}
	void insert(int p,int v,int&k,int d){
		if(!k){k=p;sum[k]=val[k]=v;return;}
		if(node[p].c[d]<node[k].c[d])insert(p,v,ls,d^1);
		else insert(p,v,rs,d^1);
		update(k);
	}
	int query(const Point&ll,const Point&rr,int k,int d){
		if(ll<=mn[k]&&mx[k]<=rr)return sum[k];
		int ret=0;
		if(ll<=node[k]&&node[k]<=rr)ret+=val[k];
		if(ll.c[d]<=node[k].c[d])ret+=query(ll,rr,ls,d^1);
		if(rr.c[d]>=node[k].c[d])ret+=query(ll,rr,rs,d^1);
		return ret;
	}
}T;
int main(){
	scanf("%d",&n);
	int ans=0;
	int op;
	while(scanf("%d",&op)>0&&op!=3){
		if(op==1){
			int x,y,a;scanf("%d%d%d",&x,&y,&a);
			x^=ans;y^=ans;a^=ans;
			node[++n]=Point(x,y);
			T.insert(n,a,rt,0);
		}else{
			int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x1^=ans;y1^=ans;x2^=ans;y2^=ans;
			printf("%d\n",ans=T.query(Point(x1,y1),Point(x2,y2),rt,0));
		}
	}
	return 0;
}
