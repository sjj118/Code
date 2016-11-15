#include<iostream>
#include<cstdio>
#include<algorithm>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
typedef long long LL;
const int N=2000+10;
inline void up(LL&x,LL y){if(y>x)x=y;}
int n;
struct Point{
	LL x,y;
	Point(){x=y=0;}
	Point(LL _x,LL _y){x=_x;y=_y;}
}p[N<<1];
Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
LL operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
LL operator^(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
typedef pair<Point,int> ppi;
ppi q[N<<1];
bool cmp(const ppi&a,const ppi&b){
	LL t=a.fi^b.fi;
	return t<0||t==0&&a.se>b.se;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int x0,x1,y;scanf("%d%d%d",&x0,&x1,&y);
		if(x0>x1)swap(x0,x1);
		p[i*2-1]=Point(x0,y);p[i*2]=Point(x1,y);
	}
	LL ans=0;
	rep(i,1,n<<1)if(i&1){
		int tot=0;
		rep(j,1,n<<1){
			Point tmp=p[j]-p[i];
			if(tmp.y==0)continue;
			if(tmp.y<0)q[++tot]=mp(Point()-tmp,abs(p[j].x-p[((j+1)^1)-1].x)*((j&1)?-1:1));
			else q[++tot]=mp(tmp,abs(p[j].x-p[((j+1)^1)-1].x)*((j&1)?1:-1));
		}
		sort(q+1,q+1+tot,cmp);
		LL sum=p[i+1].x-p[i].x;
		up(ans,sum);
		rep(i,1,tot){
			sum+=q[i].se;
			up(ans,sum);
		}
	}
	printf("%lld",ans);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
