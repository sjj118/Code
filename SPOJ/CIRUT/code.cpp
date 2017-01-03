#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double real;
const int N=1000+10;
const real eps=1e-10,pi=acos(-1);
inline real readreal(){double ret;scanf("%lf",&ret);return ret;}
inline real sqr(real x){return x*x;}
inline real ck(real x,real p){if(x<0)x+=p;if(x>p)x-=p;return x;}
inline void up(real&x,real y){if(y>x)x=y;}
inline int dblcmp(real x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
int n,cover[N];
struct Point{
	real x,y;
	Point(){}
	Point(real x,real y):x(x),y(y){}
	void input(){
		x=readreal();y=readreal();
	}
	real length(){return sqrt(x*x+y*y);}
	real sqr_length(){return x*x+y*y;}
};
bool operator<(const Point&a,const Point&b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator==(const Point&a,const Point&b){return dblcmp(a.x-b.x)==0&&dblcmp(a.y-b.y)==0;}
Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
real operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
real operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
struct Interval{
	real l,r;
	Interval(){}
	Interval(real l,real r):l(l),r(r){}
}iv[N<<1];
bool operator<(const Interval&a,const Interval&b){return a.l<b.l;}
struct Circle{
	Point o;
	real r;
	void input(){
		o.input();
		r=readreal();
	}
	bool inside(const Circle&x){return x.r<r+eps&&sqr(r-x.r)>(o-x.o).sqr_length()-eps;}
	bool hasIntersection(const Circle&x){return sqr(x.r+r)+eps>(o-x.o).sqr_length()&&sqr(r-x.r)<(o-x.o).sqr_length()-eps;}
	real getAngle(real a,real b,real c){
		real ret=acos(a/c);
		if(b<0)ret=2*pi-ret;
		return ret;
	}
	Interval getIntersectionAngle(const Circle&x){
		real l=(x.o-o).length();
		real angle=getAngle(x.o.x-o.x,x.o.y-o.y,l);
		real cita=acos((r*r+l*l-x.r*x.r)/2/l/r);
		return Interval(ck(angle-cita,2*pi),ck(angle+cita,2*pi));
	}
	real area(real angle=2*pi){return r*r*angle/2;}
	Point AnglePoint(real angle){return o+Point(r*cos(angle),r*sin(angle));}
}O[N];
bool operator<(const Circle&a,const Circle&b){return a.o<b.o||(a.o==b.o&&a.r<b.r);}
bool operator==(const Circle&a,const Circle&b){return a.o==b.o&&a.r==b.r;}
real area[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)O[i].input();
	sort(O+1,O+1+n);
	n=unique(O+1,O+1+n)-O-1;
	rep(i,1,n)rep(j,1,n)if(O[i].inside(O[j]))++cover[j];
	rep(i,1,n){
		int tot=0;
		rep(j,1,n)if(O[i].hasIntersection(O[j])){
			iv[++tot]=O[i].getIntersectionAngle(O[j]);
			if(iv[tot].l>iv[tot].r+eps){
				++tot;
				iv[tot]=Interval(iv[tot-1].l,2*pi);
				iv[tot-1].l=0;
			}
		}
		static pair<real,int> q[N<<2];
		rep(j,1,tot)q[j*2-1]=mp(iv[j].l,1),q[j*2]=mp(iv[j].r,-1);
		sort(q+1,q+1+tot*2);
		q[0]=mp(0,0);
		q[tot*2+1]=mp(2*pi,0);
		int cov=0;
		rep(j,0,tot*2){
			cov+=q[j].se;
			real now=q[j].fi;
			real nxt=q[j+1].fi;
			real tmp=O[i].area(nxt-now)-sqr(O[i].r)*sin(nxt-now)/2+O[i].AnglePoint(now)%O[i].AnglePoint(nxt)/2;
			area[cover[i]+cov]+=tmp;
			area[cover[i]+cov-1]-=tmp;
		}
	}
	rep(i,1,n)printf("[%d] = %.3lf\n",i,(double)area[i]);
	return 0;
}
