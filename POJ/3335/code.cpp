#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#define eps 1e-8
#define maxn 110

using namespace std;

int n;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}p[maxn];
Point operator+(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
int dblcmp(double x){
	if(abs(x)<eps)return 0;
	return x>0?1:-1;
}
struct Line{
	Point s,v;
	Line(Point _s=Point(),Point _v=Point()){s=_s;v=_v;}
}l[maxn];
int quad(Point a){
	if(a.x>0&&a.y>=0)return 1;
	if(a.y>0&&a.x<=0)return 2;
	if(a.x<0&&a.y<=0)return 3;
	if(a.y<0&&a.x>=0)return 4;
	return -1;
}
bool operator<(Line a,Line b){
	int qa=quad(a.v),qb=quad(b.v);
	if(qa<qb)return 1;
	if(qa>qb)return 0;
	return dblcmp(a.v^b.v)==1;
}
Point getInter(Line a,Line b){
	double t=((b.s-a.s)^(b.s+b.v-a.s))/(((b.s-a.s)^(b.s+b.v-a.s))+((b.s+b.v-a.s-a.v)^(b.s-a.s-a.v)));
	return Point(a.s.x+a.v.x*t,a.s.y+a.v.y*t);
}
Line q[maxn];
int ql,qr;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
		for(int i=1;i<n;++i)l[i]=Line(p[i+1],p[i]-p[i+1]);l[n]=Line(p[1],p[n]-p[1]);
		sort(l+1,l+1+n);
		int i,j;
		for(i=2,j=1;i<=n;++i){
			if(!dblcmp(l[i].v^l[j].v)){
				if(dblcmp(l[i].v^(l[j].s-l[i].s))==-1)l[j]=l[i];
			}else l[++j]=l[i];
		}
		n=j;
		ql=1;qr=0;
		for(int i=1;i<=n;++i){
			while(ql<qr&&dblcmp((getInter(q[qr],q[qr-1])-l[i].s)^l[i].v)==1)--qr;
			while(ql<qr&&dblcmp((getInter(q[ql],q[ql+1])-l[i].s)^l[i].v)==1)++ql;
			q[++qr]=l[i];
		}
		while(ql<qr&&dblcmp((getInter(q[qr],q[qr-1])-q[ql].s)^q[ql].v)==1)--qr;
		while(ql<qr&&dblcmp((getInter(q[ql],q[ql+1])-q[qr].s)^q[qr].v)==1)++ql;
		if(qr-ql<2)printf("NO\n");else printf("YES\n");
	}
	return 0;
}
