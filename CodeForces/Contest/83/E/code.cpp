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
const int N=500+10;
const real eps=1e-10;
inline int dblcmp(real x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
inline real readreal(){double ret;scanf("%lf",&ret);return ret;}
int n,m;
struct Point{
	real x,y;
	Point(){}
	Point(real x,real y):x(x),y(y){}
	void input(){x=readreal();y=readreal();}
};
Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
Point operator*(const Point&a,real t){return Point(a.x*t,a.y*t);}
Point operator*(real t,const Point&a){return Point(a.x*t,a.y*t);}
real operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
real operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
struct Line{
	Point p,v;
	Line(){}
	Line(Point p,Point v):p(p),v(v){}
}C[N*4];
Point getIntersection(const Line&a,const Line&b){
	real t=b.v%(a.p-b.p)/(a.v%b.v);
	return a.p+a.v*t;
}
pair<Point,int> L[N*4];
bool del[N*4];
bool operator==(const Line&a,const Line&b){return dblcmp(a.v%b.v)==0&&dblcmp((b.p-a.p)%a.v)==0;}
struct cmp{
	Point p;
	cmp(const Point&p):p(p){}
	bool operator()(const pair<Point,int>&a,const pair<Point,int>&b){return dblcmp((b.fi-a.fi)*p)==1;}
};
real ans,area;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		Point a,b,c,d;
		a.input();b.input();c.input();d.input();
		if(dblcmp((b-a)%(c-a))<0)swap(a,d),swap(b,c);
		C[++m]=Line(a,b-a);
		C[++m]=Line(b,c-b);
		C[++m]=Line(c,d-c);
		C[++m]=Line(d,a-d);
		ans+=a%b/2+b%c/2+c%d/2+d%a/2;
	}
	rep(i,1,m)if(!del[i]){
		n=0;
		rep(j,1,m){
			int t=dblcmp(C[j].v%C[i].v);
			if(t){
				Point p=getIntersection(C[i],C[j]);
				if(dblcmp((p-C[j].p)*(C[j].p+C[j].v-p))>=0)L[++n]=mp(p,t);
			}else if(dblcmp((C[i].p-C[j].p)%C[i].v)==0){
				del[j]=1;
				L[++n]=mp(C[j].p,2);
				L[++n]=mp(C[j].p+C[j].v,-2);
			}
		}
		sort(L+1,L+1+n,cmp(C[i].v));
		int cnt=0,ct=0;
		rep(j,1,n-1){
			if(abs(L[j].se)>1)ct+=L[j].se/2;
			else cnt+=L[j].se;
			if(cnt>0&&cnt==ct)
				area+=L[j].fi%L[j+1].fi/2;
		}
	}
	ans/=area;
	printf("%.10lf",(double)ans);
	return 0;
}
