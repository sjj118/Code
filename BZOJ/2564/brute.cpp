#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=2e5+10;
int n,m;
struct Point{
	LL x,y;
	Point(){}
	Point(LL x,LL y):x(x),y(y){}
}a[N],b[N];
bool operator<(const Point&a,const Point&b){return a.y<b.y||(a.y==b.y&&a.x<b.x);}
Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
LL operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
LL operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
struct ConvexHull{
	int tot,top;
	Point p[N];
	void build(Point*a,int n){
		tot=top=0;
		sort(a+1,a+1+n);
		rep(i,1,n){
			while(top>1&&(a[i]-p[top-1])%(p[top]-p[top-1])>=0)--top;
			p[++top]=a[i];
		}tot=top;
		per(i,n-1,1){
			while(tot>top&&(a[i]-p[tot-1])%(p[tot]-p[tot-1])>=0)--tot;
			p[++tot]=a[i];
		}
		if(tot>1)--tot;
	}
	LL get2Area(){
		LL ret=0;
		rep(i,1,tot)ret+=p[i]%p[i+1];
		return ret;
	}
}ca,cb;
ConvexHull merge(const ConvexHull&a,const ConvexHull&b){
	static Point p[N];
	int n=0;
	rep(i,1,a.tot)rep(j,1,b.tot)p[++n]=a.p[i]+b.p[j];
	ConvexHull ret;
	ret.build(p,n);
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lld%lld",&a[i].x,&a[i].y);
	rep(i,1,m)scanf("%lld%lld",&b[i].x,&b[i].y);
	ca.build(a,n);
	cb.build(b,m);
	printf("%lld",merge(ca,cb).get2Area());
	return 0;
}
