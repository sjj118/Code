#include<iostream>
#include<cstdio>
#define maxn 100010
#define LL long long

using namespace std;

int n;
struct Point{
	LL x,y;
	Point(int X=0,int Y=0){x=X;y=Y;}
	void read(){scanf("%lld%lld",&x,&y);}
}p[maxn];
LL s[maxn<<2];
Point Vector(Point a,Point b){return Point(b.x-a.x,b.y-a.y);}
LL cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)p[i].read();
		
	}
	return 0;
}
