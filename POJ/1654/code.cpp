#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 1000010
#define LL long long
#define abs(x) (x)<0?(-(x)):(x)

using namespace std;

const int dir[10][2]={{0,0},{-1,1},{0,1},{1,1},{-1,0},{0,0},{1,0},{-1,-1},{0,-1},{1,-1}};
struct Point{
	LL x,y;
	Point(LL _x=0,LL _y=0){x=_x;y=_y;}
}a,b;
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
LL operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		a=Point(0,0);
		char c=getchar();
		while(c<'0'||c>'9')c=getchar();
		LL ans=0;
		while(c>='0'&&c<='9'){
			int d=c-'0';
			b=Point(a.x+dir[d][0],a.y+dir[d][1]);
			ans+=(a^b);
			a=b;
			c=getchar();
		}
		ans=abs(ans);
		if(ans&1)printf("%lld.5\n",ans>>1);
		else printf("%lld\n",ans>>1);
	}
	return 0;
}
