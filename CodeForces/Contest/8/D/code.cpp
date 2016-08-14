#include<bits/stdc++.h>
#define ppp pair<Point,Point>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long double LB;
const double eps=1e-10;
int t1,t2;
int dblcmp(double x){if(fabs(x)<=eps)return 0;return x>0?1:-1;}
double sqr(double x){return x*x;}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
	void read(){double a,b;scanf("%lf%lf",&a,&b);x=a;y=b;}
}a,b,c;
double dis(Point a,Point b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
Point operator+(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
double operator^(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
struct Circle{
	Point o;
	double r;
	Circle(Point _o=Point(),double _r=0){o=_o;r=_r;}
	bool inside(Point p){return dblcmp(r-dis(p,o))>=0;}
	bool inside(Circle a){return dblcmp(r-a.r-dis(o,a.o))>=0;}
};
struct Line{
	double a,b,c;
	Line(double _a=0,double _b=0,double _c=0){a=_a;b=_b;c=_c;}
	Line(Point x,Point y){a=y.y-x.y,b=x.x-y.x,c=y^x;}
};
Point getInter(Line a,Line b){
	return Point((b.c*a.b-a.c*b.b)/(a.a*b.b-b.a*a.b),(b.c*a.a-a.c*b.a)/(b.a*a.b-a.a*b.b));
}
bool hasCommon(Circle a,Circle b){return dblcmp(a.r+b.r-dis(a.o,b.o))>=0;}
double disl(Line a,Point b){
	return sqr(a.a*b.x+a.b*b.y+a.c)/(sqr(a.a)+sqr(a.b));
}
ppp getInter(Circle a,Circle b){
	Line l(2*(b.o.x-a.o.x),2*(b.o.y-a.o.y),-(sqr(a.r)-sqr(b.r)-sqr(a.o.x)+sqr(b.o.x)-sqr(a.o.y)+sqr(b.o.y)));
	Line tmp(a.o,b.o);
	Point alpha=getInter(l,Line(a.o,b.o));
	double len=sqrt(sqr(a.r)-disl(l,a.o));
	if(l.a){
		double y=len/sqrt((sqr(l.b)/sqr(l.a)+1));
		Point delta(-l.b*y/l.a,y);
		return mp(alpha+delta,alpha-delta);
	}else{
		double x=len/sqrt((sqr(l.a)/sqr(l.b)+1));
		Point delta(x,-x*l.a/l.b);
		return mp(alpha+delta,alpha-delta);
	}
}
bool hasCommon(Circle a,Circle b,Circle c){
	if(!hasCommon(a,b)||!hasCommon(a,c)||!hasCommon(b,c))return 0;
	if(a.inside(b)||a.inside(c)||b.inside(a)||b.inside(c)||c.inside(a)||c.inside(b))return 1;
	ppp inter=getInter(b,c);
	if(a.inside(inter.fi)||a.inside(inter.se))return 1;
	inter=getInter(a,b);
	if(c.inside(inter.fi)||c.inside(inter.se))return 1;
	inter=getInter(a,c);
	if(b.inside(inter.fi)||b.inside(inter.se))return 1;
	return 0;
}
int main(){
	scanf("%d%d",&t1,&t2);
	a.read();b.read();c.read();
	if(dis(a,b)+t2>=dis(a,c)+dis(c,b)){printf("%lf",(min(t1+dis(a,c)+dis(c,b),t2+dis(a,b))));return 0;}
	double l=0,r=min(dis(a,c)+t1,dis(a,b)+t2);
	while(r-l>eps){
		double m=(l+r)/2;
		if(hasCommon(Circle(a,m),Circle(b,dis(a,b)+t2-m),Circle(c,dis(a,c)+t1-m)))l=m;else r=m;
	}
	printf("%lf",(l));
	return 0;
}
