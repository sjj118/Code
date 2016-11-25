#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=8+2,S=20+5,T=200000+10;
int n,m,s,d,r,t,num_ant,level_ant;
double ant_health=4.4;
bool full[N][N];
int info[N][N];
struct Point{
	int x,y;
	Point(){x=y=0;}
	Point(int _x,int _y){x=_x;y=_y;}
};
const Point dir[4]={Point(1,0),Point(0,1),Point(-1,0),Point(0,-1)};
bool operator==(const Point&a,const Point&b){return a.x==b.x&&a.y==b.y;}
Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
int dis(const Point&a){return a.x*a.x+a.y*a.y;}
struct Ant{
	Point pos,lastpos;
	int health,age,maxhealth;
	bool hasCake;
	Ant(int id=0){
		if(id%6==1)++level_ant,ant_health*=1.1;;
		maxhealth=health=floor(ant_health);
		age=hasCake=0;
		pos=lastpos=Point(0,0);
	}
	int vaildDir(int x){
		Point to=pos+dir[x];
		if(to==lastpos)return -1;
		if(full[to.x][to.y])return -1;
		if(to.x>n||to.y>m||to.x<1||to.y<1)return -1;
		return info[to.x][to.y];
	}
	int getDir123(){
		int ret=-1,fo=-1;
		rep(i,0,3){
			int t=vaildDir(i);
			if(t==-1)continue;
			if(t>fo)ret=i,fo=t;
		}
		return ret;
	}
	int getDir4(int x){
		if(x==0)x=4;--x;
		while(!vaildDir(x)){
			if(x==0)x=4;--x;
		}
		return x;
	}
	int getDir(){
		int ret=getDir123();
		if(ret==-1)return -1;
		if(age%5==0)ret=getDir4(ret);
		return ret;
	}
	void Walk(){
		++age;
		if(hasCake)info[pos.x][pos.y]+=5;else info[pos.x][pos.y]+=2;
		int x=getDir();
		if(x==-1)return;
		lastpos=pos;pos=pos+dir[x];
		full[lastpos.x][lastpos.y]=0;full[pos.x][pos.y]=1;
		if(pos.x==n&&pos.y==m)hasCake=1,health=max(maxhealth,health+maxhealth/2);
	}
};
list<Ant> ants;
struct Canon{
	Point pos;
	Ant*getTarget(){
		Ant*ret=0;
		int d=10000;
		for(list<Ant>::iterator i=ants.begin();i!=ants.end();++i){
			if(dis(i->pos-pos)<d)d=dis(i->pos-pos),ret=&(*i);
			if(i->hasCake&&dis(i->pos-pos)<=r*r)return &(*i);
		}
		if(dis(ret->pos-pos)>r*r)return 0;
		return ret;
	}
	void Attack(){
		Ant*tar=getTarget();
		if(tar==0)return;
		for(list<Ant>::iterator i=ants.begin();i!=ants.end();++i){
			if(dis)
		}
	}
}canon[S];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&s,&d,&r);
	rep(i,1,s)scanf("%d%d",&canon[i].pos.x,&canon[i].pos.y),full[canon[i].pos.x][canon[i].pos.y]=1;
	scanf("%d",&t);
	rep(i,1,t){
		if(ants.size()<6&&!full[0][0])++num_ant,ants.push_back(Ant(num_ant));
		for(list<Ant>::iterator j=ants.begin();j!=ants.end();++j)j->Walk();
		rep(i,1,s)canon[i].Attack();
		for(list<Ant>::iterator j=ants.begin();j!=ants.end();++j)if(i->health<0){
			j.del();
		}
	}
	return 0;
}
