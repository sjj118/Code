#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long double LB;
typedef long long LL;
const int maxn=1e4+10;
using namespace std;
int n,w,v,u;
LB ans;
struct Point{
	LL x,y;
	Point(LL _x=0,LL _y=0){x=_x;y=_y;}
}p[maxn],q[maxn],l;
bool operator<(Point a,Point b){return a.x<b.x||a.x==b.x&&a.y<b.y;}
LL operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
Point operator+(Point a,Point b){return Point (a.x+b.x,a.y+b.y);}
int dblcmp(LL x){if(x==0)return 0;return x>0?1:-1;}
int main(){
	scanf("%d%d%d%d",&n,&w,&v,&u);
	l=Point(v,u);
	rep(i,1,n)scanf("%I64d%I64d",&p[i].x,&p[i].y);
	bool flag=1;
	rep(i,1,n)if(dblcmp(l^p[i])==1)flag=0;
	if(!flag){
		int tmp=1;
		rep(i,1,n)if(p[i]<p[tmp])tmp=i;
		rep(i,1,n)q[i]=p[(tmp+i-2)%n+1];
		tmp=1;
		while(tmp<n&&dblcmp((q[tmp+1]-q[tmp])^(l))==1)++tmp;
		if(dblcmp(q[tmp]^l)==1)ans=(LB)q[tmp].x/v+(LB)(w-q[tmp].y)/u;
		else ans=(LB)w/u;
	}else ans=(LB)w/u;
	printf("%.10lf\n",(double)ans);
	return 0;
}
