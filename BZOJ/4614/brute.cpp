#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=2000+10;
int n;
struct Point{
	LL x,y;
	Point(){x=y=0;}
	Point(LL _x,LL _y){x=_x;y=_y;}
};
struct Line{
	Point a,b;
	Line(){}
	Line(Point _a,Point _b){a=_a;b=_b;}
}L[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int x0,x1,y;scanf("%d%d%d",&x0,&x1,&y);
		if(x0>x1)swap(x0,x1);
		L[i]=Line(Point(x0,y),Point(x1,y));
	}
	if(n==1){printf("%lld",L[1].b.x-L[1].a.x);return 0;}
	LL ans=0;
	rep(i,1,n){
		rep(j,1,n)if(L[i].a.y!=L[j].b.y){
			Line tmp=Line(L[i].a,L[j].b);
			LL sum=0;
			rep(k,1,n){
				double x=tmp.a.x+1.0*(L[k].a.y-tmp.a.y)/(tmp.a.y-tmp.b.y)*(tmp.a.x-tmp.b.x);
				if(L[k].a.x<=x&&x<=L[k].b.x)sum+=L[k].b.x-L[k].a.x;
			}
			if(sum>ans)ans=sum;
		}
	}
	printf("%lld",ans);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
