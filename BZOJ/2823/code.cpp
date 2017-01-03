#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double real;
const double eps=1e-6,pi=acos(-1);
const int N=1e6+10;
inline real readreal(){double x;scanf("%lf",&x);return x;}
inline int dblcmp(real x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
int n;
struct Point{
	real x,y;
	Point(){}
	Point(real x,real y):x(x),y(y){}
	void input(){x=readreal();y=readreal();}
	real length2(){return x*x+y*y;}
	real length(){return sqrt(x*x+y*y);}
	Point rotate(real a){return Point(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));}
}p[N];
Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
Point operator*(real p,const Point&a){return Point(p*a.x,p*a.y);}
Point operator*(const Point&a,real p){return Point(p*a.x,p*a.y);}
real operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
real operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
struct Line{
	Point p,v;
	Line(){}
	Line(const Point&p,const Point&v):p(p),v(v){}
};
Point getIntersection(const Line&a,const Line&b){
	double t=b.v%(a.p-b.p)/(a.v%b.v);
	return a.p+a.v*t;
}
struct Circle{
	Point o;
	real r;
	Circle(){}
	Circle(Point o,real r):o(o),r(r){}
	bool inside(const Point&a){return dblcmp((a-o).length2()-r*r)<=0;}
	void output(){
		printf("%.2lf %.2lf %.2lf",(double)o.x,(double)o.y,(double)r);
	}
};
Circle getCircle(const Point&a,const Point&b,const Point&c){
	Point o=getIntersection(Line((a+b)*0.5,(b-a).rotate(pi/2)),Line((b+c)*0.5,(c-b).rotate(pi/2)));
	return Circle(o,(o-a).length());
}
Circle findMinCircle(){
	random_shuffle(p+1,p+1+n);
	Circle ret=Circle(p[1],0);
	rep(i,1,n)if(!ret.inside(p[i])){
		ret=Circle(p[i],0);
		rep(j,1,i-1)if(!ret.inside(p[j])){
			ret=Circle(0.5*(p[i]+p[j]),0.5*(p[i]-p[j]).length());
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
	findMinCircle().output();
	return 0;
}
