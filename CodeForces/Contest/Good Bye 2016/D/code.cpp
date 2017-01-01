#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define cls(a) memset(a,0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=30+5,M=300+20,dx[2][4]={{-1,1,1,-1},{0,1,0,-1}},dy[2][4]={{1,1,-1,-1},{1,0,-1,0}};
int n,t[N],vis[M][M];
struct Point{
	int x,y,d;
	Point(){}
	Point(int x,int y,int d):x(x),y(y),d(d){}
};
bool operator<(const Point&a,const Point&b){
	if(a.x==b.x){
		if(a.y==b.y){
			return a.d<b.d;
		}else return a.y<b.y;
	}else return a.x<b.x;
}
set<Point> inq;
Point q[M*M*4];
int ql,qr;
void bfs(){
	ql=qr=0;q[qr++]=Point(155,155,0);
	rep(i,1,n){
		int tmp=qr;
		inq.clear();
		while(ql!=tmp){
			int x=q[ql].x,y=q[ql].y;
			int p=q[ql].d;
			if(++ql==M*M*4)ql=0;
			rep(l,1,t[i])vis[x+l*dx[i&1][p]][y+l*dy[i&1][p]]=1;
			Point t1=Point(x+t[i]*dx[i&1][p],y+t[i]*dy[i&1][p],p);
			Point t2=Point(x+t[i]*dx[i&1][p],y+t[i]*dy[i&1][p],(p+((i&1)?1:-1)+4)%4);
			if(!inq.count(t1))inq.insert(t1),q[qr++]=t1;
			if(qr==M*M*4)qr=0;
			if(!inq.count(t2))inq.insert(t2),q[qr++]=t2;
			if(qr==M*M*4)qr=0;
		}
	}
}
int main(){
	scanf("%d",&n);rep(i,1,n)scanf("%d",&t[i]);
	bfs();
	int ans=0;
	rep(i,0,M-1)rep(j,0,M-1)ans+=vis[i][j];
	printf("%d",ans);
	return 0;
}
