#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=30+10,inf=1e9;
int k,n,w[N][N],lx[N],ly[N],vy[N],match[N],slk[N],prev[N];
struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y){x=_x;y=_y;}
};
Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
int operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
int operator^(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
int dis(const Point&a){return a.x*a.x+a.y*a.y;}
struct Person{
	Point p;
	char name[N];
}people[N<<1];
bool ok(int x,int y){
	if(dis(people[x].p-people[y].p)>k*k)return 0;
	rep(i,1,n<<1)if(i!=x&&i!=y){
		if(((people[x].p-people[i].p)^(people[y].p-people[i].p))==0&&(((people[x].p-people[i].p)*(people[y].p-people[i].p))<=0))return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&k,&n);
	rep(i,1,n)rep(j,1,n)w[i][j]=-inf;
	rep(i,1,n<<1){
		scanf("%d%d%s",&people[i].p.x,&people[i].p.y,people[i].name);
		int t=-1;
		while(people[i].name[++t])people[i].name[t]=toupper(people[i].name[t]);
	}
	char s1[N],s2[N];
	scanf("\n%s",s1);
	rep(i,1,n)rep(j,1,n)if(ok(i,n+j))w[i][j]=1;
	while(strcmp(s1,"End")){
		int p;
		scanf("%s%d",s2,&p);
		int x1,x2,t=-1;
		while(s1[++t])s1[t]=toupper(s1[t]);
		t=-1;while(s2[++t])s2[t]=toupper(s2[t]);
		rep(i,1,n<<1)if(!strcmp(s1,people[i].name))x1=i;
		rep(i,1,n<<1)if(!strcmp(s2,people[i].name))x2=i;
		if(x1>x2)swap(x1,x2);
		if(x1<=n&&x2>n&&ok(x1,x2)){
			w[x1][x2-n]=p;
		}
		scanf("\n%s",s1);
	}
	rep(i,1,n){
		cls(vy);rep(y,1,n)slk[y]=inf;
		int py=0;
		match[py]=i;
		while(match[py]){
			vy[py]=1;
			int x=match[py],yy,d=inf;
			rep(y,1,n)if(!vy[y]){
				if(lx[x]+ly[y]-w[x][y]<slk[y])slk[y]=lx[x]+ly[y]-w[x][y],prev[y]=py;
				if(slk[y]<d)d=slk[y],yy=y;
			}
			rep(y,0,n)if(vy[y])ly[y]+=d,lx[match[y]]-=d;else slk[y]-=d;
			py=yy;
		}
		while(py){
			match[py]=match[prev[py]];
			py=prev[py];
		}
	}
	int ans=0;
	rep(i,1,n)ans+=lx[i]+ly[i];
	printf("%d",ans);
	return 0;
}
