#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<assert.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double real;
const int N=1000+10;
const real eps=1e-5,pi=acos(-1);
inline void up(real&x,real y){if(y>x)x=y;}
inline int sqr(int x){return x*x;}
inline real sqr(real x){return x*x;}
int n;
struct Interval{
	real l,r;
	Interval(){}
	Interval(real l,real r):l(l),r(r){}
}iv[N<<1];
bool operator<(const Interval&a,const Interval&b){return a.l<b.l;}
struct Point{
	real x,y;
	void input(){
		double _x,_y;scanf("%lf%lf",&_x,&_y);
		x=_x;y=_y;
	}
	Point(){}
	Point(real x,real y):x(x),y(y){}
	real sqr_length(){return x*x+y*y;}
	real length(){return sqrt(x*x+y*y);}
};
Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
real operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
real operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
bool del[N];
struct Circle{
	Point o;
	real r;
	void input(){
		o.input();
		double tmp;scanf("%lf",&tmp);
		r=tmp;
	}
	real area(real angle=2*pi){return r*r*angle/2;}
	bool inside(const Circle&x){return r>=x.r&&(x.o-o).sqr_length()<=sqr(r-x.r);}
	bool hasIntersection(const Circle&x){return (x.o-o).sqr_length()<=sqr(r+x.r);}
	inline real ck(real x){if(x<0)x+=2*pi;if(x>2*pi)x-=2*pi;return x;}
	real getAngle(real a,real b,real c){
		real ret=acos(a/c);
		if(b<0)ret=2*pi-ret;
		return ret;
	}
	Interval getIntersectionAngle(const Circle&x){
		real l=(x.o-o).length();
		real angle=getAngle(x.o.x-o.x,x.o.y-o.y,l);
		real cita=acos((x.r*x.r-r*r-l*l)/(-2*l*r));
		return Interval(ck(angle-cita),ck(angle+cita));
	}
	Point AnglePoint(real angle){
		return o+Point(r*cos(angle),r*sin(angle));
	}
}O[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)O[i].input();
	rep(i,1,n)rep(j,1,n)if(i!=j&&!del[j])if(O[j].inside(O[i]))del[i]=1;
	int tot=0;
	rep(i,1,n)if(!del[i])O[++tot]=O[i];
	n=tot;
	real ans=0;
	rep(i,1,n){
		tot=0;
		rep(j,1,n)if(i!=j&&O[i].hasIntersection(O[j])){
			iv[++tot]=O[i].getIntersectionAngle(O[j]);
			if(iv[tot].l>iv[tot].r){
				++tot;
				iv[tot]=Interval(iv[tot-1].l,2*pi);
				iv[tot-1].l=0;
			}
		}
		sort(iv+1,iv+1+tot);
		iv[tot+1].l=iv[1].l+2*pi;
		real tr=0;
		rep(j,1,tot){
			up(tr,iv[j].r);
			if(iv[j+1].l>tr+eps){
				real l=tr,r=iv[j+1].l;
				ans+=O[i].area(r-l)-O[i].r*O[i].r*sin(r-l)/2+O[i].AnglePoint(l)%O[i].AnglePoint(r)/2;
			}
		}
		if(tot==0)ans+=O[i].area();
	}
	printf("%.3lf",(double)ans);
	return 0;
}
