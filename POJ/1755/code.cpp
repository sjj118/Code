#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 110
#define eps 1e-8

using namespace std;

int n;
struct Player{
	int u,v,w;
}a[maxn];
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}p[maxn];
Point operator+(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
double operator*(Point a,Point b){return a.x*b.x+a.y*b.y;}
int dblcmp(double x){
	if(abs(x)<eps)return 0;
	return x>0?1:-1;
}
struct Line{
	Point a,b;
	Line(Point _a=Point(),Point _b=Point()){a=_a;b=_b;}
}l[maxn];
int quad(Point a){
	if(a.x>0&&a.y>=0)return 1;
	if(a.y>0&&a.x<=0)return 2;
	if(a.x<0&&a.y<=0)return 3;
	if(a.y<0&&a.x>=0)return 4;
}
bool operator<(Line a,Line b){
	int qa=quad(a.b-a.a),qb=quad(b.b-b.a);
	if(qa==qb)return dblcmp((b.b-b.a)^(a.b-a.a))==-1;
	return qa<qb;
}
Point inter(Line a,Line b){
	int t=((b.b-a.a)^(b.a-a.a))/(((b.b-a.a)^(b.a-a.a))+((b.a-a.b)^(b.b-a.b)));
	return Point(a.a.x+(a.b.x-a.a.x)*t,a.a.y+(a.b.y-a.a.y)*t);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&a[i].v,&a[i].u,&a[i].w);
	for(int i=1;i<=n;++i){
		
	}
	return 0;
}
