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
	ConvexHull(){tot=0;}
	void build(Point*a,int n){
		tot=top=0;
		sort(a+1,a+1+n);
		rep(i,1,n){
			while(top>1&&(a[i]-p[top-1])%(p[top]-p[top-1])>=0)--top;
			p[++top]=a[i];
		}tot=top>1?top-1:1;
		per(i,n,1){
			while(tot>top&&(a[i]-p[tot-1])%(p[tot]-p[tot-1])>=0)--tot;
			p[++tot]=a[i];
		}
		--tot;
	}
	LL get2Area(){
		LL ret=0;
		rep(i,1,tot)ret+=p[i]%p[i+1];
		return ret;
	}
}ca,cb;
ConvexHull merge(const ConvexHull&a,const ConvexHull&b){
	if(a.tot==1)return b;
	ConvexHull ret;
	for(int i=1,j=1;i<=a.tot+1;++i){
		bool flag=1;
		while(j<=b.tot&&((b.p[j+1]-b.p[j])%(a.p[i+1]-a.p[i])>=0&&(j==1||(b.p[j+1]-b.p[j])%(b.p[j]-b.p[j-1])||flag))){
			ret.p[++ret.tot]=a.p[i]+b.p[j++];
			flag=0;
		}
		ret.p[++ret.tot]=a.p[i]+b.p[j];
	}
	--ret.tot;
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lld%lld",&a[i].x,&a[i].y);
	rep(i,1,m)scanf("%lld%lld",&b[i].x,&b[i].y);
	ca.build(a,n);ca.p[ca.tot+2]=ca.p[2];
	cb.build(b,m);
	printf("%lld",merge(ca,cb).get2Area());
	return 0;
}
