#include<iostream>
#include<cstdio>
#include<cmath>
#define sqr(x) ((x)*(x))
#define maxn 33
#define eps 1e-9

using namespace std;

int n;
struct Point{
	double x,y,z;
	Point(double X=0,double Y=0,double Z=0){x=X;y=Y;z=Z;}
}p[maxn];
double dis(Point a,Point b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z));}
double search(){
	double t=50;
	Point O;
	int lp=1;
	double l;
	while(t>eps){
		for(int i=1;i<=n;++i)if(dis(O,p[i])>dis(O,p[lp]))lp=i;
		l=dis(O,p[lp]);
		if(l==0)return 0;
		O.x+=t*(p[lp].x-O.x)/l;
		O.y+=t*(p[lp].y-O.y)/l;
		O.z+=t*(p[lp].z-O.z)/l;
		t*=0.99;
	}
	return l;
}

int main(){
	while(scanf("%d",&n)>0&&n){
		for(int i=1;i<=n;++i)scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
		printf("%.5lf\n",search());
	}
	return 0;
}
