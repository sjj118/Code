
#include<iostream>
#include<assert.h>
#include<ctime>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10;
const double alpha=0.63;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,ans;
struct Point{
	int c[2];
	Point(){}
	Point(int x,int y){c[0]=x;c[1]=y;}
}node[N];
inline bool operator<=(const Point&a,const Point&b){
	return a.c[0]<=b.c[0]&&a.c[1]<=b.c[1];
	//rep(i,0,1)if(a.c[i]>b.c[i])return 0;
	//return 1;
}
#define ls son[k][0]
#define rs son[k][1]
int rt;
int D;
bool cmp(int a,int b){return node[a].c[D]<node[b].c[D];}
struct KDT{
	int tot,son[N][2],val[N],sum[N],size[N];
	Point mn[N],mx[N];
	void update(int k){
		size[k]=1+size[ls]+size[rs];
		sum[k]=val[k]+sum[ls]+sum[rs];
		mn[k]=mx[k]=node[k];
		if(ls)rep(i,0,1)up(mx[k].c[i],mx[ls].c[i]),dn(mn[k].c[i],mn[ls].c[i]);
		if(rs)rep(i,0,1)up(mx[k].c[i],mx[rs].c[i]),dn(mn[k].c[i],mn[rs].c[i]);
	}
	int v[N],t;
	void travel(int k){
		if(ls)travel(ls);
		v[++t]=k;
		if(rs)travel(rs);
	}
	//struct cmp{
	//	int d;
	//	cmp(int d):d(d){}
	//	bool operator()(int a,int b){return node[a].c[d]<node[b].c[d];}
	//};
	int build(int l,int r,int d){
		int m=(l+r)>>1;
		D=d;
		nth_element(v+l,v+m,v+r+1,cmp);
		int k=v[m];
		ls=rs=0;
		if(l<m)ls=build(l,m-1,d^1);
		if(m<r)rs=build(m+1,r,d^1);
		update(k);
		return k;
	}
	int rebuild(int k,int d){
		t=0;travel(k);
		return build(1,t,d);
	}
	void insert(const Point&p,int v,int&k,int d){
		if(!k){node[k=++tot]=p;val[k]=v;update(k);return;}
		if(p.c[d]<node[k].c[d]){
			insert(p,v,ls,d^1);
			update(k);
			//if(size[ls]>size[k]*alpha)k=rebuild(k,d);
		}else{ 
			insert(p,v,rs,d^1);
			update(k);
			//if(size[rs]>size[k]*alpha)k=rebuild(k,d);
		}
	}
	int query(const Point&ll,const Point&rr,int k){
		if(ll<=mn[k]&&mx[k]<=rr)return sum[k];
		int ret=0;
		if(ll<=node[k]&&node[k]<=rr)ret+=val[k];
		if(ls&&mn[ls]<=rr&&ll<=mx[ls])ret+=query(ll,rr,ls);
		if(rs&&mn[rs]<=rr&&ll<=mx[rs])ret+=query(ll,rr,rs);
		return ret;
	}
	int zhao(int k,int x1,int y1,int x2,int y2) {
		if(mn[k].c[0]>=x1&&mn[k].c[1]>=y1&&mx[k].c[0]<=x2&&mx[k].c[1]<=y2)
		  return sum[k];
		if(mn[k].c[0]>x2||mn[k].c[1]>y2||mx[k].c[0]<x1||mx[k].c[1]<y1)
		  return 0;
		int tmp=0;
		if(node[k].c[0]>=x1&&node[k].c[1]>=y1&&node[k].c[0]<=x2&&node[k].c[1]<=y2)
		  tmp+=val[k];
		return tmp+zhao(ls,x1,y1,x2,y2)+zhao(rs,x1,y1,x2,y2);
	}
}T;
int main(){
	n=read();
	int op,blo=10000;
	while((op=read())!=3){
		if(op==1){
			int x=read(),y=read(),a=read();
			//x^=ans;y^=ans;a^=ans;
			T.insert(Point(x,y),a,rt,0);
			if(--blo==0){
				blo=10000;
				rt=T.rebuild(rt,0);
			}
		}else{
			int x1=read(),y1=read(),x2=read(),y2=read();
			//x1^=ans;y1^=ans;x2^=ans;y2^=ans;
			//printf("%d\n",ans=T.query(Point(x1,y1),Point(x2,y2),rt));
			printf("%d\n",ans=T.zhao(rt,x1,y1,x2,y2));
		}
	}
	return 0;
}
