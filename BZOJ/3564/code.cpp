#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double real;
const int N=50000+10;
const real eps=1e-6,pi=acos(-1);
inline real readreal(){double x;scanf("%lf",&x);return x;}
inline int dblcmp(real x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
inline real sqr(real x){return x*x;}
int n;
struct Point{
	real x,y;
	Point(){}
	Point(real x,real y):x(x),y(y){}
	void input(){x=readreal();y=readreal();}
	Point rotate(real a){return Point(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));}
	real length2(){return x*x+y*y;}
	real length(){return sqrt(x*x+y*y);}
}p[N];
Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
Point operator*(real b,const Point&a){return Point(a.x*b,a.y*b);}
Point operator*(const Point&a,real b){return Point(a.x*b,a.y*b);}
real operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
real operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
struct Line{
	Point p,v;
	Line(){}
	Line(const Point&p,const Point&v):p(p),v(v){}
};
Point getIntersection(const Line&a,const Line&b){
	real t=b.v%(a.p-b.p)/(a.v%b.v);
	return a.p+a.v*t;
}
struct Circle{
	Point o;
	real r;
	Circle(){}
	Circle(const Point&o,real r):o(o),r(r){}
	bool inside(const Point&p){return dblcmp(r*r-(p-o).length2())>=0;}
};
Circle getCircle(const Point&a,const Point&b,const Point&c){
	Point o=getIntersection(Line((a+b)*0.5,(a-b).rotate(pi/2)),Line((a+c)*0.5,(a-c).rotate(pi/2)));
	return Circle(o,(a-o).length());
}
Circle getMinCircle(){
	random_shuffle(p+1,p+1+n);
	Circle ret=Circle(p[1],0);
	rep(i,1,n)if(!ret.inside(p[i])){
		ret=Circle(p[i],0);
		rep(j,1,i-1)if(!ret.inside(p[j])){
			ret=Circle((p[i]+p[j])*0.5,(p[i]-p[j]).length()/2);
			rep(k,1,j-1)if(!ret.inside(p[k])){
				ret=getCircle(p[i],p[j],p[k]);
			}
		}
	}
	return ret;
}
int main(){
	srand(20000107);
	scanf("%d",&n);
	rep(i,1,n)p[i].input();
	real a=readreal(),q=readreal();
	Line l=Line(Point(0,0),Point(cos(a*pi/180+pi/2),sin(a*pi/180+pi/2)));
	Point v=Point(cos(a*pi/180),sin(a*pi/180));
	rep(i,1,n){
		Point o=getIntersection(l,Line(p[i],v));
		p[i]=o+1.0/q*(p[i]-o);
	}
	printf("%.3lf",(double)getMinCircle().r);
	return 0;
}
