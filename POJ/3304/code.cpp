#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 110
#define eps 1e-8
#define abs(x) ((x)<0?(-(x)):(x))
#define sqr(x) ((x)*(x))

using namespace std;

int n;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}a[maxn],b[maxn];
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
Point operator+(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
double operator*(Point a,Point b){return a.x*b.x+a.y*b.y;}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
int dblcmp(double x){
	if(abs(x)<eps)return 0;
	return x>0?1:-1;
}
bool hasInsect(Point a1,Point a2,Point b1,Point b2){
	return dblcmp((b1-a1)^(a2-a1))*dblcmp((a2-a1)^(b2-a1))>=0;
}
bool check(Point a1,Point a2){
	for(int i=1;i<=n;++i)if(!hasInsect(a1,a2,a[i],b[i]))return 0;
	return 1;
}
double dis(Point a,Point b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
		bool ans=0;
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
			if(dis(a[i],a[j])>=eps)ans|=check(a[i],a[j]);
			if(dis(a[i],b[j])>=eps)ans|=check(a[i],b[j]);
			if(dis(b[i],a[j])>=eps)ans|=check(b[i],a[j]);
			if(dis(b[i],b[j])>=eps)ans|=check(b[i],b[j]);
			if(ans)break;
		}
		if(ans)printf("Yes!\n");else printf("No!\n");
	}
	return 0;
}
