#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 10010
#define inf 1e9
#define eps 1e-8
#define sqr(x) ((x)*(x))

using namespace std;

int n;
struct Point{
	double x,y;
	int w;
	Point(double X=0,double Y=0){x=X;y=Y;}
} p[maxn],ans;
double dis(Point a,Point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
void climbhill(){
	double t=100,x,y;
	while(t>eps){
		x=y=0;
		for(int i=1;i<=n;++i){
			double d;
			if(!(d=dis(ans,p[i])))continue;
			x+=(p[i].x-ans.x)*p[i].w/d;
			y+=(p[i].y-ans.y)*p[i].w/d;
		}
		ans.x+=x*t;
		ans.y+=y*t;
		t*=0.99;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf%lf%d",&p[i].x,&p[i].y,&p[i].w);
	climbhill();
	printf("%.3lf %.3lf",ans.x,ans.y);
	return 0;
}
