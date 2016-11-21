#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=200+10,M=10000+10,inf=1e9;
int n,m;
struct Edge{
	LL u,v,a,b;
}e[M];
struct Graph{
	int tot,
}G;
struct Point{
	LL x,y;
	Point(){x=y=0;}
	Point(LL _x,LL _y){x=_x;y=_y;}
};
Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
LL operator^(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
LL operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
Point dis[N];
bool vis[N];
Point MST(LL x,LL y){
	Point ret;
	rep(i,1,n)dis[i]=Point(inf,inf);cls(vis);
	dis[1]=Point(0,0);
	while(1){
		int k=-1;
		rep(j,1,n)if(!vis[j]&&(k==-1||dis[j].x*x+dis[j].y*y<dis[k].x*x+dis[k].y*y))k=j;
		if(k==-1)break;
		vis[k]=1;
		ret+=dis[k];
		for(int p=head[k];p;p=next[p])if()
	}
	return ret;
}
Point solve(Point a,Point b){
	Point ret=MST(a.y-b.y,b.x-a.x);
	if(((b-ret)^(a-ret))<=0)return ret;
	Point left=solve(a,ret),right=solve(ret,b);
	if(left.x*left.y<=ret.x*ret.y)ret=left;
	if(right.x*right.y<ret.x*ret.y)ret=right;
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%lld%lld%lld%lld",&e[i].u,&e[i].v,&e[i].a,&e[i].b),++e[i].u,++e[i].v;
	Point left=MST(1,0),right=MST(0,1);
	Point ans=solve(left,right);
	if(left.x*left.y<=ans.x*ans.y)ans=left;
	if(right.x*right.y<ans.x*ans.y)ans=right;
	printf("%lld %lld",ans.x,ans.y);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
