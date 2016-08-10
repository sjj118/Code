#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 20010
#define eps 1e-8
#define LB long double

using namespace std;

int n;
struct Point{
	LB x,y;
	Point(LB _x=0,LB _y=0){x=_x;y=_y;}
}a,b,p[maxn];
int dblcmp(LB x){
	if(abs(x)<eps)return 0;
	return x>0?1:-1;
}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
LB operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
struct Line{
	Point a,b;
	Line(Point _a=Point(),Point _b=Point()){a=_a;b=_b;}
}l[maxn];
Point inter(Line a,Line b){
	LB t=((b.b-a.a)^(b.a-a.a))/(((b.b-a.a)^(b.a-a.a))+((b.a-a.b)^(b.b-a.b)));
	return Point(a.a.x+(a.b.x-a.a.x)*t,a.a.y+(a.b.y-a.a.y)*t);
}
int quad(Point a){
	if(a.x>0&&a.y>=0)return 1;
	if(a.y>0&&a.x<=0)return 2;
	if(a.x<0&&a.y<=0)return 3;
	if(a.y<0&&a.x>=0)return 4;
}
bool operator<(Line a,Line b){
	int qa=quad(a.b-a.a),qb=quad(b.b-b.a);
	if(qa==qb)return dblcmp((a.b-a.a)^(b.b-b.a))==1;
	return qa<qb;
}
Line q[maxn];
int ql,qr;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%Lf%Lf%Lf%Lf",&a.x,&a.y,&b.x,&b.y);
		l[i]=Line(a,b);
	}
	l[++n]=Line(Point(0,0),Point(10000,0));
	l[++n]=Line(Point(10000,0),Point(10000,10000));
	l[++n]=Line(Point(10000,10000),Point(0,10000));
	l[++n]=Line(Point(0,10000),Point(0,0));
	sort(l+1,l+1+n);
	int tot=1;
	for(int i=2;i<=n;++i){
		if(dblcmp((l[i].b-l[i].a)^(l[tot].b-l[tot].a)))l[++tot]=l[i];
		else if(dblcmp((l[i].b-l[i].a)^(l[tot].a-l[i].a))==-1)l[tot]=l[i];
	}
	ql=1;qr=0;
	for(int i=1;i<=tot;++i){
		while(ql<qr&&dblcmp((inter(q[qr],q[qr-1])-l[i].a)^(l[i].b-l[i].a))==1)--qr;
		while(ql<qr&&dblcmp((inter(q[ql],q[ql+1])-l[i].a)^(l[i].b-l[i].a))==1)++ql;
		q[++qr]=l[i];
	}
	while(ql<qr&&dblcmp((inter(q[qr],q[qr-1])-q[ql].a)^(q[ql].b-q[ql].a))==1)--qr;
	while(ql<qr&&dblcmp((inter(q[ql],q[ql+1])-q[qr].a)^(q[qr].b-q[qr].a))==1)++ql;
	for(int i=ql;i<qr;++i)p[i-ql+1]=inter(q[i],q[i+1]);p[qr-ql+1]=inter(q[qr],q[ql]);
	LB ans=0;
	if(qr-ql<2)return puts("0.0");
	for(int i=1;i<=qr-ql;++i)ans+=(p[i]^p[i+1])/2;ans+=(p[qr-ql+1]^p[1])/2;
	ans=fabs(ans);
	printf("%.1Lf",ans);
	return 0;
}
