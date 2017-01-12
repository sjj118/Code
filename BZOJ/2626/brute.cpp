#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n,m;
struct Point{
	int x,y,id;
	Point(){}
	Point(int x,int y):x(x),y(y){}
	LL length2(){return (LL)x*x+(LL)y*y;}
}p[N],c;
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
bool operator<(const Point&a,const Point&b){
	LL l1=(a-c).length2(),l2=(b-c).length2();
	return l1>l2||(l1==l2&&a.id<b.id);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
	scanf("%d",&m);
	while(m--){
		int k;scanf("%d%d%d",&c.x,&c.y,&k);
		sort(p+1,p+1+n);
		printf("%d\n",p[k].id);
	}
	return 0;
}
