#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#include<algorithm>
#define maxn 1010
#define eps 1e-8
#define inf 1e9

using namespace std;

int n;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}p[maxn],q[maxn];
int qr,top;
bool operator<(Point a,Point b){return a.y<b.y||a.y==b.y&&a.x<b.x;}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
double operator*(Point a,Point b){return a.x*b.x+a.y*b.y;}
int fab(double x){
	if(abs(x)<eps)return 0;
	return x>0?1:-1;
}
bool cmp(Point a,Point b,Point c){
	int t=fab((b-a)^(c-a));
	if(t==-1||t==0&&fab((a-b)*(c-b))==-1)return 1;
	return 0;
}
bool mark[maxn];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);cls(mark);
		for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p+1,p+1+n);top=0;
		for(int i=1;i<=n;++i){
			while(top>1&&cmp(q[top-1],q[top],p[i]))--top;
			q[++top]=p[i];
		}
		qr=top-1;
		for(int i=n;i;--i){
			while(qr>top&&cmp(q[qr-1],q[qr],p[i]))--qr;
			q[++qr]=p[i];
		}
		for(int i=1,j=1;i<top;++i){
			while(j<=n&&!(fab((p[j]-q[i])^(q[i+1]-q[i]))==0&&fab((q[i]-p[j])*(q[i+1]-p[j]))==-1))++j;
			if(j<=n)mark[i]=1;
		}
		for(int i=top,j=n;i<qr;++i){
			while(j&&!(fab((p[j]-q[i])^(q[i+1]-q[i]))==0&&fab((q[i]-p[j])*(q[i+1]-p[j]))==-1))--j;
			if(j)mark[i]=1;
		}
		bool flag=1;
		for(int i=1;i<qr;++i)if(!mark[i])flag=0;
		if(qr<=3)flag=0;
		if(flag)printf("YES\n");else printf("NO\n");
	}
	return 0;
}
