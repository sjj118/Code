#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::sort;
using std::fabs;
using std::sqrt;
typedef double real;
const int N=4e5+10;
const real eps=1e-9,inf=1e100,pi=acos(-1);
inline void up(real&x,real y){if(y>x)x=y;}
inline int dblcmp(real x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
inline real read(){double x;scanf("%lf",&x);return x;}
int n;
struct Point{
	real x,y;
	Point(){}
	Point(real x,real y):x(x),y(y){}
	inline void input(){
		x=read();y=read();
	}
	inline void output(){
		printf("%lf %lf\n",(double)x,(double)y);
	}
	friend Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
	friend Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
	friend Point operator*(const Point&a,real t){return Point(a.x*t,a.y*t);}
	friend Point operator*(real t,const Point&a){return Point(a.x*t,a.y*t);}
	friend real operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
	friend real operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
	real length(){return sqrt(x*x+y*y);}
	const real getAngle()const{
		return atan2(y,x);
	}
	Point rotate(real angle)const{
		return Point(x*cos(angle)-y*sin(angle),y*cos(angle)+x*sin(angle));
	}
	Point symm(const Point p){
		return p.rotate(2*(this->getAngle()-p.getAngle()));
	}
};
struct Line{
	Point p,v;
	Line(){}
	Line(const Point&p,const Point&v):p(p),v(v){}
	real length(){return v.length();}
	bool isInside(const Point x)const{
		return dblcmp((x-p)%v)==0&&dblcmp((x-p)*(p+v-x))>=0;
	}
	friend Point getIntersection(const Line&a,const Line&b){
		real t=b.v%(a.p-b.p)/(a.v%b.v);
		return a.p+t*a.v;
	}
	friend bool hasIntersection(const Line&a,const Line&b){
		return dblcmp(a.v%b.v);
	}
};
struct Segment:Line{
	Segment(){};
	Segment(const Point&p,const Point&v){this->p=p;this->v=v;}
	friend bool hasIntersection(const Segment&a,const Segment&b){
		if(dblcmp(a.v%b.v)==0)return 0;
		Point p=getIntersection(a,b);
		return a.isInside(p)&&b.isInside(p);
	}
};
struct Zhangai:Segment{
	int ref;
}a[N];
Point shoot(Segment l,int lst){
	Point inter;
	real dis=inf;
	int id=-1;
	rep(i,0,n)if(i!=lst&&hasIntersection(l,a[i])){
		Point _inter=getIntersection(l,a[i]);
		real _dis=(_inter-l.p).length();
		if(_dis<dis-eps)dis=_dis,inter=_inter,id=i;
	}
	if(id==-1)return l.p+l.v;
	if(!a[id].ref)return inter;
	Segment nw=Segment(inter,a[id].v.symm(l.p+l.v-inter));
	return shoot(nw,id);
}
Point shoot(real angle,real len){
	return shoot(Segment(Point(0,0),len*Point(cos(angle),sin(angle))),-1);
}
real p[N];
int main(){
	//freopen("d.in","r",stdin);freopen("d.out","w",stdout);
	real angle,len;
	scanf("%d",&n);
	angle=read();len=read();
	rep(i,1,n){
		Point x,y;x.input();y.input();
		a[i].p=x;a[i].v=y-x;
		scanf("%d",&a[i].ref);
	}
	Point x,y;x.input();y.input();
	a[0].p=x;a[0].v=y-x;a[0].ref=0;
	angle=angle/180*pi;
	real ans=0;
	real det=angle/400000;
	int tot=0;
	for(real i=pi/2-angle/2;i<=pi/2+angle/2;i+=det){
		Point o=shoot(i,len);
		if(a[0].isInside(o))p[++tot]=o.x;
	}
	real st=0,ed=0;
	real part=a[0].v.x/1e4;
	sort(p+1,p+1+tot);
	rep(i,1,tot-1)if(p[i+1]-p[i]<part)ans+=p[i+1]-p[i];
	printf("%.4lf",(double)(ans/(a[0].length())));
	return 0;
}
