#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxc=1e6+10;
typedef long long LL;
using namespace std;
inline int read(){int tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,m,c,tc;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x;y=_y;}
}p[maxc];
Point operator+(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}
const Point d[8]={Point(1,0),Point(-1,0),Point(0,1),Point(0,-1),Point(1,1),Point(1,-1),Point(-1,1),Point(-1,-1)};
const int ha=23333333;
struct Hashmap{
	int tot,head[ha],next[maxc<<3],x[maxc<<3],y[maxc<<3];
	void ins(int _x,int _y){
		int k=((LL)_x*13131+_y)%ha;
		x[++tot]=_x;y[tot]=_y;
		next[tot]=head[k];head[k]=tot;
	}
	int find(int _x,int _y){
		int k=((LL)_x*13131+_y)%ha;
		for(int p=head[k];p;p=next[p])if(x[p]==_x&&y[p]==_y)return p;
		return 0;
	}
	void pop(int _x,int _y){
		int k=((LL)_x*13131+_y)%ha;
		head[k]=next[head[k]];
	}
	void clear(){tot=0;cls(head);}
}vfk,ququ;
bool vis[maxc<<3];
bool avail(int x,int y){return x>=0&&x<=n+1&&y>=0&&y<=m+1;}
bool flag;
int dfs(int k,int x,int y){
	if(flag&&x==p[c].x&&y==p[c].y)return 0;
	vis[k]=1;
	rep(i,0,3)if(avail(x+d[i].x,y+d[i].y)){
		int p=vfk.find(x+d[i].x,y+d[i].y);
		if(p&&!vis[p])dfs(p,x+d[i].x,y+d[i].y);
	}
	return 1;
}
bool check(){
	int tmp=0;cls(vis);
	rep(i,1,c)rep(j,0,7)if(avail(p[i].x+d[j].x,p[i].y+d[j].y)){
		int k=vfk.find(p[i].x+d[j].x,p[i].y+d[j].y);
		if(!k)continue;
		if(!vis[k])
		tmp+=dfs(k,p[i].x+d[j].x,p[i].y+d[j].y);
	}
	return tmp>1;
}
int solve(){
	rep(i,1,c)ququ.ins(p[i].x,p[i].y);
	rep(i,1,c){
		rep(j,0,7)if((avail(p[i].x+d[j].x,p[i].y+d[j].y))&&ququ.find(p[i].x+d[j].x,p[i].y+d[j].y)==0&&vfk.find(p[i].x+d[j].x,p[i].y+d[j].y)==0)vfk.ins(p[i].x+d[j].x,p[i].y+d[j].y);
	}
	flag=0;
	if(check())return 0;
	flag=1;
	int stack[8],top=0; 
	rep(i,1,c){
		rep(j,0,7)if((avail(p[i].x+d[j].x,p[i].y+d[j].y))&&ququ.find(p[i].x+d[j].x,p[i].y+d[j].y)==0){
			p[c+1]=p[i]+d[j];++c;
			vfk.ins(p[i].x+d[j].x,p[i].y+d[j].y);
			rep(k,0,7)if((avail(p[c].x+d[k].x,p[c].y+d[k].y))&&ququ.find(p[c].x+d[k].x,p[c].y+d[k].y)==0&&vfk.find(p[c].x+d[k].x,p[c].y+d[k].y)==0)stack[++top]=k,vfk.ins(p[c].x+d[k].x,p[c].y+d[k].y);
			if(check())return 1;
			while(top)vfk.pop(p[c].x+d[stack[top]].x,p[c].y+d[stack[top]].y),--top;
			--c;vfk.pop(p[i].x+d[j].x,p[i].y+d[j].y);
		}
	}
	if(n*m-tc<4)return -1;else return 2;
}

int main(){
	freopen("grid.in","r",stdin);//freopen("grid.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&c);tc=c;
		rep(i,1,c)p[i].x=read(),p[i].y=read();
		rep(i,0,m+1)p[++c]=Point(0,i),p[++c]=Point(n+1,i);
		rep(i,1,n)p[++c]=Point(i,0),p[++c]=Point(i,m+1);
		printf("%d\n",solve());
		ququ.clear();vfk.clear();
	}
	return 0;
}
