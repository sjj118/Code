#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 10010
#define eps 1e-8
#define inf 1e9
#define sqr(x) ((x)*(x))

using namespace std;

int n,m,ar,br,at,bt;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}a[maxn],b[maxn],p[maxn];
Point operator+(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double operator*(Point a,Point b){return a.x*b.x+a.y*b.y;}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
bool operator<(Point a,Point b){return a.y<b.y||a.y==b.y&&a.x<b.x;}
double dis(Point a,Point b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
int dblcmp(double x){
	if(abs(x)<eps)return 0;
	return x>0?1:-1;
}
void graham(Point*p,Point*q,int&top,int&qr,int n){
	sort(p+1,p+1+n);top=0;
	for(int i=1;i<=n;++i){
		while(top>1&&dblcmp((p[i]-q[top-1])^(q[top]-q[top-1]))==1)--top;
		q[++top]=p[i];
	}qr=top;
	for(int i=n-1;i;--i){
		while(qr>top&&dblcmp((p[i]-q[qr-1])^(q[qr]-q[qr-1]))==1)--qr;
		q[++qr]=p[i];
	}
}
struct Line{
	Point a,b;
	Line(Point _a=Point(),Point _b=Point()){a=_a;b=_b;}
};
double dis(Point a,Line l){
	if(dblcmp((a-l.a)*(l.b-l.a))==-1)return dis(a,l.a);
	if(dblcmp((a-l.b)*(l.a-l.b))==-1)return dis(a,l.b);
	return fabs((a-l.a)^(l.b-l.a))/dis(l.a,l.b);
}
double dis(Line a,Line b){
	return min(min(dis(a.a,b),dis(a.b,b)),min(dis(b.a,a),dis(b.b,a)));
}

int main(){
	while(scanf("%d%d",&n,&m)>0&&n&&m){
		for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
		graham(p,b,at,ar,n);
		for(int i=at;i<ar;++i)a[i-at+1]=b[i];
		for(int i=1;i<=at;++i)a[i+ar-at]=b[i];a[++ar]=a[2];
		for(int i=1;i<=m;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
		graham(p,b,bt,br,m);b[++br]=b[2];
		double ans=inf;
		for(int i=1,j=1;i<ar;++i){
			while(j<br-1&&dblcmp((a[i+1]-a[i])^(b[j+1]-b[j]))==1)ans=min(ans,dis(a[i],b[j])),ans=min(ans,dis(a[i],Line(b[j],b[j+1]))),ans=min(ans,dis(b[j],Line(a[i],a[i+1]))),++j;
			if(dblcmp((a[i+1]-a[i])^(b[j+1]-b[j])))ans=min(ans,dis(a[i],b[j])),ans=min(ans,dis(a[i],Line(b[j],b[j+1]))),ans=min(ans,dis(b[j],Line(a[i],a[i+1])));
			else ans=min(ans,dis(Line(a[i],a[i+1]),Line(b[j],b[j+1])));
		}
		printf("%.5lf\n",ans);
	}
	return 0;
}
