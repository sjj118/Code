#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
int x,y,fx[10][3],dis[105][105];
struct Point
{
	int x,y;
};
void bfs()
{
	memset(dis,-1,sizeof(dis));
	dis[x][y]=0;
	fx[1][1]=fx[2][1]=1,fx[3][1]=fx[4][1]=-1,fx[5][1]=fx[6][1]=2,fx[7][1]=fx[8][1]=-2;
	fx[1][2]=fx[3][2]=2,fx[2][2]=fx[4][2]=-2,fx[5][2]=fx[7][2]=1,fx[6][2]=fx[8][2]=-1;
	queue<Point> q;
	Point p;
	p.x=x,p.y=y;
	q.push(p);
	while (!q.empty())
	{
		Point x;
		x=q.front();
		q.pop();
		for (int i=1;i<=8;i++)
		{
			int nowx=x.x+fx[i][1],nowy=x.y+fx[i][2];
			if (nowx<0||nowy<0||nowx>100||nowy>100) continue;
			if (dis[nowx][nowy]!=-1) continue;
			dis[nowx][nowy]=dis[x.x][x.y]+1;
			Point X;
			X.x=nowx,X.y=nowy;
			q.push(X);
			if (nowx==50&&nowy==50) return;
		}
	}
}
int main()
{ 
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
	int xp,yp,xs,ys;
	scanf("%d%d%d%d",&xp,&yp,&xs,&ys);
	x=abs(xs-xp),y=abs(ys-yp);
	int ans=0;
	while (x+y>=50)
	{
		if (x<y) swap(x,y);
		if (x-4>=y*2) x-=4;
		else x-=4,y-=2;
		ans+=2;
	}
	x+=50,y+=50;
	bfs();
	printf("%d\n",ans+dis[50][50]);
	return 0;
}

