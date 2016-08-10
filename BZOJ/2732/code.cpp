#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 200010
#define inf 1e9
#define eps 1e-12
#define LB long double

using namespace std;

int n,ql,qr;
struct Point{
	LB x,y;
	Point(LB _x=0,LB _y=0){x=_x;y=_y;}
};
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
LB operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
int dblcmp(LB x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
struct Line{
	Point a,b;
	int pos;
	Line(Point _a=Point(),Point _b=Point()){a=_a;b=_b;pos=0;}
}l[maxn],q[maxn],A[maxn];
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
bool merge(int m){
	int tot=1,s=1;
	while(A[s].pos>m)++s;
	l[tot]=A[s];
	for(int i=s+1;i<=n;++i){
		if(A[i].pos>m)continue;
		if(dblcmp((l[tot].b-l[tot].a)^(A[i].b-A[i].a)))l[++tot]=A[i];
		else if(dblcmp((A[i].b-l[tot].a)^(l[tot].b-l[tot].a))==-1)l[tot]=A[i];
	}
	ql=1;qr=0;
	for(int i=1;i<=tot;++i){
		while(ql<qr&&dblcmp((inter(q[qr],q[qr-1])-l[i].a)^(l[i].b-l[i].a))==1)--qr;
		while(ql<qr&&dblcmp((inter(q[ql],q[ql+1])-l[i].a)^(l[i].b-l[i].a))==1)++ql;
		q[++qr]=l[i];
	}
	while(ql<qr&&dblcmp((inter(q[qr],q[qr-1])-q[ql].a)^(q[ql].b-q[ql].a))==1)--qr;
	while(ql<qr&&dblcmp((inter(q[ql],q[ql+1])-q[qr].a)^(q[qr].b-q[qr].a))==1)++ql;
	return qr-ql>1;
}

int main(){
	scanf("%d",&n);int tn=n;
	for(int i=1;i<=n;++i){
		LB x,d,u;scanf("%Lf%Lf%Lf",&x,&d,&u);
		A[i*2-1]=Line(Point(0,d/x),Point(1,d/x-x));A[i*2-1].pos=i;
		A[i*2]=Line(Point(1,u/x-x),Point(0,u/x));A[i*2].pos=i;
	}
	n<<=1;
	A[++n]=Line(Point(-eps,0),Point(-eps,1));
	A[++n]=Line(Point(0,inf),Point(-1,inf));
	A[++n]=Line(Point(-inf,1),Point(-inf,0));
	A[++n]=Line(Point(-1,eps),Point(0,eps));
	sort(A+1,A+1+n);
	int l=0,r=tn;
	while(l<r){
		int m=(l+r+1)>>1;
		if(merge(m))l=m;else r=m-1;
	}
	printf("%d",l);
	return 0;
}
