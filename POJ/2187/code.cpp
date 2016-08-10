#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 50010
#define sqr(x) ((x)*(x))

using namespace std;

int n,top,qr;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x;y=_y;}
}p[maxn],q[maxn];
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
Point operator+(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
int operator*(Point a,Point b){return a.x*b.x+a.y*b.y;}
int operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
bool operator<(Point a,Point b){return a.y<b.y||a.y==b.y&&a.x<b.x;}
int dis(Point a,Point b){return sqr(a.x-b.x)+sqr(a.y-b.y);}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+1+n);
	for(int i=1;i<=n;++i){
		while(top>1&&((p[i]-q[top-1])^(q[top]-q[top-1]))>0)--top;
		q[++top]=p[i];
	}
	qr=top;
	for(int i=n-1;i;--i){
		while(qr>top&&((p[i]-q[qr-1])^(q[qr]-q[qr-1]))>0)--qr;
		q[++qr]=p[i];
	}
	int ans=0;
	for(int i=1,j=top;i<top;++i){
		while(j<qr&&((q[j+1]-q[j])^(q[i+1]-q[i]))<=0)ans=max(ans,dis(q[i],q[j++]));
		ans=max(ans,dis(q[i],q[j]));
	}
	printf("%d",ans);
	return 0;
}
