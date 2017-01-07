
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 50500
#define EPS 1e-7
#define PI 3.1415926535897932
using namespace std;
struct Point{
	double x,y;
	Point() {}
	Point(double _,double __):
		x(_),y(__) {}
	friend istream& operator >> (istream &_,Point &p)
	{
		scanf("%lf%lf",&p.x,&p.y);
		return _;
	}
	friend Point operator + (const Point &p1,const Point &p2)
	{
		return Point(p1.x+p2.x,p1.y+p2.y);
	}
	friend Point operator - (const Point &p1,const Point &p2)
	{
		return Point(p1.x-p2.x,p1.y-p2.y);
	}
	friend Point operator * (const Point &p,double rate)
	{
		return Point(p.x*rate,p.y*rate);
	}
	friend double operator * (const Point &p1,const Point &p2)
	{
		return p1.x*p2.y - p1.y*p2.x;
	}
	friend Point Rotate(const Point &p,double alpha)
	{
		return Point( p.x * cos(alpha) - p.y * sin(alpha) , p.x * sin(alpha) + p.y * cos(alpha) );
	}
	friend double Distance(const Point &p1,const Point &p2)
	{
		return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
	}

}points[M];
struct Line{
	Point p,v;
	Line() {}
	Line(const Point &_,const Point &__):
		p(_),v(__) {}
};
struct Circle{
	Point o;
	double r;
	Circle() {}
	Circle(const Point &_,double __):
		o(_),r(__) {}
	bool In_Circle(const Point &p)
	{
		return Distance(o,p)<r+EPS;
	}
}ans;
int n,a,p;
Point Get_Intersection(const Line &l1,const Line &l2)
{
	Point u=l1.p-l2.p;
	double temp=(l2.v*u)/(l1.v*l2.v);
	return l1.p+l1.v*temp;
}
int main()
{
	srand(19980402);
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>points[i];
	cin>>a>>p;
	double alpha=-a/180.0*PI;
	for(i=1;i<=n;i++)
	{
		points[i]=Rotate(points[i],alpha);
		points[i].x/=p;
	}
	random_shuffle(points+1,points+n+1);
	for(i=1;i<=n;i++)
		if(!ans.In_Circle(points[i]))
		{
			ans=Circle(points[i],0);
			for(j=1;j<i;j++)
				if(!ans.In_Circle(points[j]))
				{
					ans=Circle((points[i]+points[j])*0.5,Distance(points[i],points[j])/2);
					for(k=1;k<j;k++)
						if(!ans.In_Circle(points[k]))
						{
							Line l1((points[i]+points[j])*0.5,Rotate(points[i]-points[j],PI/2));
							Line l2((points[i]+points[k])*0.5,Rotate(points[i]-points[k],PI/2));
							Point p=Get_Intersection(l1,l2);
							ans=Circle(p,Distance(p,points[i]));
						}
				}
		}
	printf("%.3lf\n",ans.r);
	return 0;
}
