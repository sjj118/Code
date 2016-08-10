#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-8

using namespace std;

int fab(double x){if(abs(x)<eps)return 0;return x>0?1:-1;}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x,y=_y;}
}a,b,c,d;
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}

int main(){
	printf("INTERSECTING LINES OUTPUT\n");
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
		if(fab((b-a)^(c-a))==0&&fab((b-a)^(d-a))==0)printf("LINE\n");
		else if(fab((a-b)^(c-d))==0)printf("NONE\n");
		else{
			double s1,s2;
			s1=(d-a)^(c-a);s2=(c-b)^(d-b);
			double x=a.x+(b.x-a.x)*s1/(s1+s2);
			s1=(b-d)^(a-d);s2=(a-c)^(b-c);
			double y=d.y+(c.y-d.y)*s1/(s1+s2);
			printf("POINT %.2lf %.2lf\n",x,y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
