#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg inr i=(x);i>=(y);--i)

using std::fabs;
using std::sort;

typedef long double real;
const int N=1e5+10;
const real eps=1e-8,inf=1e10,pi=acos((real)-1);
inline real readreal(){double ret;scanf("%lf",&ret);return ret;}
int n,m,a[N],b[N],c[N];
int dblcmp(real x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
inline void up(real&x,real y){if(y>x)x=y;}
inline void dn(real&x,real y){if(y<x)x=y;}
struct Point{
	real x,y;
	Point(){}
	Point(real x,real y):x(x),y(y){}
	friend Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
	friend Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
	friend real operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
	friend real operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
	friend Point operator*(real a,const Point&b){return Point(a*b.x,a*b.y);}
	friend Point operator*(const Point&b,real a){return Point(a*b.x,a*b.y);}
};
struct Line{
	Point p,v;
	real alpha;
	Line(){}
	Line(const Point&p,const Point&v):p(p),v(v){alpha=atan2(v.y,v.x);}
	friend bool operator<(const Line&a,const Line&b){
		int t=dblcmp(b.alpha-a.alpha);
		return t>0||(t==0&dblcmp(b.v%(a.p-b.p))>0);
	}
	friend Point getIntersection(const Line&a,const Line&b){
		real t=b.v%(a.p-b.p)/(a.v%b.v);
		return a.p+a.v*t;
	}
}l[N];
struct Convex_Hull{
	Point p[N];
	int n;
	void half_plane(Line*l,int tot){
		l[++tot]=Line(Point(-inf,-inf),Point(inf,0));
		//l[++tot]=Line(Point(inf,-inf),Point(inf,inf));
		//l[++tot]=Line(Point(inf,inf),Point(-inf,inf));
		l[++tot]=Line(Point(-inf,inf),Point(0,-inf));
		sort(l+1,l+1+tot);
		n=1;rep(i,2,tot)if(dblcmp(l[i].alpha-l[n].alpha))l[++n]=l[i];
		tot=n;
		static Line q[N];
		n=0;
		rep(i,1,tot){
			while(n>1&&dblcmp((getIntersection(q[n],q[n-1])-l[i].p)%l[i].v)>=0)--n;
			q[++n]=l[i];
		}
		rep(i,1,n-1)p[i]=getIntersection(q[i],q[i+1]);
		--n;
	}
	real query(const Point&s){
		int l=1,r=n;
		while(r-l>5){
			int h3=(r-l)/3;
			int m1=l+h3,m2=r-h3;
			if(dblcmp(s*p[m1]-s*p[m2])<0)r=m2;else l=m1;
		}
		real ret=inf;
		rep(i,l,r)dn(ret,s*p[i]);
		return ret;
	}
}conv;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		real a=readreal(),b=readreal(),c=readreal();
		l[i]=Line(Point(0,c/b),Point(10000,-a*10000/b));
	}
	conv.half_plane(l,n);
	rep(i,1,m){
		real s=readreal(),t=readreal();
		real ans=conv.query(Point(s,t));
		if(dblcmp(ans)<=0)puts("IMPOSSIBLE");
		else printf("%.5lf\n",(double)ans);
	}
	return 0;
}
