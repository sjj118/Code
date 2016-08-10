#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long LL;
const int maxn=1550;
using namespace std;

LL inline sqr(LL x){return x*x;}
int n,tot;
struct Point{
	LL x,y;
	Point(LL _x=0,LL _y=0){x=_x;y=_y;}
}p[maxn];
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
Point operator+(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
bool operator==(Point a,Point b){return a.x==b.x&&a.y==b.y;}
bool operator<(Point a,Point b){return a.y<b.y||a.y==b.y&&a.x<b.x;}
LL operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
LL dis(Point a,Point b){return sqr(a.x-b.x)+sqr(a.y-b.y);}
struct Line{
	Point a,b;
	Line(Point _a=Point(),Point _b=Point()){a=_a;b=_b;}
}l[maxn*maxn];
int quad(Point a){
	if(a.x>0&&a.y>=0)return 1;
	if(a.y>0&&a.x<=0)return 2;
	if(a.x<0&&a.y<=0)return 3;
	if(a.y<0&&a.x>=0)return 4;
	return 0;
}
bool operator==(Line a,Line b){
	return a.a+a.b==b.a+b.b&&dis(a.a,a.b)==dis(b.a,b.b);
}
bool operator<(Line a,Line b){
	if(a.a+a.b==b.a+b.b){
		if(dis(a.a,a.b)==dis(b.a,b.b)){
			int qa=quad(a.b-a.a),qb=quad(b.b-b.a);
			return qa<qb||qa==qb&&((a.b-a.a)^(b.b-b.a))>0;
		}
		return dis(a.a,a.b)<dis(b.a,b.b);
	}
	return a.a+a.b<b.a+b.b;
}
LL area(Line a,Line b){
	return ((b.a-a.a)^(b.b-a.a));
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld%lld",&p[i].x,&p[i].y);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)l[++tot]=Line(p[i],p[j]);
	sort(l+1,l+1+tot);
	LL ans=0;
	for(int start=1,i=1,j=1;i<=tot;++i){
		if(l[start]<l[i])start=j=i;
		while(l[start]==l[j+1]&&area(l[i],l[j+1])>area(l[i],l[j]))++j;
		ans=max(ans,area(l[i],l[j]));
	}
	printf("%lld\n",ans);
	return 0;
}
