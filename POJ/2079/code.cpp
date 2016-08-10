#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 50010
#define eps 1e-10

using namespace std;

int n,top,qr;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}p[maxn],q[maxn];
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
Point operator+(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
double operator*(Point a,Point b){return a.x*b.x+a.y*b.y;}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
bool operator<(Point a,Point b){return a.y<b.y||a.y==b.y&&a.x<b.x;}
int dblcmp(double x){if(abs(x)<eps)return 0;return x>0?1:-1;}

int main(){
	while(scanf("%d",&n)>0&&n>0){
		for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p+1,p+1+n);top=0;
		for(int i=1;i<=n;++i){
			while(top>1&&dblcmp((p[i]-q[top-1])^(q[top]-q[top-1]))==1)--top;
			q[++top]=p[i];
		}qr=top;
		for(int i=n-1;i;--i){
			while(qr>top&&dblcmp((p[i]-q[qr-1])^(q[qr]-q[qr-1]))==1)--qr;
			q[++qr]=p[i];
		}
		double ans=0;
		for(int i=1;i!=qr;++i){
			for(int j=i%(qr-1)+1,k=j%(qr-1)+1;j!=i&&k!=i;j=j%(qr-1)+1){
				ans=max(ans,fabs((q[j]-q[i])^(q[k]-q[i]))/2);
				int nek=k%(qr-1)+1;
				while(nek!=i&&dblcmp((q[nek]-q[k])^(q[j]-q[i]))==-1)ans=max(ans,fabs((q[j]-q[i])^(q[k=nek]-q[i]))/2),nek=k%(qr-1)+1;
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
