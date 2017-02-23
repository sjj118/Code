#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10;
typedef double real;
int n,m;
struct Point{
	real x,y;
	Point(){}
	Point(real x,real y):x(x),y(y){}
	friend Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
	friend Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
	friend Point operator*(const Point&a,real t){return Point(a.x*t,a.y*t);}
	friend Point operator*(real t,const Point&a){return Point(a.x*t,a.y*t);}
	friend real operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
	friend real operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
};
int main(){
	scanf("%d%d",&n,&m);
	return 0;
}
