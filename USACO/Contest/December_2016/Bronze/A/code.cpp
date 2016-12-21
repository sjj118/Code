#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	freopen("square.in","r",stdin);freopen("square.out","w",stdout);
	int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	int x3,y3,x4,y4;scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
	int minx=min(min(x1,x2),min(x3,x4)),maxx=max(max(x1,x2),max(x3,x4));
	int miny=min(min(y1,y2),min(y3,y4)),maxy=max(max(y1,y2),max(y3,y4));
	int d=max(maxx-minx,maxy-miny);
	printf("%d",d*d);
	return 0;
}
