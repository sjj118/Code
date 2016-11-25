#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<ctime> 
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double LB;
const int N=1e5+10;
const LB eps=1e-8;
inline int dblcmp(LB x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
inline double sqr(double x){return x*x;}
int n,m;
struct Point{
	LB x,y;
	Point(){x=y=0;}
	Point(LB _x,LB _y):x(_x),y(_y){}
	friend Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
	friend Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
	friend Point operator*(const Point&a,double b){return Point(a.x*b,a.y*b);}
	friend LB operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
	friend LB operator^(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
	friend LB dis(const Point&a,const Point&b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
	friend Point rot(const Point&a){return Point(-a.y,a.x);}
}p[N],q[N],b[N];
struct Line{
	Point p,v;
	Line(){}
	Line(const Point&_p,const Point&_v):p(_p),v(_v){}
	friend Point getInter(const Line&a,const Line&b){
		Point u=a.p-b.p;
		LB t=(b.v^u)/(a.v^b.v);
		return a.p+a.v*t;
	}
};
struct Circle{
	Point o;
	LB r;
	Circle(){}
	Circle(const Point&_o,LB _r):o(_o),r(_r){}
	bool inside(const Point&p){return dis(o,p)<r+eps;}
};
inline Circle getCircle(const Point&a,const Point&b,const Point&c){
	if(dblcmp((b-a)^(c-a))==0){
		if(dblcmp((b-a)*(c-a))<=0)return Circle((b+c)*0.5,dis(b,c)*0.5);
		if(dblcmp((a-b)*(c-b))<=0)return Circle((a+c)*0.5,dis(a,c)*0.5);
		return Circle((a+b)*0.5,dis(a,b)*0.5);
	}
	Point o=getInter(Line((a+b)*0.5,rot(a-b)),Line((a+c)*0.5,rot(a-c)));
	return Circle(o,dis(o,a));
}
Circle min_circle(int l,int r){
	rep(i,l,r)b[i]=p[i];
	random_shuffle(b+l,b+r+1);
	Circle o(Point(0,0),0);
	rep(i,l,r)if(!o.inside(b[i])){
		o=Circle(b[i],0);
		rep(j,l,i-1)if(!o.inside(b[j])){
			o=Circle((b[i]+b[j])*0.5,dis(b[i],b[j])*0.5);
			rep(k,l,j-1)if(!o.inside(b[k])){
				o=getCircle(b[i],b[j],b[k]);
			}
		}
	}
	return o;
}
int solve(LB maxr){
	int ret=0;
	for(int i=1;i<=n;){
		int l=i,r=i+1;
		for(int j=1;;j<<=1,l=r,r=min(n,i+j)){
			if(min_circle(i,r).r>maxr+eps)break;
			if(n==r){q[++ret]=min_circle(i,r).o;return ret;}
		}
		r=min(r,n);
		while(l<r){
			int mid=(l+r+1)>>1;
			if(min_circle(i,mid).r>maxr+eps)r=mid-1;else l=mid;
		}
		q[++ret]=min_circle(i,l).o;
		i=l+1;
		if(ret>m)return ret;
	}
	return ret;
}
int main(){
	srand(20000107);
	scanf("%d%d",&n,&m);
	rep(i,1,n){double x,y;scanf("%lf%lf",&x,&y);p[i]=Point(x,y);}
	LB l=0,r=min_circle(1,n).r;
	int cnt=0;
	while(r-l>eps){
		LB mid=(l+r)/2;
		cnt=solve(mid);
		if(cnt<=m)r=mid;else l=mid;
	}
	printf("%.8lf\n",double(r));
	cnt=solve(r);
	printf("%d\n",cnt);
	rep(i,1,cnt)printf("%.8lf %.8lf\n",double(q[i].x),double(q[i].y));
	return 0;
}
