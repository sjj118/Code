#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a));
#define maxn 5050

using namespace std;

int n,m,x1,y1,x2,y2,ans[maxn];
struct Point{
	int x,y;
	Point(int X=0,int Y=0){x=X;y=Y;}
}U[maxn],D[maxn];
Point operator-(const Point a,const Point b){return Point(b.x-a.x,b.y-a.y);}
int cross(Point a,Point b){return a.x*b.y-a.y*b.x;}

int main(){
	bool first=1;
	while(scanf("%d",&n)>0&&n){
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		cls(ans);
		for(int i=1;i<=n;++i){
			int u,d;scanf("%d%d",&u,&d);
			U[i]=Point(u-x1,y1-y2);D[i]=Point(d-x1,0);
		}
		U[0]=Point(0,y1-y2);
		for(int i=1;i<=m;++i){
			int x,y;scanf("%d%d",&x,&y);
			Point toy(x-x1,y-y2);
			int l=0,r=n;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(cross(toy-D[mid],U[mid]-D[mid])>=0)l=mid;else r=mid-1;
			}
			++ans[l];
		}
		if(first)first=0;else printf("\n");
		for(int i=0;i<=n;++i)printf("%d: %d\n",i,ans[i]);
	}
	return 0;
}
