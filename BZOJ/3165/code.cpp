#include<iostream>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::max;
using std::swap;
using std::fabs;
typedef long long LL;
typedef double real;
const int N=4e4+10,n=39989,inf=1e9,P=N<<2;
const real eps=1e-10;
inline int dblcmp(real x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
int m,ans,ps;
struct Point{
	real x,y;
	Point(){}
	Point(real x,real y):x(x),y(y){}
	friend Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
	friend Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
	friend Point operator*(const Point&a,real b){return Point(a.x*b,a.y*b);}
	friend Point operator*(real b,const Point&a){return Point(a.x*b,a.y*b);}
	friend real operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
	friend real operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
};
struct Line{
	Point p,v;
	int id;
	Line(){}
	Line(int id,const Point&p,const Point&v):id(id),p(p),v(v){}
	friend Point operator*(const Line&a,const Line&b){
		real t=b.v%(a.p-b.p)/(a.v%b.v);
		return a.p+t*a.v;
	}
	real operator()(real x)const{
		if(!id)return 0;
		if(fabs(v.x)<eps)return p.y;
		return (p+(x-p.x)/v.x*v).y;
	}
};
bool cmp(int x,const Line&a,const Line&b){
	int t=dblcmp(a(x)-b(x));
	return t==1||(t==0&&a.id<b.id);
}
Line higher(int x,const Line&a,const Line&b){
	return cmp(x,a,b)?a:b;
}
#define ls (k<<1)
#define rs (k<<1|1)
struct SGT{
	Line data[P];
	void insert(int ll,int rr,const Line&v,int k,int l,int r){
		if(ll<=l&&r<=rr){
			int t1=cmp(l,data[k],v),t2=cmp(r,data[k],v);
			if(t1==0&&t2==0){
				data[k]=v;
			}else if(t1==1&&t2==0){
				Point p=data[k]*v;
				int m=(l+r)>>1;
				if(p.x+eps<=m)insert(ll,rr,data[k],ls,l,m),data[k]=v;
				else insert(ll,rr,v,rs,m+1,r);
			}else if(t1==0&&t2==1){
				Point p=data[k]*v;
				int m=(l+r)>>1;
				if(p.x+eps<=m)insert(ll,rr,v,ls,l,m);
				else insert(ll,rr,data[k],rs,m+1,r),data[k]=v;
			}
			return;
		}
		int m=(l+r)>>1;
		if(ll<=m)insert(ll,rr,v,ls,l,m);
		if(rr>m)insert(ll,rr,v,rs,m+1,r);
	}
	Line query(int p,int k,int l,int r){
		if(l==r)return data[k];
		int m=(l+r)>>1;
		if(p<=m)return higher(p,data[k],query(p,ls,l,m));
		else return higher(p,data[k],query(p,rs,m+1,r));
	}
}T;
int main(){
	//freopen("code.in","r",stdin);
	scanf("%d",&m);
	rep(i,1,m){
		int op;scanf("%d",&op);
		if(op){
			int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x1=(x1+ans-1)%n+1;y1=(y1+ans-1)%inf+1;
			x2=(x2+ans-1)%n+1;y2=(y2+ans-1)%inf+1;
			if(x1>x2)swap(x1,x2),swap(y1,y2);
			if(x1==x2)y1=y2=max(y1,y2);
			T.insert(x1,x2,Line(++ps,Point(x1,y1),Point(x2-x1,y2-y1)),1,1,n);
		}else{
			int x;scanf("%d",&x);
			x=(x+ans-1)%n+1;
			printf("%d\n",ans=T.query(x,1,1,n).id);
		}
	}
	return 0;
}
