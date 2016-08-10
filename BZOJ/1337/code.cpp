#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=1e5+10;
const double eps=1e-8;
using namespace std;
inline double sqr(double x){return x*x;}
int n;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}p[maxn],o;
double r;
double dis(Point a,Point b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
Point operator+(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
Point operator/(Point a,double x){return Point(a.x/x,a.y/x);}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
double operator*(Point a,Point b){return a.x*b.x+a.y*b.y;}
int dblcmp(double x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
Point getO(Point a,Point b,Point c){
	if(dblcmp((b-a)^(c-a))){
		double A=2*(a.x-b.x),B=2*(a.y-b.y),C=sqr(a.x)+sqr(a.y)-sqr(b.x)-sqr(b.y);
		double D=2*(a.x-c.x),E=2*(a.y-c.y),F=sqr(a.x)+sqr(a.y)-sqr(c.x)-sqr(c.y);
		if(dblcmp(B)){
			double x=(F-C*E/B)/(D-A*E/B);
			return Point(x,(C-A*x)/B);
		}else{
			double y=(F-C*D/A)/(E-B*D/A);
			return Point((C-B*y)/A,y);
		}
	}else{
		if(dblcmp((b-a)*(c-a))<=0)return (b+c)/2;
		if(dblcmp((a-b)*(c-b))<=0)return (a+c)/2;
		return (a+b)/2;
	}
}

int main(){
	srand(10086);
	scanf("%d",&n);
	rep(i,1,n)scanf("%lf%lf",&p[i].x,&p[i].y);
	random_shuffle(p+1,p+1+n);
	o=p[1];
	rep(i,1,n){
		if(dblcmp(dis(o,p[i])-r)<=0)continue;
		o=(p[1]+p[i])/2;r=dis(o,p[1]);
		rep(j,1,i-1){
			if(dblcmp(dis(o,p[j])-r)<=0)continue;
			o=(p[i]+p[j])/2;r=dis(o,p[i]);
 			rep(k,1,j-1){
				if(dblcmp(dis(o,p[k])-r)<=0)continue;
				o=getO(p[i],p[j],p[k]);
				r=dis(o,p[i]);
			}
		}
	}
	printf("%lf\n%lf %lf",r,o.x,o.y);
	return 0;
}
