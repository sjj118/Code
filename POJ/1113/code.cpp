#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 1010
#define pi acos(-1.0)
#define eps 1e-8

using namespace std;

int n,l;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}p[maxn],D[maxn],U[maxn];
int fab(double x){
	if(abs(x)<eps)return 0;
	return x>0?1:-1;
}
int tD,tU;
bool comp(Point a,Point b){
	return a.y<b.y||a.y==b.y&&a.x<b.x;
}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
double ans;
double dis(Point a,Point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
	sort(p+1,p+1+n,comp);
	for(int i=1;i<=n;++i){
		while(tD>1&&fab((D[tD]-D[tD-1])^(p[i]-D[tD-1]))<0)--tD;
		D[++tD]=p[i];
	}
	for(int i=n;i;--i){
		while(tU>1&&fab((U[tU]-U[tU-1])^(p[i]-U[tU-1]))<0)--tU;
		U[++tU]=p[i];
	}
	ans+=2*pi*l;
	for(int i=2;i<=tD;++i)ans+=dis(D[i-1],D[i]);
	for(int i=2;i<=tU;++i)ans+=dis(U[i-1],U[i]);
	printf("%d",int(ans+0.5));
	return 0;
}
