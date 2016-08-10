#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100010
#include<cmath>
#define eps 1e-8

using namespace std;

int n;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}p[maxn],q[maxn];
int top,qr;
bool operator<(Point a,Point b){return a.y<b.y||a.y==b.y&&a.x<b.x;}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
int fab(double x){
	if(abs(x)<eps)return 0;
	return x>0?1:-1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
	sort(p+1,p+1+n);
	for(int i=1;i<=n;++i){
		while(top>1&&fab((q[top]-q[top-1])^(p[i]-q[top-1]))==-1)--top;
		q[++top]=p[i];
	}qr=top;
	for(int i=n-1;i;--i){
		while(qr>top&&fab((q[qr]-q[qr-1])^(p[i]-q[qr-1]))==-1)--qr;
		q[++qr]=p[i];
	}
	double ans=0;
	for(int i=1;i<qr;++i)ans+=(q[i]^q[i+1])/2;
	printf("%d",int(ans/50));
	return 0;
}
