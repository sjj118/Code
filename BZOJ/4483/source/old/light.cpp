#include<iostream>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::fabs;
using std::sqrt;
typedef long double real;
const int N=10+3;
const real eps=1e-10,inf=1e100,pi=acos(-1);
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
struct Path{
	int a[30+5],n;
	Path(){n=0;}
	void ins(int x){a[++n]=x;}
	friend bool operator==(const Path&a,const Path&b){
		if(a.n!=b.n)return 0;
		rep(i,1,a.n)if(a.a[i]!=b.a[i])return 0;
		return 1;
	}
};
Point shoot(Segment l,int lst,Path&path){
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
	path.ins(id);
	Segment nw=Segment(inter,a[id].v.symm(l.p+l.v-inter));
	return shoot(nw,id,path);
}
Point shoot(real angle,real len,Path&path){
	return shoot(Segment(Point(0,0),len*Point(cos(angle),sin(angle))),-1,path);
}
real calc(real x,real y,real len){
	if(y-x<1e-15)return 0;
	static Path pax,pay;
	pax.n=pay.n=0;
	Point px=shoot(x,len,pax);
	Point py=shoot(y,len,pay);
	bool inx=a[0].isInside(px);
	bool iny=a[0].isInside(py);
	if(pax==pay&&inx&&iny){
		return fabs(px.x-py.x);
	}else if(inx||iny){
		real m=(x+y)/2;
		return calc(x,m,len)+calc(m,y,len);
	}else return 0;
}
real det(real x){
	return 1e-5;
}
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
	for(real i=pi/2-angle/2;i<=pi/2+angle/2;i+=det(angle)){
		ans+=calc(i,i+det(angle),len);
	}
	printf("%.4lf",(double)(ans/(a[0].length())));
	return 0;
}
